#pragma once

#include <string_view>
#include <variant>
#include "../utils/utils_lib/utils_compiler.hpp"
#include "../utils/utils_lib/utils_exceptions.hpp"
#include "../utils/utils_lib/utils_traits.hpp"
#include "../utils/utils_lib/utils_math.hpp"
#include "../utils/utils_lib/utils_memory.hpp"
#include "../utils/utils_lib/utils_logger.hpp"
#include "fwd.hpp"

namespace cmp {
    /**
     *  \brief  Types of Binary operands.
     *          `+`, `-`, `*`, `/`, `%`, `&`, `|`, `^`
     */
    enum class BinaryOperand {
        Plus, Minus, Times, Div, Mod, BinAnd, BinOr, BinXor
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
     *          `+`, `-`, `!`, `~`
     */
    enum class UnaryOperand {
         Plus, Minus, Not, BinNot
    };

    namespace detail {
        static constexpr std::string_view _BinaryOperandStrings[] {
            "PLUS", "MINUS", "TIMES", "DIV", "BINAND", "BINOR", "BINXOR"
        };

        static constexpr std::string_view to_string(const cmp::BinaryOperand o) {
            return cmp::detail::_BinaryOperandStrings[utils::traits::to_underlying(o)];
        }

        static constexpr std::string_view _UnaryOperandStrings[] {
            "PLUS", "MIN", "NOT", "BINNOT"
        };

        static constexpr std::string_view to_string(const cmp::UnaryOperand o) {
            return cmp::detail::_UnaryOperandStrings[utils::traits::to_underlying(o)];
        }

        static constexpr std::string_view _BinCompareStrings[] {
            "==", "!=", "<", "<=", ">", ">=", "&&", "||"
        };

        static constexpr std::string_view to_string(const cmp::BinCompare o) {
            return cmp::detail::_BinCompareStrings[utils::traits::to_underlying(o)];
        }
    }

    template<
        typename TChar,
        typename TCharTraits,
        typename T,
        typename = typename std::enable_if_t<std::is_same_v<T, cmp::BinaryOperand>
                                          || std::is_same_v<T, cmp::UnaryOperand>
                                          || std::is_same_v<T, cmp::BinCompare>>
    > auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const T& op)
    {
        stream << cmp::detail::to_string(op);
        return stream;
    }


    class IdExpression : public Expression {
        public:
            std::string id;

            /**
             *  \brief  Construct a new Id Expression object
             *          `Exp -> id`
             *
             *  \param  id
             */
            IdExpression(std::string_view id)
                : id{id.data(), id.size()}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("IdExpression(", this->id, ")\n");
                #endif
            }

            ~IdExpression() {}

            int maxargs() const {
                return 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                if (const auto val = table.get_var_table().get(this->id)) {
                    return { val.value() };
                }
                throw utils::exceptions::KeyDoesNotExistException("Symboltable", this->id);
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
            ValueExpression(int32_t val) : value{val} {
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ValueExpression(", val, ")\n");
                #endif
            }

            ValueExpression(double val) : value{val} {
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ValueExpression(", val, ")\n");
                #endif
            }

            ValueExpression(bool val) : value{val} {
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ValueExpression(", std::boolalpha, val, ")\n");
                #endif
            }

            ~ValueExpression() {}

            int maxargs() const {
                return 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                UNUSED(table);
                return this->value;
            }
    };

    class AssignExpression : public Expression {
        public:
            IdExpression *id;
            Expression   *exp;

            /**
             *  \brief  Construct a new Assign Expression object
             *          `Stm -> id := Exp`
             *
             *  \param  id
             *  \param  exp
             */
            AssignExpression(IdExpression *id, Expression *exp)
                : id{id}
                , exp{exp}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("AssignExpression(IdExpression(", this->id->id, "), ", this->exp, ")\n");
                #endif
            }

            ~AssignExpression() {
                utils::memory::delete_var(this->id);
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp->maxargs();
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto ret = this->exp->interpret(table);
                table.get_var_table().insert(this->id->id, ret);
                return ret;
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("BinOperandExpression(", this->left, ", ", cmp::detail::to_string(op), ", ", this->right, ")\n");
                #endif
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

                // Throw if binop on bool
                if (std::holds_alternative<bool>(ret_left)
                 || std::holds_alternative<bool>(ret_left)) {
                     const auto frmt = utils::string::format("Tried to perform BinOperandExpression(%s) on booleans!",
                                                             cmp::detail::to_string(this->op).data());
                     throw utils::exceptions::ConversionException(frmt);
                }

                InterpretResult retval;

                std::visit([&](auto&& argl) {
                    std::visit([&](auto&& argr) {
                        using Tl = std::decay_t<decltype(argl)>;
                        using Tr = std::decay_t<decltype(argr)>;

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
                                // Throw if div by 0
                                if (utils::math::epsilon_equals(argr, Tr{0})) {
                                    throw utils::exceptions::DivideByZeroException("BinOperandExpression");
                                }
                                retval = argl / argr;
                                break;
                            default:
                                if constexpr (std::is_integral_v<Tl>
                                           && std::is_integral_v<Tr>)
                                {
                                    switch (this->op) {
                                        case BinaryOperand::Mod:
                                            retval = argl % argr;
                                            break;
                                        case BinaryOperand::BinAnd:
                                            retval = argl & argr;
                                            break;
                                        case BinaryOperand::BinOr:
                                            retval = argl | argr;
                                            break;
                                        case BinaryOperand::BinXor:
                                            retval = argl ^ argr;
                                            break;
                                        default:
                                            break;
                                    }
                                } else {
                                    // Throw if integral op on real
                                    const auto frmt = utils::string::format("Tried to perform BinOperandExpression(%s) on non-integral type!",
                                                                            cmp::detail::to_string(this->op).data());
                                    throw utils::exceptions::ConversionException(frmt);
                                }
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("UnaryOperandExpression(", cmp::detail::to_string(op), ", ", this->expr, ")\n");
                #endif
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
                            retval = !bool(arg);
                            break;
                        case UnaryOperand::BinNot:
                            if constexpr (std::is_integral_v<std::decay_t<decltype(arg)>>) {
                                retval = ~int32_t(arg);
                            } else {
                                // WARNING Error type not integral
                                retval = 0;
                            }
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("BinCompareExpression(", this->left, ", ", cmp::detail::to_string(comp), ", ", this->right, ")\n");
                #endif
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

                HEDLEY_DIAGNOSTIC_PUSH
                #pragma GCC diagnostic ignored "-Wfloat-equal"

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
                                retval = bool(argl) && bool(argr);
                                break;
                            case BinCompare::OR:
                                retval = bool(argl) || bool(argr);
                                break;
                        }
                    }, ret_right);
                }, ret_left);

                HEDLEY_DIAGNOSTIC_POP
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ExpseqExpression(", this->stm, ", ", this->exp, ")\n");
                #endif
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("PairExpressionList(", this->head, ", ", this->tail, ")\n");
                #endif
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
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("LastExpressionList(", this->last, ")\n");
                #endif
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

    class FunctionExpression : public Expression {
        public:
            IdExpression   *name;
            ExpressionList *exp;

            FunctionExpression(IdExpression *name, ExpressionList *exp = nullptr)
                : name{name}
                , exp{exp}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    if (this->exp)
                        utils::Logger::Stream("FunctionExpression(", this->name->id, ", ", this->exp, ")\n");
                    else
                        utils::Logger::Stream("FunctionExpression(", this->name->id, ")\n");
                #endif
            }

            ~FunctionExpression() {
                utils::memory::delete_var(this->name);
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp ? this->exp->maxargs() : 0;
            }

            InterpretResult interpret(SymbolTable& table) const {
                const auto fn_name = this->name->id;
                InterpretResult ret{};

                const int arg_len = this->exp ? this->exp->maxargs() : 0;

                if (const auto argc = table.get_fun_table().get(this->name->id)) {
                    // Remove vars introduced inside function
                    // i.e. override them with old table contents?
                    // interpret existing func and return result

                    std::visit([&](auto&& arg) {
                        if (arg_len != arg) {
                            const auto name = utils::string::format("FunctionExpression \"%s\"", this->name->id.c_str());
                            const auto msg  = utils::string::format("Amount of arguments mismatch! Expected: %d vs given: %d", arg, arg_len);
                            throw utils::exceptions::Exception(name, msg);
                        } else {
                            // Interpret function
                            // TODO
                            if (this->exp) {
                                // Has args
                                utils::Logger::Stream()
                                    << "Call " << fn_name << "() with ";
                                ret = this->exp->interpret(table);
                            } else {
                                utils::Logger::Stream()
                                    << "Call " << fn_name << "()\n";
                            }
                        }
                    }, argc.value());
                } else {
                    throw utils::exceptions::KeyDoesNotExistException("FunctionTable", fn_name);
                }

                return ret;
            }
    };
}
