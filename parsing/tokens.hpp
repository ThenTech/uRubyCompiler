#pragma once
#include <string_view>
#include "../utils/utils_lib/utils_traits.hpp"
#include "../utils/utils_lib/utils_logger.hpp"

namespace cmp {
    enum class Token : int {
        ID=1     ,
        INTEGER  , REAL      , BOOLEAN    , STRING   , NIL      ,

        IF       , THEN      , ELSIF      , ELSE     ,
        WHILE    , UNTIL     , DO         , UNLESS   ,
        WHEN     , CASE      ,
        END      , RETURN    ,

        COMMA    , COLON     , SEMICOLON  , DOT      ,
        LPAREN   , RPAREN    , LBRACK     , RBRACK   , LBRACE   , RBRACE,

        ASSIGN   , PLUSASSIGN, MINUSASSIGN, MULASSIGN, DIVASSIGN, // MODASSIGN
        ANDASSIGN, ORASSIGN  ,

        PLUS     , MINUS     , TIMES      , DIVIDE   , // MOD
        UMINUS   ,
        EQ       , NEQ       , LT         , LE       , GT       , GE,
        AND      , OR        , NOT        ,

        ARRAY    ,
        DEF      , UNDEF     ,
        PRINT
    };

    namespace detail {
        static constexpr std::string_view _TokenStrings[] {
            "?",
            "IDENTIFIER",
            "INTEGER"   , "REAL"     , "BOOLEAN"    , "STRING"   , "NIL"      ,

            "IF"       , "THEN"      , "ELSIF"      , "ELSE"     ,
            "WHILE"    , "UNTIL"     , "DO"         , "UNLESS"   ,
            "WHEN"     , "CASE"      ,
            "END"      , "RETURN"    ,

            "COMMA"    , "COLON"     , "SEMICOLON"  , "DOT"      ,
            "LPAREN"   , "RPAREN"    , "LBRACK"     , "RBRACK"   , "LBRACE"   , "RBRACE",

            "ASSIGN"   , "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN", // "MODASSIGN"
            "ANDASSIGN", "ORASSIGN"  ,

            "PLUS"     , "MINUS"     , "TIMES"      , "DIVIDE"   , // "MOD"
            "UMINUS"   ,
            "EQ"       , "NEQ"       , "LT"         , "LE"       , "GT"       , "GE",
            "AND"      , "OR"        , "NOT"        ,

            "ARRAY"    ,
            "DEF"      , "UNDEF" ,
            "PRINT"
        };

        static constexpr std::string_view to_string(const cmp::Token t) {
            return cmp::detail::_TokenStrings[utils::traits::to_underlying(t)];
        }
    }

    template<typename TChar, typename TCharTraits>
    auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const Token& t)
    {
        stream << cmp::detail::to_string(t);
        return stream;
    }
}
