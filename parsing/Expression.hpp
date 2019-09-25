#pragma once

#include <string_view>
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
     *  \brief  Types of Unary operands.
     *          `-`
     */
    enum class UnaryOperand {
         Minus
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
                    return { val.value(), table };
                }
                throw utils::exceptions::KeyDoesNotExistException("Symboltable", "this->id");
            }
    };

    class NumericExpression : public Expression {
        public:
            int num;

            /**
             *  \brief  Construct a new Numeric Expression object
             *          `Exp -> num`
             *
             *  \param  num
             */
            NumericExpression(int num)
                : num{num}
            {
                // Empty
            }

            ~NumericExpression() {}

            int maxargs() const {
                return 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                return { this->num, table };
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

                int retval = ret_left.first;

                switch (this->op) {
                    case BinaryOperand::Plus:
                        retval += ret_right.first;
                        break;
                    case BinaryOperand::Minus:
                        retval -= ret_right.first;
                        break;
                    case BinaryOperand::Times:
                        retval *= ret_right.first;
                        break;
                    case BinaryOperand::Div:
                        retval /= ret_right.first;
                        break;
                }

                return { retval, table };
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
                utils::Logger::Stream(ret.first, " ");
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
                utils::Logger::Stream(ret.first, "\n");
                return ret;
            }
    };

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
