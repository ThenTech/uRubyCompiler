
%{
#include "../tokens.hpp"
#define ENUM_VAL(X) utils::traits::to_underlying(X)

typedef struct {
  int line;
  int column;
} yyLocation;

/// Store the current position
static yyLocation yylocation { 1, 1 };

/// Called on every match
#define YY_USER_ACTION \
    yylocation.column += yyleng;

/// Call when a newline is encountered
#define YY_NEWLINE_ACTION  \
    yylocation.column = 1; \
    yylocation.line++;

void ppos(const char* rule = "\0") {
    #if CMP_VERBOSE_CTORS
        if (rule[0] != '\0')
            utils::Logger::Writef("%03d:%03d [%s] => ", yylocation.line, yylocation.column - 1, rule);
        else
            utils::Logger::Writef("%03d:%03d => ", yylocation.line, yylocation.column - 1);
    #endif
}

void lex_error(const char* const text) {
    if (text[0] < ' ' || text[0] > '~') {
        const std::string frmt = utils::string::format(
            "FLEX: Illegal character 0x%02X at line %d, column %d!",
            static_cast<int>(text[0]), yylocation.line, yylocation.column - 1
        );

        utils::Logger::Error(frmt);
        // fprintf(stderr, "%s\n", frmt.c_str());
    } else {
        const std::string frmt = utils::string::format(
            "FLEX: Illegal character \"%s\" at line %d, column %d!",
            text, yylocation.line, yylocation.column - 1
        );

        utils::Logger::Error(frmt);
        // fprintf(stderr, "%s\n", frmt.c_str());
    }
}

%}

identifier    [a-zA-Z_]([a-zA-Z_]|[0-9])*
numeric       ([0-9]+((\_)?[0-9]+)*)
real          (((({numeric}+)|({numeric}+\.{numeric}*)|({numeric}*\.{numeric}+))[eE]{1}[\-\+]?{numeric}+)|({numeric}+\.{numeric}*)|({numeric}*\.{numeric}+))
boolean       (true|false)
string        \"[^"]*\"
comment       (\-{2}|\#|\/{2}).*\n
whitespace    [\t\f\v\ ]+
linefeed      [\r\n]
comma         \,
colon         \:
semicolon     \;
dot           \.
lparen        \(
rparen        \)
lbrack        \[
rbrack        \]
lbrace        \{
rbrace        \}
plus          \+
minus         \-
times         \*
divide        \/
mod           \%
uminus        \-
binand        \&
binor         \|
binxor        \^
binnot        \~
assign        \=
assignplus    \+\=
assignmin     \-\=
assignmul     \*\=
assigndiv     \/\=
assignmod     \%\=
assignand     \&\&\=
assignor      \|\|\=
assignbinand  \&\=
assignbinor   \|\=
assignbinxor  \^\=
equals        \=\=
notequals     \!\=
less          \<
lessequals    \<\=
greater       \>
greaterequals \>\=
and           \&\&
or            \|\|
not           \!
array         {lbrace}\s*(({numeric}|{real}|{boolean}|{string})\s*\,?\s*)+\s*{rbrace}

%%

if                     { return ENUM_VAL(cmp::Token::IF);        }
then                   { return ENUM_VAL(cmp::Token::THEN);      }
elsif                  { return ENUM_VAL(cmp::Token::ELSIF);     }
else                   { return ENUM_VAL(cmp::Token::ELSE);      }
while                  { return ENUM_VAL(cmp::Token::WHILE);     }
until                  { return ENUM_VAL(cmp::Token::UNTIL);     }
do                     { return ENUM_VAL(cmp::Token::DO);        }
unless                 { return ENUM_VAL(cmp::Token::UNLESS);    }
when                   { return ENUM_VAL(cmp::Token::WHEN);      }
case                   { return ENUM_VAL(cmp::Token::CASE);      }
end                    { return ENUM_VAL(cmp::Token::END);       }
nil                    { return ENUM_VAL(cmp::Token::NIL);       }
undef                  { return ENUM_VAL(cmp::Token::UNDEF);     }
def                    { return ENUM_VAL(cmp::Token::DEF);       }
return                 { return ENUM_VAL(cmp::Token::RETURN);    }

{boolean}              { return ENUM_VAL(cmp::Token::BOOLEAN);     }
{identifier}           { return ENUM_VAL(cmp::Token::ID);          }
{real}                 { return ENUM_VAL(cmp::Token::REAL);        }
{numeric}              { return ENUM_VAL(cmp::Token::INTEGER);     }
{string}               { return ENUM_VAL(cmp::Token::STRING);      }
{array}                { return ENUM_VAL(cmp::Token::ARRAY);       }

{assign}               { return ENUM_VAL(cmp::Token::ASSIGN);      }
{assignplus}           { return ENUM_VAL(cmp::Token::PLUSASSIGN);  }
{assignmin}            { return ENUM_VAL(cmp::Token::MINUSASSIGN); }
{assignmul}            { return ENUM_VAL(cmp::Token::MULASSIGN);   }
{assigndiv}            { return ENUM_VAL(cmp::Token::DIVASSIGN);   }
{assignmod}            { return ENUM_VAL(cmp::Token::MODASSIGN);   }
{assignand}            { return ENUM_VAL(cmp::Token::ANDASSIGN);   }
{assignor}             { return ENUM_VAL(cmp::Token::ORASSIGN);    }
{assignbinand}         { return ENUM_VAL(cmp::Token::BANDASSIGN);  }
{assignbinor}          { return ENUM_VAL(cmp::Token::BORASSIGN);   }
{assignbinxor}         { return ENUM_VAL(cmp::Token::XORASSIGN);   }

{comma}                { return ENUM_VAL(cmp::Token::COMMA);     }
{colon}                { return ENUM_VAL(cmp::Token::COLON);     }
{semicolon}            { return ENUM_VAL(cmp::Token::SEMICOLON); }
{dot}                  { return ENUM_VAL(cmp::Token::DOT);       }
{lparen}               { return ENUM_VAL(cmp::Token::LPAREN);    }
{rparen}               { return ENUM_VAL(cmp::Token::RPAREN);    }
{lbrack}               { return ENUM_VAL(cmp::Token::LBRACK);    }
{rbrack}               { return ENUM_VAL(cmp::Token::RBRACK);    }
{lbrace}               { return ENUM_VAL(cmp::Token::LBRACE);    }
{rbrace}               { return ENUM_VAL(cmp::Token::RBRACE);    }

{equals}               { return ENUM_VAL(cmp::Token::EQ);        }
{notequals}            { return ENUM_VAL(cmp::Token::NEQ);       }
{less}                 { return ENUM_VAL(cmp::Token::LT);        }
{lessequals}           { return ENUM_VAL(cmp::Token::LE);        }
{greater}              { return ENUM_VAL(cmp::Token::GT);        }
{greaterequals}        { return ENUM_VAL(cmp::Token::GE);        }
{and}                  { return ENUM_VAL(cmp::Token::AND);       }
{or}                   { return ENUM_VAL(cmp::Token::OR);        }
{not}                  { return ENUM_VAL(cmp::Token::NOT);       }

{plus}                 { return ENUM_VAL(cmp::Token::PLUS);      }
{minus}                { return ENUM_VAL(cmp::Token::MINUS);     }
{times}                { return ENUM_VAL(cmp::Token::TIMES);     }
{divide}               { return ENUM_VAL(cmp::Token::DIVIDE);    }
{mod}                  { return ENUM_VAL(cmp::Token::MOD);       }
{binand}               { return ENUM_VAL(cmp::Token::BINAND);    }
{binor}                { return ENUM_VAL(cmp::Token::BINOR);     }
{binxor}               { return ENUM_VAL(cmp::Token::BINXOR);    }
{binnot}               { return ENUM_VAL(cmp::Token::BINNOT);    }

{whitespace}           { /* Do nothing */ }
{comment}              { YY_NEWLINE_ACTION
                         return ENUM_VAL(cmp::Token::SEMICOLON);
                       }
{linefeed}             { YY_NEWLINE_ACTION
                         return ENUM_VAL(cmp::Token::ENDTOKEN);
                        // return ENUM_VAL(cmp::Token::SEMICOLON);
                       }

.   {
        lex_error(yytext);
    }

%%


#if YY_FLEX_MAJOR_VERSION == 2 && \
    YY_FLEX_MINOR_VERSION == 6 && \
    YY_FLEX_SUBMINOR_VERSION == 3
/* https://github.com/westes/flex/issues/162 */
#undef yywrap
#endif

#ifndef yywrap
    int yywrap(void) { return 1; }
#endif
