%{
#pragma once
#include "../tokens.hpp"
#include "yylexer.hpp"
#include "../fwd.hpp"
#include "../Expression.hpp"
#include "../Statement.hpp"
#include "../../utils/utils_lib/utils_misc.hpp"
#include "../../utils/utils_lib/utils_string.hpp"

#define YYERROR_VERBOSE
#define ENUM_VAL(X) utils::traits::to_underlying(X)

extern char* yytext;

int yyerror(const char *msg) {
    utils::Logger::WriteLn("");
    utils::Logger::Error("BISON: %s", msg);
    cmp::parse_flags.ErrorIllegalChar({yytext, size_t(yyleng)});
    return 1;
}

void ppos(const char* rule = "\0") {
    #if CMP_VERBOSE_CTORS
        cmp::parse_flags.LogPosition(rule);
    #endif
}

static cmp::Statement *root = nullptr;

%}

%start ROOT

// WARNING Must be hardcoded, cannot use cmp::Token enum or values...
%token  ID          500
%token  INTEGER     501
%token  REAL        502
%token  BOOLEANVAR  503
%token  STRING      504
%token  NIL         505

%token  IF          506
%token  THEN        507
%token  ELSIF       508
%token  ELSE        509
%token  WHILE       510
%token  UNTIL       511
%token  DO          512
%token  UNLESS      513
%token  WHEN        514
%token  CASE        515
%token  END         516
%token  RETURN      517

%token  COMMA       518
%token  COLON       519
%token  SEMICOLON   520
%token  DOT         521
%token  LPAREN      522
%token  RPAREN      523
%token  LBRACK      524
%token  RBRACK      525
%token  LBRACE      526
%token  RBRACE      527

%token  ASSIGN      528
%token  PLUSASSIGN  529
%token  MINUSASSIGN 530
%token  MULASSIGN   531
%token  DIVASSIGN   532
%token  MODASSIGN   533
%token  ANDASSIGN   534
%token  ORASSIGN    535
%token  BANDASSIGN  536
%token  BORASSIGN   537
%token  XORASSIGN   538

%token  PLUS        539
%token  MINUS       540
%token  TIMES       541
%token  DIVIDE      542
%token  MOD         543
%token  UMINUS      544
%token  BINAND      545
%token  BINOR       546
%token  BINXOR      547
%token  BINNOT      548

%token  EQ          549
%token  NEQ         550
%token  LT          551
%token  LE          552
%token  GT          553
%token  GE          554
%token  AND         555
%token  OR          556
%token  NOT         557

%token  ARRAY       558
%token  DEF         559
%token  UNDEF       560
%token  PRINT       561

%token  ENDTOKEN    562


%union {
    cmp::Statement      *stm;
    cmp::Expression     *exp;
    cmp::IdExpression   *idexp;
    cmp::ExpressionList *expli;

    char*   string;
    int32_t integer;
    double  real;
    bool    boolean;
}

%type <stm>   ROOT statement ifstm whenstm stmseq stmseq2 returnmark
%type <idexp> designator
%type <exp>   expression expr2 expr3 expr4
%type <expli> expressionlist argumentlist

%type <string>  ID STRING
%type <integer> INTEGER
%type <real>    REAL
%type <boolean> BOOLEANVAR

%nonassoc LT GT EQ NEQ LE GE AND OR
%right ASSIGN
%right PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN MODASSIGN ANDASSIGN ORASSIGN BANDASSIGN BORASSIGN XORASSIGN
%left PLUS MINUS
%left TIMES DIVIDE MOD BINAND BINOR BINXOR
%right THEN ELSE

%right ENDTOKEN SEMICOLON

%%

ROOT:
    stmseq                      { $$ = $1; root = $$; }
;

ifmark:
      IF                        {}
    ;

elifmark:
      ENDTOKEN ELSIF            {}
    | ELSIF                     {}
    ;

thenmark:
      ENDTOKEN THEN ENDTOKEN    {}
    | THEN ENDTOKEN             {}
    | ENDTOKEN THEN             {}
    | THEN                      {}
    ;

elsemark:
      ENDTOKEN ELSE ENDTOKEN    {}
    | ELSE ENDTOKEN             {}
    | ENDTOKEN ELSE             {}
    | ELSE                      {}
    ;

endmark:
      ENDTOKEN END endmarker2   {}
    | END endmarker2            {}
    ;

defmark:
      DEF                       { cmp::parse_flags.EnterDefinition(); }
    ;

lparenmark:
      LPAREN ENDTOKEN           {}
    | LPAREN                    {}
    ;

rparenmark:
      ENDTOKEN RPAREN ENDTOKEN  {}
    | RPAREN ENDTOKEN           {}
    | ENDTOKEN RPAREN           {}
    | RPAREN                    {}
    ;

returnmark:
      RETURN expression         { ppos("stm::RETURN");
                                  if (cmp::parse_flags.EnteredDefinition()) {
                                    $$ = new cmp::ReturnStatement($2);
                                  } else {
                                    yyerror("syntax error, RETURN token outside of function block!");
                                    YYERROR;
                                  }
                                }
    ;

whilemark:
      WHILE                     {}
    ;

unlessmark:
      UNLESS                    {}
    ;

domark:
      ENDTOKEN DO ENDTOKEN      {}
    | DO ENDTOKEN               {}
    | ENDTOKEN DO               {}
    | DO                        {}
    ;

untillmark:
      UNTIL                     {}
    ;

casemark:
      CASE                      {}
    ;

whenmark:
      ENDTOKEN WHEN             {}
    | WHEN                      {}
    ;

commamark:
      ENDTOKEN COMMA ENDTOKEN   {}
    | COMMA ENDTOKEN            {}
    | ENDTOKEN COMMA            {}
    | COMMA                     {}
    ;

statement:
      PRINT lparenmark expressionlist rparenmark endmarker
                                { ppos("stm::PRINT(explist)");
                                  $$ = new cmp::PrintStatement($3); }

    | ifmark expression thenmark stmseq ifstm
                                { ppos("stm::IF");
                                  $$ = new cmp::IfStatement($2, $4, $5); }

    | whilemark expression domark stmseq endmark
                                { ppos("stm::WHILE");
                                  $$ = new cmp::WhileStatement($2, $4); }
    | untillmark expression domark stmseq endmark
                                { ppos("stm::UNTIL");
                                  $$ = new cmp::UntilStatement($2, $4); }

    | unlessmark expression thenmark stmseq endmark
                                { ppos("stm::UNLESS");
                                  $$ = new cmp::UnlessStatement($2, $4); }
    | unlessmark expression thenmark stmseq elsemark stmseq endmark
                                { ppos("stm::UNLESS ELSE");
                                  $$ = new cmp::UnlessStatement($2, $4, $6); }

    | casemark expression whenmark expression thenmark stmseq whenstm
                                { ppos("stm::CASE");
                                  $$ = new cmp::CaseStatement($2,
                                                              new cmp::WhenStatement($4, $6, $7));
                                }

    | defmark designator lparenmark argumentlist rparenmark stmseq endmark
                                { ppos("stm::DEF id(args)");
                                  cmp::parse_flags.LeaveDefinition();
                                  $$ = new cmp::FunctionStatement($2, $4, $6); }

    | UNDEF designator          { ppos("stm::UNDEF");
                                  $$ = new cmp::UndefStatement($2); }

    | returnmark                { ppos("stm::returnmark");
                                  $$ = $1; }

    | expression                { ppos("stm::expr");
                                  $$ = new cmp::ExpressionStatement($1); }
    ;

ifstm:
      elifmark expression thenmark stmseq ifstm
                                { ppos("ifstm::ELSIF");
                                  $$ = new cmp::IfStatement($2, $4, $5); }
    | elsemark stmseq endmark   { ppos("ifstm::ELSE");
                                  $$ = $2; }
    | endmark                   { ppos("ifstm::END");
                                  $$ = nullptr; }
    ;

whenstm:
      whenmark expression thenmark stmseq whenstm
                                { ppos("whenstm::WHEN");
                                  $$ = new cmp::WhenStatement($2, $4, $5); }
    | elsemark stmseq endmark
                                { ppos("whenstm::ELSE");
                                  $$ = new cmp::WhenStatement(nullptr, $2); }
    | endmark                   { ppos("whenstm::END");
                                  $$ = nullptr; }
    ;


// // Attempt 3
// stmseq:
//       stmseq endmarker2 stmseq2 { ppos("stmseq::stmseq endmarker2 stm");
//                                   $$ = new cmp::CompoundStatement($1, $3); }
//     | stmseq2                   { ppos("stmseq::stm");
//                                   $$ = $1; }
//     ;

// stmseq2:
//       statement                 { $$ = $1; }
//     ;

// // Attempt 2
stmseq:
      statement stmseq2         { ppos("stmseq::stm stmseq2");
                                  $$ = new cmp::CompoundStatement($1, $2); }
    | statement endmarker       { ppos("stmseq::stm endmarker");
                                  $$ = $1; }
    ;

stmseq2:
      endmarker stmseq          { ppos("stmseq2::endmarker stmseq");
                                  $$ = $2; }
    | endmarker statement       { ppos("stmseq2::endmarker stm");
                                  $$ = $2; }
    ;


// // Attemp 1
// stmseq:
//       endmarker stmseq
//                                 { ppos("stmseq::endmarker stmseq");
//                                   $$ = $2; }
//     | stmseq endmarker statement
//                                 { ppos("stmseq::stmseq endmarker stm");
//                                   $$ = new cmp::CompoundStatement($1, $3); }
//     | statement endmarker stmseq
//                                 { ppos("stmseq::stm endmarker stmseq");
//                                   $$ = new cmp::CompoundStatement($1, $3); }
//     | statement endmarker
//                                 { ppos("stmseq::stm endmarker");
//                                   $$ = $1; }
//     | statement                 { ppos("stmseq::stm");
//                                   $$ = $1; }
//     | stmseq returnmark         { ppos("stmseq::stmseq returnmark");
//                                   $$ = new cmp::CompoundStatement($1, $2); }
//     ;
// stmseq2:
//       statement                 { $$ = $1; }
//     ;

endmarker2:
      ENDTOKEN                  { ppos("endmarker2::ENDTOKEN"); }
    | ENDTOKEN endmarker2       { ppos("endmarker2::ENDTOKEN endmarker2"); }
    | SEMICOLON                 { ppos("endmarker2::SEMICOLON"); }
    | SEMICOLON endmarker2      { ppos("endmarker2::SEMICOLON endmarker2"); }
    ;

endmarker:
      endmarker2                { ppos("endmarker::2"); }
    | %empty                    { ppos("endmarker::?EMPTY?"); }
    ;

expression:
      expr2                     { ppos("expr::expr2");
                                  $$ = $1; }
    | expr2 EQ expr2            { ppos("expr::EQ");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::EQ,  $3); }
    | expr2 NEQ expr2           { ppos("expr::NEQ");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::NEQ, $3); }
    | expr2 LT expr2            { ppos("expr::LT");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::LT,  $3); }
    | expr2 LE expr2            { ppos("expr::LE");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::LE,  $3); }
    | expr2 GT expr2            { ppos("expr::GT");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::GT,  $3); }
    | expr2 GE expr2            { ppos("expr::GE");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::GE,  $3); }
    | expr2 AND expr2           { ppos("expr::AND");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::AND, $3); }
    | expr2 OR expr2            { ppos("expr::OR");
                                  $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::OR,  $3); }

    | designator ASSIGN expression
                                { ppos("expr::id ASSIGN exp");
                                  $$ = new cmp::AssignExpression($1, $3); }
    | designator PLUSASSIGN expression
                                { ppos("expr::id PLUSASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Plus, $3)); }
    | designator MINUSASSIGN expression
                                { ppos("expr::id MINUSASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Minus, $3)); }
    | designator MULASSIGN expression
                                { ppos("expr::id MULASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Times, $3)); }
    | designator DIVASSIGN expression
                                { ppos("expr::id DIVASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Div, $3)); }
    | designator MODASSIGN expression
                                { ppos("expr::id MODASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Mod, $3)); }
    | designator ANDASSIGN expression
                                { ppos("expr::id ANDASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinCompareExpression($1, cmp::BinCompare::AND, $3)); }
    | designator ORASSIGN expression
                                { ppos("expr::id ORASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinCompareExpression($1, cmp::BinCompare::OR, $3)); }
    | designator BANDASSIGN expression
                                { ppos("expr::id ANDASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinAnd, $3)); }
    | designator BORASSIGN expression
                                { ppos("expr::id ORASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinOr, $3)); }
    | designator XORASSIGN expression
                                { ppos("expr::id XORASSIGN exp");
                                  $$ = new cmp::AssignExpression(new cmp::IdExpression(*$1),
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinXor, $3)); }
    ;

argumentlist:
      designator commamark argumentlist
                                { ppos("arglist::id COMMA args");
                                  $$ = new cmp::PairExpressionList($1, $3); }
    | designator                { ppos("arglist::id");
                                  $$ = new cmp::LastExpressionList($1); }
    | %empty                    { $$ = nullptr; }
    ;

expressionlist:
      expression commamark expressionlist
                                { ppos("explist::exp COMMA explist");
                                  $$ = new cmp::PairExpressionList($1, $3); }
    | expression                { ppos("explist::exp");
                                  $$ = new cmp::LastExpressionList($1); }
    | %empty                    { $$ = nullptr; }
    ;

expr2:
      expr3                     { ppos("expr2::expr3");
                                  $$ = $1; }
    | expr2 PLUS expr3          { ppos("expr2::PLUS");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Plus, $3); }
    | expr2 MINUS expr3         { ppos("expr2::MINUS");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Minus, $3); }
    ;

expr3:
      expr4                     { ppos("expr3::expr4");
                                  $$ = $1; }
    | expr3 TIMES expr4         { ppos("expr3::TIMES");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Times, $3); }
    | expr3 DIVIDE expr4        { ppos("expr3::DIVIDE");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Div, $3); }
    | expr3 MOD expr4           { ppos("expr3::MOD");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Mod, $3); }
    | expr3 BINAND expr4        { ppos("expr3::BINAND");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinAnd, $3); }
    | expr3 BINOR expr4         { ppos("expr3::BINOR");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinOr, $3); }
    | expr3 BINXOR expr4        { ppos("expr3::BINXOR");
                                  $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinXor, $3); }
    ;

expr4:
      PLUS expr4                { ppos("expr4::PLUS");
                                  $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Plus, $2); }
    | MINUS expr4               { ppos("expr4::MINUS");
                                  $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Minus, $2); }
    | NOT expr4                 { ppos("expr4::NOT");
                                  $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Not, $2); }
    | BINNOT expr4              { ppos("expr4::BINNOT");
                                  $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::BinNot, $2); }

    | lparenmark expression rparenmark
                                { ppos("expr4::(exp)");
                                  $$ = $2; }
    | lparenmark statement commamark expression rparenmark
                                { ppos("expr4::(stm,exp)");
                                  $$ = new cmp::ExpseqExpression($2, $4); }
    | designator lparenmark expressionlist rparenmark
                                { ppos("expr4::id(explist)");
                                  $$ = new cmp::FunctionExpression($1, $3); }

    | INTEGER                   { ppos("expr4::int");
                                  std::string raw{yytext, size_t(yyleng)};
                                  utils::string::erase_all(raw, "_");
                                  const auto val = utils::misc::lexical_cast<int32_t>(raw);
                                  $$ = new cmp::ValueExpression(val); }
    | REAL                      { ppos("expr4::real");
                                  std::string raw{yytext, size_t(yyleng)};
                                  utils::string::erase_all(raw, "_");
                                  const double val = utils::misc::lexical_cast<double>(raw);
                                  $$ = new cmp::ValueExpression(val); }
    | BOOLEANVAR                { ppos("expr4::bool");
                                  $$ = new cmp::ValueExpression(yytext[0] == 't'); }
    | designator                { ppos("expr4::id");
                                  $$ = $1; }
    ;

designator:
    ID                          { ppos("id::id");
                                  $$ = new cmp::IdExpression(std::string_view{yytext, size_t(yyleng)}); }
    ;
