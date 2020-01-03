#pragma once
#include <string_view>
#include "../utils/utils_lib/utils_traits.hpp"
#include "../utils/utils_lib/utils_logger.hpp"


namespace cmp {
    enum class Token : int {
        ID=500   ,
        INTEGER  , REAL      , BOOLEAN    , STRING   , NIL      ,

        IF       , THEN      , ELSIF      , ELSE     ,
        WHILE    , UNTIL     , DO         , UNLESS   ,
        WHEN     , CASE      ,
        END      , RETURN    ,

        COMMA    , COLON     , SEMICOLON  , DOT      ,
        LPAREN   , RPAREN    , LBRACK     , RBRACK   , LBRACE   , RBRACE,

        ASSIGN   , PLUSASSIGN, MINUSASSIGN, MULASSIGN, DIVASSIGN, MODASSIGN,
        ANDASSIGN, ORASSIGN  , BANDASSIGN , BORASSIGN, XORASSIGN,

        PLUS     , MINUS     , TIMES      , DIVIDE   , MOD      ,
        UMINUS   , BINAND    , BINOR      , BINXOR   , BINNOT   ,
        EQ       , NEQ       , LT         , LE       , GT       , GE,
        AND      , OR        , NOT        ,

        ARRAY    ,
        DEF      , UNDEF     ,
        PRINT    ,
        ENDTOKEN
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

            "ASSIGN"   , "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN", "MODASSIGN",
            "ANDASSIGN", "ORASSIGN"  , "BINANDASSIGN", "BINORASSIGN", "XORASSIGN"  ,

            "PLUS"     , "MINUS"     , "TIMES"      , "DIVIDE"   , "MOD"      ,
            "UMINUS"   , "BINAND"    , "BINOR"      , "BINXOR"   , "BINNOT"   ,
            "EQ"       , "NEQ"       , "LT"         , "LE"       , "GT"       , "GE",
            "AND"      , "OR"        , "NOT"        ,

            "ARRAY"    ,
            "DEF"      , "UNDEF" ,
            "PRINT"    ,
            "ENDTOKEN"
        };

        static constexpr std::string_view to_string(const cmp::Token t) {
            int offset = utils::traits::to_underlying(t) - utils::traits::to_underlying(cmp::Token::ID) + 1;

            if (utils::math::within_inclusive(offset,
                                              utils::traits::to_underlying(cmp::Token::ID),
                                              utils::traits::to_underlying(cmp::Token::ENDTOKEN) - 1))
            {
                offset = 0;
            }

            return cmp::detail::_TokenStrings[offset];
        }
    }

    template<typename TChar, typename TCharTraits>
    auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const cmp::Token& t)
    {
        stream << cmp::detail::to_string(t);
        return stream;
    }
}
