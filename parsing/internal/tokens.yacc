%{
#include "../tokens.hpp"
#include "../fwd.hpp"
#include "../Expression.hpp"
#include "../Statement.hpp"

int yyerror(const char *msg) {
    utils::Logger::Error("BISON: %s", msg);
}

Statement root;

%}

%start ROOT

%token  ID
        INTEGER   REAL       BOOLEAN     STRING    NIL

        IF        THEN       ELSIF       ELSE
        WHILE     UNTIL      DO          UNLESS
        WHEN      CASE
        END       RETURN

        COMMA     COLON      SEMICOLON   DOT
        LPAREN    RPAREN     LBRACK      RBRACK    LBRACE    RBRACE

        ASSIGN    PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN
        ANDASSIGN ORASSIGN

        PLUS      MINUS      TIMES       DIVIDE
        UMINUS
        EQ        NEQ        LT          LE        GT        GE
        AND       OR         NOT

        ARRAY
        DEF       UNDEF
        PRINT

%union {
    cmp::Statement      *stm;
    cmp::Expression     *exp;
    cmp::IdExpression   *idexp;
    cmp::ExpressionList *expli;

    char     string[100];
    int32_t  integer;
    double   real;
    bool     boolean;
}

%type <stm>   ROOT statement ifstm whenstm stmseq
%type <idexp> designator
%type <exp>   expression expr2 expr3 expr4
%type <expli> expressionlist argumentlist

%type <string>  ID STRING
%type <integer> INTEGER
%type <real>    REAL
%type <boolean> BOOLEAN

%left LT GT EQ NEQ LE GE
%left PLUS MINUS
%left TIMES DIVIDE

%%

ROOT:
    stmseq { utils::Logger::Success("BISON: done!"); }
;

statement:
      designator ASSIGN expression
                                { $$ = new cmp::AssignStatement($1, $3); }
    | PRINT LPAREN expressionlist RPAREN
                                { $$ = new cmp::PrintStatement($3); }

    | IF expression THEN stmseq ifstm
                                { $$ = new cmp::IfStatement($2, $4, $5); }

    | WHILE expression DO stmseq END
                                { $$ = new cmp::WhileStatement($2, $4); }
    | UNTIL expression DO stmseq END
                                { $$ = new cmp::UntilStatement($2, $4); }

    | UNLESS expression THEN stmseq END
                                { $$ = new cmp::UnlessStatement($2, $4); }
    | UNLESS expression THEN stmseq ELSE stmseq END
                                { $$ = new cmp::UnlessStatement($2, $4, $6); }

    | CASE expression WHEN expression THEN stmseq whenstm
                                { $$ = new cmp::CaseStatement($2,
                                                              new cmp::WhenStatement($4, $6, $7));
                                }

    | DEF designator LPAREN argumentlist RPAREN stmseq END
                                { $$ = new cmp::FunctionStatement($2, $4, $6); }
    | DEF designator LPAREN RPAREN stmseq END
                                { $$ = new cmp::FunctionStatement($2, $5); }

    | RETURN expression         { $$ = new cmp::ReturnStatement($2); }
    ;

ifstm:
      ELSIF expression THEN stmseq ifstm
                                { $$ = new cmp::IfStatement($2, $4, $5); }
    | ELSE stmseq END           { $$ = $2; }
    | END                       { $$ == nullptr; }
    ;

whenstm:
      WHEN expression THEN stmseq whenstm
                                { $$ = new cmp::WhenStatement($2, $4, $5); }
    | ELSE stmseq END
                                { $$ = new cmp::WhenStatement(nullptr, $2); }
    | END                       { $$ = nullptr; }
    ;

stmseq:
      stmseq SEMICOLON statement
                                { $$ = new cmp::CompoundStatement($1, $3); }
    | statement                 { $$ = $1; }
    ;

expression:
      expr2                     { $$ = $1; }
    | expr2 EQ expr2            { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::EQ,  $3); }
    | expr2 NEQ expr2           { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::NEQ, $3); }
    | expr2 LT expr2            { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::LT,  $3); }
    | expr2 LE expr2            { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::LE,  $3); }
    | expr2 GT expr2            { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::GT,  $3); }
    | expr2 GE expr2            { $$ = new cmp::BinCompareExpression($1, cmp::BinCompare::GE,  $3); }
    ;

argumentlist:
      designator COMMA argumentlist
                                { $$ = new cmp::PairExpressionList($1, $3); }
    | designator                { $$ = new cmp::LastExpressionList($1); }
    ;

expressionlist:
      expression COMMA expressionlist
                                { $$ = new cmp::PairExpressionList($1, $3); }
    | expression                { $$ = new cmp::LastExpressionList($1); }
    ;

expr2:
      expr3                     { $$ == $1; }
    | expr2 PLUS expr3          { $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Plus, $3); }
    | expr2 MINUS expr3         { $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Minus, $3); }
    ;

expr3:
      expr4                     { $$ = $1; }
    | expr3 TIMES expr4         { $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Times, $3); }
    | expr3 DIVIDE expr4        { $$ = new cmp::BinOperandExpression($1, cmp::BinaryOperand::Div, $3); }
    ;

expr4:
      PLUS expr4                { $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Plus, $2); }
    | MINUS expr4               { $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Minus, $2); }
    | NOT expr4                 { $$ = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Not, $2); }
    | LPAREN expression RPAREN  { $$ = $2; }
    | LPAREN statement COMMA expression RPAREN
                                { $$ = new cmp::ExpseqExpression($2, $4); }
    | designator LPAREN expressionlist RPAREN
                                { $$ = new cmp::FunctionExpression($1, $3); }
    | INTEGER                   { $$ = new cmp::ValueExpression($1); }
    | REAL                      { $$ = new cmp::ValueExpression($1); }
    | BOOLEAN                   { $$ = new cmp::ValueExpression($1); }
    | designator                { $$ = $1; }
    ;

designator:
    ID                          { $$ = new cmp::IdExpression($1); }
    ;
