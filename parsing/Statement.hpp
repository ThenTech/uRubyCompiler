#pragma once

#include <string_view>
#include "../utils/utils_lib/utils_compiler.hpp"
#include "../utils/utils_lib/utils_logger.hpp"
#include "../utils/utils_lib/utils_math.hpp"
#include "../utils/utils_lib/utils_memory.hpp"
#include "../utils/utils_lib/utils_exceptions.hpp"
#include "../utils/utils_lib/utils_math.hpp"
#include "fwd.hpp"
#include "Expression.hpp"

namespace cmp {
    namespace detail {
        static constexpr std::string_view CASE_RESULT_NAME = "TEMP_CASE_VALUE";
    }

    class ExpressionStatement : public Statement {
        public:
            Expression *exp;

            /**
             *  \brief  Construct a new Expression Statement object
             *          `Stm -> Exp`
             *
             *  \param  id
             *  \param  exp
             */
            ExpressionStatement(Expression *exp) : exp{exp}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ExpressionStatement(", this->exp, ")\n");
                #endif
            }

            ~ExpressionStatement() {
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto ret = this->exp->interpret(table);
                return table;
            }
    };

    class AssignStatement : public Statement {
        public:
            IdExpression *id;
            Expression   *exp;

            /**
             *  \brief  Construct a new Assign Statement object
             *          `Stm -> id := Exp`
             *
             *  \param  id
             *  \param  exp
             */
            AssignStatement(IdExpression *id, Expression *exp)
                : id{id}
                , exp{exp}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ExpressionStatement(IdExpression(", this->id->id, "), ", this->exp, ")\n");
                #endif
            }

            ~AssignStatement() {
                utils::memory::delete_var(this->id);
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto ret = this->exp->interpret(table);
                table.get_var_table().insert(this->id->id, ret);
                return table;
            }
    };

    class PrintStatement : public Statement {
        public:
            ExpressionList *exps;

            /**
             *  \brief  Construct a new Print Statement object
             *          `Stm -> print( ExpList )`
             *
             *  \param  exps
             */
            PrintStatement(ExpressionList *exps)
                : exps{exps}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("PrintStatement(", this->exps, ")\n");
                #endif
            }

            ~PrintStatement() {
                utils::memory::delete_var(this->exps);
            }

            int maxargs() const {
                return this->exps->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                this->exps->interpret(table);
                return table;
            }
    };

    class CompoundStatement : public Statement {
        public:
            Statement *stm1, *stm2;

            /**
             *  \brief  Construct a new Compound Statement object
             *          `Stm ; Stm`
             *
             *  \param  stm1
             *  \param  stm2
             */
            CompoundStatement(Statement *stm1, Statement *stm2)
                : stm1{stm1}
                , stm2{stm2}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("CompoundStatement(", this->stm1, ", ", this->stm2, ")\n");
                #endif
            }

            ~CompoundStatement() {
                utils::memory::delete_var(this->stm1);
                utils::memory::delete_var(this->stm2);
            }

            int maxargs() const {
                return utils::math::max(this->stm1->maxargs(), this->stm2->maxargs());
            }

            SymbolTable& interpret(SymbolTable& table) const {
                this->stm1->interpret(table);
                this->stm2->interpret(table);
                return table;
            }
    };

    class IfStatement : public Statement {
        public:
            Expression *condition;
            Statement *stm_true, *stm_false;

            /**
             *  \brief  Construct a new If Statement object
             *          `if condition then stm_true else stm_false`
             *
             *  \param  condition
             *  \param  stm_true
             *  \param  stm_false
             */
            IfStatement(Expression *condition, Statement *stm_true, Statement *stm_false = nullptr)
                : condition{condition}
                , stm_true{stm_true}
                , stm_false{stm_false}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("IfStatement(", this->condition, ", ", this->stm_true, ", ", this->stm_false, ")\n");
                #endif
            }

            ~IfStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->stm_true);
                utils::memory::delete_var(this->stm_false);
            }

            int maxargs() const {
                return utils::math::max(this->condition->maxargs(),
                                        this->stm_true->maxargs(),
                                        this->stm_false ? this->stm_false->maxargs() : 0);
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto result = this->condition->interpret(table);
                const bool cond = std::visit([](auto&& arg) { return bool(arg); }, result);

                if (cond) {
                    this->stm_true->interpret(table);
                } else if (this->stm_false) {
                    this->stm_false->interpret(table);
                }

                return table;
            }
    };

    class UnlessStatement : public Statement {
        public:
            Expression *condition;
            Statement *stm_false, *stm_true;

            /**
             *  \brief  Construct a new Unless Statement object
             *          `unless condition then stm_false else stm_true`
             *
             *  \param  condition
             *  \param  stm_true
             *  \param  stm_false
             */
            UnlessStatement(Expression *condition, Statement *stm_false, Statement *stm_true = nullptr)
                : condition{condition}
                , stm_false{stm_false}
                , stm_true{stm_true}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("UnlessStatement(", this->condition, ", ", this->stm_false, ", ", this->stm_true, ")\n");
                #endif
            }

            ~UnlessStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->stm_false);
                utils::memory::delete_var(this->stm_true);
            }

            int maxargs() const {
                return utils::math::max(this->condition->maxargs(),
                                        this->stm_false->maxargs(),
                                        this->stm_true ? this->stm_true->maxargs() : 0);
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto result = this->condition->interpret(table);
                const bool cond = std::visit([](auto&& arg) { return bool(arg); }, result);

                if (!cond) {
                    this->stm_false->interpret(table);
                } else if (this->stm_true) {
                    this->stm_true->interpret(table);
                }

                return table;
            }
    };

    class WhileStatement : public Statement {
        public:
            Expression *condition;
            Statement *stm;

            /**
             *  \brief  Construct a new While Statement object
             *          `while condition then stm`
             *
             *  \param  condition
             *  \param  stm
             */
            WhileStatement(Expression *condition, Statement *stm)
                : condition{condition}
                , stm{stm}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("WhileStatement(", this->condition, ", ", this->stm, ")\n");
                #endif
            }

            ~WhileStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->stm);
            }

            int maxargs() const {
                return utils::math::max(this->condition->maxargs(),
                                        this->stm->maxargs());
            }

            SymbolTable& interpret(SymbolTable& table) const {
                bool cond = true;

                do {
                    const auto result = this->condition->interpret(table);
                    cond = std::visit([](auto&& arg) { return bool(arg); }, result);

                    if (cond) {
                        this->stm->interpret(table);
                    }
                } while(cond);

                return table;
            }
    };

    class UntilStatement : public Statement {
        public:
            Expression *condition;
            Statement *stm;

            /**
             *  \brief  Construct a new Until Statement object
             *          `until condition then stm`
             *       == `while not condition then stm`
             *
             *  \param  condition
             *  \param  stm
             */
            UntilStatement(Expression *condition, Statement *stm)
                : condition{condition}
                , stm{stm}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("UntilStatement(", this->condition, ", ", this->stm, ")\n");
                #endif
            }

            ~UntilStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->stm);
            }

            int maxargs() const {
                return utils::math::max(this->condition->maxargs(),
                                        this->stm->maxargs());
            }

            SymbolTable& interpret(SymbolTable& table) const {
                bool cond = false;

                do {
                    const auto result = this->condition->interpret(table);
                    cond = std::visit([](auto&& arg) { return bool(arg); }, result);

                    if (!cond) {
                        this->stm->interpret(table);
                    }
                } while(!cond);

                return table;
            }
    };

    class WhenStatement : public Statement {
        public:
            Expression *condition;
            Statement  *when_true;
            Statement  *next;

            WhenStatement(Expression *condition, Statement *when_true, Statement *next = nullptr)
                : condition{condition}
                , when_true{when_true}
                , next{next}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("WhenStatement(", this->condition, ", ", this->when_true, ", ", this->next, ")\n");
                #endif
            }

            ~WhenStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->when_true);
                utils::memory::delete_var(this->next);
            }

            int maxargs() const {
                return utils::math::max(this->when_true->maxargs(),
                                        this->next ? this->next->maxargs() : 0);
            }

            SymbolTable& interpret(SymbolTable& table) const {
                if (this->condition != nullptr) {
                    const auto case_result = table.get_var_table().get(cmp::detail::CASE_RESULT_NAME);
                    const auto when_value  = this->condition->interpret(table);

                    if (case_result.has_value()) {
                        const auto case_value = case_result.value();

                        if (case_value.index() != when_value.index()) {
                            std::stringstream ss;
                            ss << "WhenStatement mismatching types for ";
                            std::visit([&](auto&& arg) {
                                ss << "case = <" << utils::print::type2name(arg)
                                   << ">(" << arg << ")";
                            }, case_value);

                            ss << " and ";
                            std::visit([&](auto&& arg) {
                                ss << "when = <" << utils::print::type2name(arg)
                                   << ">(" << arg << ")";
                            }, when_value);

                            throw utils::exceptions::ConversionException(ss.str());
                        }

                        std::visit([&](auto&& argl) {
                            std::visit([&](auto&& argr) {
                                HEDLEY_DIAGNOSTIC_PUSH
                                #pragma GCC diagnostic ignored "-Wfloat-equal"
                                bool cond;

                                // It is guaranteed here that the types match,
                                // so ignore warning, but check for epsilon anyway...
                                if constexpr (std::is_floating_point_v<std::decay_t<decltype(argl)>>
                                           && std::is_floating_point_v<std::decay_t<decltype(argr)>>)
                                {
                                    cond = utils::math::epsilon_equals(argl, argr);
                                } else {
                                    cond = (argl == argr);
                                }
                                HEDLEY_DIAGNOSTIC_POP

                                if (cond) {
                                    this->when_true->interpret(table);
                                } else if (this->next) {
                                    this->next->interpret(table);
                                }
                            }, when_value);
                        }, case_value);
                    } else {
                        throw utils::exceptions::KeyDoesNotExistException("Symboltable", std::string{cmp::detail::CASE_RESULT_NAME});
                    }
                } else {
                    // case else statement
                    this->when_true->interpret(table);
                }

                return table;
            }
    };

    class CaseStatement : public Statement {
        public:
            Expression    *condition;
            WhenStatement *when_stm;

            CaseStatement(Expression *condition, WhenStatement *when_stm)
                : condition{condition}
                , when_stm{when_stm}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("CaseStatement(", this->condition, ", ", this->when_stm, ")\n");
                #endif
            }

            ~CaseStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->when_stm);
            }

            int maxargs() const {
                return this->when_stm->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto result = this->condition->interpret(table);

                table.get_var_table().insert(cmp::detail::CASE_RESULT_NAME, result);
                this->when_stm->interpret(table);
                table.get_var_table().erase(cmp::detail::CASE_RESULT_NAME);

                return table;
            }
    };

    class FunctionStatement : public Statement {
        public:
            IdExpression *name;
            ExpressionList *args;
            Statement *body;

            /**
             *  \brief  Construct a new Function Statement object
             *          `def id (args) body`
             */
            FunctionStatement(IdExpression *name, ExpressionList *args, Statement *body)
                : name{name}
                , args{args}
                , body{body}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("FunctionStatement(", this->name->id, ", ", this->args, ", ", this->body, ")\n");
                #endif
            }

            FunctionStatement(IdExpression *name, Statement *body)
                : name{name}
                , args{nullptr}
                , body{body}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("FunctionStatement(", this->name->id, ", ", this->body, ")\n");
                #endif
            }

            FunctionStatement(IdExpression *name, ExpressionList *args)
                : name{name}
                , args{args}
                , body{nullptr}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("FunctionStatement(", this->name->id, ", ", this->args, ")\n");
                #endif
            }

            ~FunctionStatement() {
                utils::memory::delete_var(this->name);
                utils::memory::delete_var(this->args);
                utils::memory::delete_var(this->body);
            }

            int maxargs() const {
                return this->body ? this->body->maxargs() : 0;
            }

            SymbolTable& interpret(SymbolTable& table) const {
                // TODO FunctionStatement::interpret
                // Interpret body and set this->name in table to result?

                // Possibly use Function table to set function def here
                // and FunctionExpression set the parameter values before
                // interpreting the body and returning the result.

                const int arg_len = this->args ? this->args->maxargs() : 0;

                if (this->body) {
                    // Declaration
                    table.get_fun_table().insert(this->name->id, arg_len);
                } else {
                    // Call Statement
                    if (const auto argc = table.get_fun_table().get(this->name->id)) {
                        std::visit([&](auto&& arg) {
                            if (arg_len != arg) {
                                const auto name = utils::string::format("FunctionStatement \"%s\"", this->name->id.c_str());
                                const auto msg  = utils::string::format("Amount of arguments mismatch! Expected: %d vs given: %d", arg, arg_len);
                                throw utils::exceptions::Exception(name, msg);
                            } else {
                                // Interpret function
                                // TODO
                            }
                        }, argc.value());
                    } else {
                        throw utils::exceptions::KeyDoesNotExistException("FunctionTable", this->name->id);
                    }
                }

                return table;
            }
    };

    class UndefStatement : public Statement {
        public:
            IdExpression *id;

            /**
             *  \brief  Construct a new Undef Statement object
             *          `Stm -> undef id`
             *
             *  \param  id
             */
            UndefStatement(IdExpression *id)
                : id{id}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("UndefStatement(IdExpression(", this->id->id, "))\n");
                #endif
            }

            ~UndefStatement() {
                utils::memory::delete_var(this->id);
            }

            int maxargs() const {
                return 0;
            }

            SymbolTable& interpret(SymbolTable& table) const {
                // Erase id in Tables
                table.get_var_table().erase(this->id->id);
                table.get_fun_table().erase(this->id->id);
                return table;
            }
    };

    class ReturnStatement : public Statement {
        public:
            Expression *value;

            /**
             *  \brief  Construct a new Return Statement object
             *          `return expr`
             */
            ReturnStatement(Expression *value)
                : value{value}
            {
                // Empty
                #if CMP_VERBOSE_CTORS
                    utils::Logger::Stream("ReturnStatement(", this->value, ")\n");
                #endif
            }

            ~ReturnStatement() {
                utils::memory::delete_var(this->value);
            }

            int maxargs() const {
                return this->value->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                this->value->interpret(table);
                return table;
            }
    };
}
