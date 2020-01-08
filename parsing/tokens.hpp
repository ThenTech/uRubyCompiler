#pragma once
#include <string_view>
#include "../utils/utils_lib/utils_traits.hpp"
#include "../utils/utils_lib/utils_logger.hpp"
#include "../utils/utils_lib/utils_string.hpp"


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

        struct yyLocation {
            int line;
            int column;
        };

        class ParseFlags {
            private:
                // Track row and column position
                cmp::detail::yyLocation location;

                // True if DEF encountered, false after FunctionStatement created.
                bool saw_defmark;

                // True if lexer saw EOF, append ENDTOKEN for first time
                bool saw_eof;
            public:
                ParseFlags() noexcept : location{1, 1} {}

                void Reset() noexcept {
                    this->location = {1, 1};
                    this->saw_defmark = this->saw_eof = false;
                }

                void NextLine() noexcept {
                    this->location.column = 1;
                    this->location.line++;
                }

                void NextCol(int token_len) noexcept {
                    this->location.column += token_len;
                }

                void EnterDefinition()   noexcept       { this->saw_defmark = true;  }
                bool EnteredDefinition() const noexcept { return this->saw_defmark;  }
                void LeaveDefinition()   noexcept       { this->saw_defmark = false; }

                bool ReachEOF() noexcept {
                    bool prev = this->saw_eof;
                    this->saw_eof = true;
                    return prev;
                }

                void LogPosition(const std::string_view rule = {}) {
                    utils::Logger::Stream(*this);
                    if (rule.size())
                        utils::Logger::Stream(" [", rule, "]");
                    utils::Logger::Stream(" => ");
                }

                void ErrorIllegalChar(utils::string::string_view sv) {
                    if (sv.size()) {
                        if (sv[0] < ' ' || sv[0] > '~') {
                            const std::string frmt = utils::string::format(
                                "FLEX: Illegal character 0x%02X at line %d, column %d!",
                                static_cast<int>(sv[0]), this->location.line, this->location.column - 1
                            );
                            utils::Logger::Error(frmt);
                        } else {
                            const std::string frmt = utils::string::format(
                                "FLEX: Illegal character \"%s\" at line %d, column %d!",
                                sv.data(), this->location.line, this->location.column - 1
                            );
                            utils::Logger::Error(frmt);
                        }
                    } else {
                        const std::string frmt = utils::string::format(
                            "FLEX: Illegal character <?> at line %d, column %d!",
                            this->location.line, this->location.column - 1
                        );
                        utils::Logger::Error(frmt);
                    }
                }

                template<typename TChar, typename TCharTraits>
                friend auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                                        const ParseFlags& p)
                {
                    stream << utils::string::format("%03d:%03d", p.location.line, p.location.column);
                    return stream;
                }
        };
    }

    template<typename TChar, typename TCharTraits>
    auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                     const cmp::Token& t)
    {
        stream << cmp::detail::to_string(t);
        return stream;
    }

    static cmp::detail::ParseFlags parse_flags{};
}
