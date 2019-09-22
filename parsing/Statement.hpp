#pragma once

#include <string_view>
#include "../utils/utils_lib/utils_math.hpp"
#include "../utils/utils_lib/utils_memory.hpp"
#include "fwd.hpp"

namespace cmp {
    class AssignStatement : public Statement {
        public:
            std::string_view id;
            Expression       *exp;

            /**
             *  \brief  Construct a new Assign Statement object
             *          `Stm -> id := Exp`
             *
             *  \param  id
             *  \param  exp
             */
            AssignStatement(std::string_view id, Expression *exp)
                : id{id}
                , exp{exp}
            {
                // Empty
            }

            ~AssignStatement() {
                utils::memory::delete_var(this->exp);
            }

            int maxargs() const {
                return this->exp->maxargs();
            }

            SymbolTable& interpret(SymbolTable& table) const {
                const auto ret = this->exp->interpret(table);
                table.insert(this->id, ret.first);
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
                const auto ret = this->exps->interpret(table);
                return ret.second;
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
}
