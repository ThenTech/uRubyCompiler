#pragma once

#include "SymbolTable.hpp"

namespace cmp {
    using InterpretResult = std::pair<int, SymbolTable&>;

    class Common {
        public:
            virtual int maxargs() const = 0;
    };

    class Statement : public Common {
        public:
            Statement() {}
            virtual ~Statement() {}
            virtual SymbolTable& interpret(SymbolTable& table) const = 0;
    };

    class Expression : public Common {
        public:
            Expression() {}
            virtual ~Expression() {}
            virtual InterpretResult interpret(SymbolTable& table) const = 0;
    };

    class ExpressionList : public Common {
        public:
            ExpressionList() {}
            virtual ~ExpressionList() {}
            virtual InterpretResult interpret(SymbolTable& table) const = 0;
    };
}
