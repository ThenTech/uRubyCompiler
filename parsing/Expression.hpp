#pragma once

#include <string_view>
#include <variant>
#include "../utils/utils_lib/utils_exceptions.hpp"
#include "../utils/utils_lib/utils_traits.hpp"
#include "../utils/utils_lib/utils_math.hpp"
#include "../utils/utils_lib/utils_memory.hpp"
#include "../utils/utils_lib/utils_logger.hpp"
#include "fwd.hpp"

namespace cmp {
    /**
     *  \brief  Types of Binary operands.
     *          `+`, `-`, `*`, `/`
     */
    enum class BinaryOperand {
        Plus, Minus, Times, Div
    };

    /**
     *  \brief  Types of Comparator operands.
     *          `==`, `!=`, `<`, `<=`, `>`, `>=`,
     *          `&&`, `||`
     */
    enum class BinCompare {
        EQ, NEQ, LT, LE, GT, GE,
        AND, OR
    };

    /**
     *  \brief  Types of Unary operands.
     *          `-`, `!`
     */
    enum class UnaryOperand {
         Plus, Minus, Not
    };

    class IdExpression : public Expression {
        public:
            std::string_view id;

            /**
             *  \brief  Construct a new Id Expression object
             *          `Exp -> id`
             *
             *  \param  id
             */
            IdExpression(std::string_view id)
                : id{id}
            {
                // Empty
            }

            ~IdExpression() {}

            int maxargs() const {
                return 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                if (const auto val = table.get(this->id)) {
                    return { val.value() };
                }
                throw utils::exceptions::KeyDoesNotExistException("Symboltable", "this->id");
            }
    };

    class ValueExpression : public Expression {
        public:
            InterpretResult value;

            /**
             *  \brief  Construct a new Numeric Expression object
             *          `Exp -> num`
             *
             *  \param  num
             */
            ValueExpression(int32_t val) : value{val} { }
            ValueExpression(double  val) : value{val} { }
            ValueExpression(bool    val) : value{val} { }

            ~ValueExpression() {}

            int maxargs() const {
                return 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                return this->value;
            }
    };

    class BinOperandExpression : public Expression {
        public:
            Expression *left, *right;
            BinaryOperand op;

            /**
             *  \brief  Construct a new Binary Operand Expression object
             *          `Exp -> Exp Binop Exp`
             *
             *  \param  left
             *  \param  op
             *  \param  right
             */
            BinOperandExpression(Expression *left, BinaryOperand op, Expression *right)
                : left{left}
                , right{right}
                , op{op}
            {
                // Empty
            }

            ~BinOperandExpression() {
                utils::memory::delete_var(this->left);
                utils::memory::delete_var(this->right);
            }

            int maxargs() const {
                // TODO are nested expressions allowed in OperandExpression?
                return utils::math::max(this->left->maxargs(), this->right->maxargs());
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret_left  = this->left->interpret(table);
                const auto ret_right = this->right->interpret(table);

                InterpretResult retval;

                std::visit([&](auto&& argl) {
                    std::visit([&](auto&& argr) {
                        switch (this->op) {
                            case BinaryOperand::Plus:
                                retval = argl + argr;
                                break;
                            case BinaryOperand::Minus:
                                retval = argl - argr;
                                break;
                            case BinaryOperand::Times:
                                retval = argl * argr;
                                break;
                            case BinaryOperand::Div:
                                retval = argl / argr;
                                break;
                        }
                    }, ret_right);
                }, ret_left);

                return { retval };
            }
    };

    class UnaryOperandExpression : public Expression {
        public:
            UnaryOperand op;
            Expression *expr;

            /**
             *  \brief  Construct a new Unary Operand Expression object
             *          `Exp -> Unop Exp`
             *
             *  \param  op
             *  \param  expr
             */
            UnaryOperandExpression(UnaryOperand op, Expression *expr)
                : op{op}
                , expr{expr}
            {
                // Empty
            }

            ~UnaryOperandExpression() {
                utils::memory::delete_var(this->expr);
            }

            int maxargs() const {
                // TODO are nested expressions allowed in OperandExpression?
                return this->expr->maxargs();
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret = this->expr->interpret(table);

                InterpretResult retval;

                std::visit([&](auto&& arg) {
                    switch (this->op) {
                        case UnaryOperand::Plus:
                            retval = arg;
                            break;
                        case UnaryOperand::Minus:
                            retval = -arg;
                            break;
                        case UnaryOperand::Not:
                            retval = !arg;
                            break;
                    }
                }, ret);

                return { retval };
            }
    };

    class BinCompareExpression : public Expression {
        public:
            Expression *left, *right;
            BinCompare comp;

            /**
             *  \brief  Construct a new Binary Operand Expression object
             *          `Exp -> Exp Binop Exp`
             *
             *  \param  left
             *  \param  op
             *  \param  right
             */
            BinCompareExpression(Expression *left, BinCompare comp, Expression *right)
                : left{left}
                , right{right}
                , comp{comp}
            {
                // Empty
            }

            ~BinCompareExpression() {
                utils::memory::delete_var(this->left);
                utils::memory::delete_var(this->right);
            }

            int maxargs() const {
                // TODO are nested expressions allowed in OperandExpression?
                return utils::math::max(this->left->maxargs(), this->right->maxargs());
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret_left  = this->left->interpret(table);
                const auto ret_right = this->right->interpret(table);

                bool retval = false;

                std::visit([&](auto&& argl) {
                    std::visit([&](auto&& argr) {
                        switch (this->comp) {
                            case BinCompare::EQ:
                                retval = argl == argr;
                                break;
                            case BinCompare::NEQ:
                                retval = argl != argr;
                                break;
                            case BinCompare::LT:
                                retval = argl < argr;
                                break;
                            case BinCompare::LE:
                                retval = argl <= argr;
                                break;
                            case BinCompare::GT:
                                retval = argl > argr;
                                break;
                            case BinCompare::GE:
                                retval = argl >= argr;
                                break;
                            case BinCompare::AND:
                                retval = argl && argr;
                                break;
                            case BinCompare::OR:
                                retval = argl || argr;
                                break;
                        }
                    }, ret_right);
                }, ret_left);

                return { retval };
            }
    };

    class ExpseqExpression : public Expression {
        public:
            Statement  *stm;
            Expression *exp;

            /**
             *  \brief  Construct a new Expseq Expression object
             *          `Exp -> ( Stm , Exp )`
             *
             *  \param  stm
             *  \param  exp
             */
            ExpseqExpression(Statement *stm, Expression *exp)
                : stm{stm}
                , exp{exp}
            {
                // Empty
            }

            ~ExpseqExpression() {
                utils::memory::delete_var(this->stm);
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return utils::math::max(this->stm->maxargs(), this->exp->maxargs());
            }

            InterpretResult interpret(SymbolTable& table) const {
                this->stm->interpret(table);
                return this->exp->interpret(table);
            }
    };

    class PairExpressionList : public ExpressionList {
        public:
            Expression     *head;
            ExpressionList *tail;

            /**
             *  \brief  Construct a new Pair Expression List object
             *          `ExpList -> Exp , ExpList`
             *
             *  \param  head
             *  \param  tail
             */
            PairExpressionList(Expression *head, ExpressionList *tail)
                : head{head}
                , tail{tail}
            {
                // Empty
            }

            ~PairExpressionList() {
                utils::memory::delete_var(this->head);
                utils::memory::delete_var(this->tail);
            }

            int maxargs() const {
                return utils::math::max(this->head->maxargs(), 1 + this->tail->maxargs());
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret = this->head->interpret(table);
                utils::Logger::Stream(ret, " ");
                return this->tail->interpret(table);
            }
    };

    class LastExpressionList : public ExpressionList {
        public:
            Expression *last;

            /**
             *  \brief  Construct a new Last Expression List object
             *          `ExpList -> Exp`
             *
             *  \param  last
             */
            LastExpressionList(Expression *last)
                : last{last}
            {
                // Empty
            }

            ~LastExpressionList() {
                utils::memory::delete_var(this->last);
            }

            int maxargs() const {
                return 1;
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret = this->last->interpret(table);
                utils::Logger::Stream(ret, "\n");
                return ret;
            }
    };

    class FunctionExpression : Expression {
        public:
            IdExpression   *name;
            ExpressionList *exp;

            FunctionExpression(IdExpression *name, ExpressionList *exp)
                : name{name}
                , exp{exp}
            {
                // Empty
            }

            ~FunctionExpression() {
                utils::memory::delete_var(this->name);
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp->maxargs();
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto fn_name = this->name->id;
                const auto ret = this->exp->interpret(table);

                utils::Logger::Stream()
                    << this->name->id
                    << "(" << ret << ")\n";

                return ret;
            }
    }

    namespace detail {
        static constexpr std::string_view _BinaryOperandStrings[] {
            "PLUS", "MINUS", "TIMES", "DIV"
        };

        static constexpr std::string_view to_string(const cmp::BinaryOperand o) {
            return cmp::detail::_BinaryOperandStrings[utils::traits::to_underlying(o)];
        }

        static constexpr std::string_view _UnaryOperandStrings[] {
            "MIN"
        };

        static constexpr std::string_view to_string(const cmp::UnaryOperand o) {
            return cmp::detail::_UnaryOperandStrings[utils::traits::to_underlying(o)];
        }
    }

    template<typename TChar, typename TCharTraits>
    auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const BinaryOperand& op)
    {
        stream << cmp::detail::to_string(op);
        return stream;
    }

    template<typename TChar, typename TCharTraits>
    auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const UnaryOperand& op)
    {
        stream << cmp::detail::to_string(op);
        return stream;
    }
}
