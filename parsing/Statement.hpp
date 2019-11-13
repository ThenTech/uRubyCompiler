#pragma once

#include <string_view>
#include "../utils/utils_lib/utils_math.hpp"
#include "../utils/utils_lib/utils_memory.hpp"
#include "fwd.hpp"

namespace cmp {
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
                table.insert(this->id->id, ret);
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
            }

            ~WhenStatement() {
                utils::memory::delete_var(this->condition);
                utils::memory::delete_var(this->when_true);
                utils::memory::delete_var(this->next);
            }

            int maxargs() const {
                return utils::math::max(this->when_true->maxargs(),
                                        this->next->maxargs());
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto result = this->condition->interpret(table);
                const bool cond = std::visit([](auto&& arg) { return bool(arg); }, result);

                // TODO WhenStatement::interpret ?

                if (cond) {
                    this->when_true->interpret(table);
                } else if (this->next) {
                    this->next->interpret(table);
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

                // TODO CaseStatement::interpret ?
                this->when_stm->interpret(table);

                return table;
            }
    };

    class FunctionStatement : public Statement {
        public:
            Expression *name;
            ExpressionList *args;
            Statement *body;

            /**
             *  \brief  Construct a new Function Statement object
             *          `def id (args) body`
             */
            FunctionStatement(Expression *name, ExpressionList *args, Statement *body)
                : name{name}
                , args{args}
                , body{body}
            {
                // Empty
            }

            FunctionStatement(Expression *name, Statement *body)
                : name{name}
                , args{nullptr}
                , body{body}
            {
                // Empty
            }

            ~FunctionStatement() {
                utils::memory::delete_var(this->name);
                utils::memory::delete_var(this->args);
                utils::memory::delete_var(this->body);
            }

            int maxargs() const {
                return this->body->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                // TODO FunctionStatement::interpret
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
