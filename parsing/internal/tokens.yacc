%{
#include "../tokens.hpp"
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
    lex_error(yytext);
    return 1;
}

cmp::Statement *root = nullptr;

%}

%start ROOT

// WARNING Must be hardcoded, cannot use cmp::Token enum or values...
%token  ID          500
%token  INTEGER     501
%token  REAL        502
%token  BOOLEAN     503
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

%type <stm>   ROOT statement ifstm whenstm stmseq stmseqend
%type <idexp> designator
%type <exp>   expression expr2 expr3 expr4
%type <expli> expressionlist argumentlist

%type <string>  ID STRING
%type <integer> INTEGER
%type <real>    REAL
%type <boolean> BOOLEAN

%left LT GT EQ NEQ LE GE AND OR
%left PLUS MINUS
%left TIMES DIVIDE MOD BINAND BINOR BINXOR

%%

ROOT:
    stmseq {
        $$ = $1;
        root = $$;
        utils::Logger::Success("BISON: done!");
    }
;

statement:
      designator ASSIGN expression
                                { ppos("stm::id ASSIGN exp");
                                  $$ = new cmp::AssignStatement($1, $3); }
    | designator PLUSASSIGN expression
                                { ppos("stm::id PLUSASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Plus, $3)); }
    | designator MINUSASSIGN expression
                                { ppos("stm::id MINUSASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Minus, $3)); }
    | designator MULASSIGN expression
                                { ppos("stm::id MULASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Times, $3)); }
    | designator DIVASSIGN expression
                                { ppos("stm::id DIVASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Div, $3)); }
    | designator MODASSIGN expression
                                { ppos("stm::id MODASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::Mod, $3)); }
    | designator ANDASSIGN expression
                                { ppos("stm::id ANDASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinCompareExpression($1, cmp::BinCompare::AND, $3)); }
    | designator ORASSIGN expression
                                { ppos("stm::id ORASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinCompareExpression($1, cmp::BinCompare::OR, $3)); }
    | designator BANDASSIGN expression
                                { ppos("stm::id ANDASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinAnd, $3)); }
    | designator BORASSIGN expression
                                { ppos("stm::id ORASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinOr, $3)); }
    | designator XORASSIGN expression
                                { ppos("stm::id XORASSIGN exp");
                                  $$ = new cmp::AssignStatement($1,
                                            new cmp::BinOperandExpression($1, cmp::BinaryOperand::BinXor, $3)); }

    | PRINT LPAREN expressionlist RPAREN
                                { ppos("stm::PRINT");
                                  $$ = new cmp::PrintStatement($3); }

    | IF expression THEN stmseq ifstm
                                { ppos("stm::IF");
                                  $$ = new cmp::IfStatement($2, $4, $5); }

    | WHILE expression DO stmseq END
                                { ppos("stm::WHILE");
                                  $$ = new cmp::WhileStatement($2, $4); }
    | UNTIL expression DO stmseq END
                                { ppos("stm::UNTIL");
                                  $$ = new cmp::UntilStatement($2, $4); }

    | UNLESS expression THEN stmseq END
                                { ppos("stm::UNLESS");
                                  $$ = new cmp::UnlessStatement($2, $4); }
    | UNLESS expression THEN stmseq ELSE stmseq END
                                { ppos("stm::UNLESS ELSE");
                                  $$ = new cmp::UnlessStatement($2, $4, $6); }

    | CASE expression WHEN expression THEN stmseq whenstm
                                { ppos("stm::CASE");
                                  $$ = new cmp::CaseStatement($2,
                                                              new cmp::WhenStatement($4, $6, $7));
                                }
    | CASE expression SEMICOLON WHEN expression THEN stmseq whenstm
                                { ppos("stm::CASE");
                                  $$ = new cmp::CaseStatement($2,
                                                              new cmp::WhenStatement($5, $7, $8));
                                }

    | DEF designator LPAREN argumentlist RPAREN stmseq END
                                { ppos("stm::DEF args");
                                  $$ = new cmp::FunctionStatement($2, $4, $6); }
    | DEF designator LPAREN RPAREN stmseq END
                                { ppos("stm::DEF");
                                  $$ = new cmp::FunctionStatement($2, $5); }

    | UNDEF designator          { ppos("stm::UNDEF");
                                  $$ = new cmp::UndefStatement($2); }

    | RETURN expression         { ppos("stm::RETURN");
                                  $$ = new cmp::ReturnStatement($2); }
    ;

ifstm:
      ELSIF expression THEN stmseq ifstm
                                { ppos("ifstm::ELSIF");
                                  $$ = new cmp::IfStatement($2, $4, $5); }
    | ELSE stmseq END           { ppos("ifstm::ELSE");
                                  $$ = $2; }
    | END                       { ppos("ifstm::END");
                                  $$ = nullptr; }
    ;

whenstm:
      WHEN expression THEN stmseq whenstm
                                { ppos("whenstm::WHEN");
                                  $$ = new cmp::WhenStatement($2, $4, $5); }
    | ELSE stmseq END
                                { ppos("whenstm::ELSE");
                                  $$ = new cmp::WhenStatement(nullptr, $2); }
    | END                       { ppos("whenstm::END");
                                  $$ = nullptr; }
    ;

stmseq:
      SEMICOLON stmseq
                                { ppos("stmseq::SEMICOLON stm");
                                  $$ = $2; }
    | statement stmseqend
                                { ppos("stmseq::stm SEMICOLON stm");
                                  $$ = new cmp::CompoundStatement($1, $2); }
    | statement                 { ppos("stmseq::stm");
                                  $$ = $1; }
    ;

stmseqend:
      SEMICOLON stmseq
                                { ppos("stmseqend::;stm");
                                  $$ = $2; }
    | SEMICOLON                 { $$ = nullptr; ppos("stmseqend::SEMICOLON"); utils::Logger::WriteLn(";"); }
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
    ;

argumentlist:
      designator COMMA argumentlist
                                { ppos("arglist::id COMMA args");
                                  $$ = new cmp::PairExpressionList($1, $3); }
    | designator                { ppos("arglist::id");
                                  $$ = new cmp::LastExpressionList($1); }
    ;

expressionlist:
      expression COMMA expressionlist
                                { ppos("explist::exp COMMA explist");
                                  $$ = new cmp::PairExpressionList($1, $3); }
    | expression                { ppos("explist::exp");
                                  $$ = new cmp::LastExpressionList($1); }
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
    | BINNOT expr4              { ppos("expr4::NOT");
                                  $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::BinNot, $2); }

    | LPAREN expression RPAREN  { ppos("expr4::(exp)");
                                  $$ = $2; }
    | LPAREN statement COMMA expression RPAREN
                                { ppos("expr4::(stm,exp)");
                                  $$ = new cmp::ExpseqExpression($2, $4); }
    | designator LPAREN expressionlist RPAREN
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
                                  const auto val = utils::misc::lexical_cast<double>(raw);
                                  $$ = new cmp::ValueExpression(val); }
    | BOOLEAN                   { ppos("expr4::bool");
                                  $$ = new cmp::ValueExpression(yytext[0] == 't'); }
    | designator                { ppos("expr4::id");
                                  $$ = $1; }
    ;

designator:
    ID                          { ppos("id::id");
                                  $$ = new cmp::IdExpression(std::string_view{yytext, size_t(yyleng)}); }
    ;
