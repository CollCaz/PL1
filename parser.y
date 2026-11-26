%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* AST Node Structure */
#include "ast.h"

/* Function Prototypes */
void free_symbol_table(void);

/* External declarations from the lexer */
extern int yylex();
extern int line_count;
extern char* yytext;
extern FILE* yyin;
void print_symbol_table(void);

void yyerror(const char *s);

/* Root of the AST */
ASTNode *ast_root = NULL;
%}

/* Yacc/Bison Union for semantic values */
%union {
    char *str;
    struct ASTNode *node;
}


%token <str> IDENTIFIER INT_CONST FLOAT_CONST CHAR_CONST BIN_CONST COMPLEX_CONST
%token <str> STRING_LITERAL BIT_STRING HEX_STRING

/* Keywords */
%token KEYWORD_DECLARE KEYWORD_PROCEDURE KEYWORD_OPTIONS KEYWORD_MAIN KEYWORD_RECURSIVE KEYWORD_RETURNS KEYWORD_RETURN KEYWORD_CALL KEYWORD_END
%token KEYWORD_FIXED KEYWORD_FLOAT KEYWORD_BINARY KEYWORD_DECIMAL KEYWORD_BIT KEYWORD_CHARACTER KEYWORD_COMPLEX KEYWORD_POINTER KEYWORD_VARYING KEYWORD_INITIAL
%token KEYWORD_IF KEYWORD_THEN KEYWORD_ELSE KEYWORD_DO KEYWORD_WHILE KEYWORD_UNTIL KEYWORD_TO KEYWORD_BY KEYWORD_LEAVE KEYWORD_ITERATE
%token KEYWORD_SELECT KEYWORD_WHEN KEYWORD_OTHERWISE KEYWORD_GO KEYWORD_GOTO KEYWORD_PUT KEYWORD_GET KEYWORD_SKIP KEYWORD_LIST KEYWORD_EDIT


%token OP_EXPONENT OP_CONCAT OP_NE OP_NLT OP_NGT OP_LE OP_GE ARROW OP_NOT

/* Type Definitions for grammar rules */
%type <node> program stmts stmt simple labels do_group select_stmt whens opt_other
%type <node> opt_params proc_opts decl_list decl attrs attr io_opts opt_id opt_by
%type <node> id_list expr_list ref base expr

%destructor { free($$); } <str>
%destructor { free_ast($$); } <node>
%destructor { } program

%nonassoc LOWER_THAN_ELSE
%nonassoc KEYWORD_ELSE


%left '|'
%left '&'
%left '=' '<' '>' OP_NE OP_LE OP_GE OP_NLT OP_NGT
%left OP_CONCAT
%left '+' '-'
%left '*' '/'
%right UMINUS
%right OP_EXPONENT

%%

/* Grammar Rules */

program
    : stmts {
        $$ = create_node("Program", NULL, 1, $1);
        ast_root = $$;
    }

stmts
    : /* empty */ { $$ = create_node("StatementList", NULL, 0); }
    | stmts stmt  { $$ = add_child($1, $2); }
    ;

stmt
    : labels simple { $$ = $1 ? create_node("LabeledStatement", NULL, 2, $1, $2) : $2; }
    ;

labels
    : /* empty */ { $$ = NULL; }
    | labels IDENTIFIER ':' {
        if (!$1) $1 = create_node("LabelList", NULL, 0);
        $$ = add_child($1, create_node("Label", $2, 0));
        free($2);
      }
    ;

simple
    : ref '=' expr ';'              { $$ = create_node("Assignment", "=", 2, $1, $3); }
    | KEYWORD_CALL ref ';'               { $$ = create_node("CallStatement", NULL, 1, $2); }
    | KEYWORD_RETURN ';'                 { $$ = create_node("Return", NULL, 0); }
    | KEYWORD_RETURN expr ';'            { $$ = create_node("Return", NULL, 1, $2); }
    | KEYWORD_GOTO IDENTIFIER ';'        { $$ = create_node("GotoStatement", $2, 0); free($2); }
    | KEYWORD_GO KEYWORD_TO IDENTIFIER ';'    { $$ = create_node("GotoStatement", $3, 0); free($3); }
    | KEYWORD_LEAVE opt_id ';'           { $$ = create_node("LeaveStatement", NULL, 1, $2); }
    | KEYWORD_ITERATE opt_id ';'         { $$ = create_node("IterateStatement", NULL, 1, $2); }
    | KEYWORD_IF expr KEYWORD_THEN stmt %prec LOWER_THAN_ELSE
                                    { $$ = create_node("IfStatement", NULL, 2, $2, $4); }
    | KEYWORD_IF expr KEYWORD_THEN stmt KEYWORD_ELSE stmt
                                    { $$ = create_node("IfElseStatement", NULL, 3, $2, $4, $6); }
    | do_group                      { $$ = $1; }
    | select_stmt                   { $$ = $1; }
    | KEYWORD_PROCEDURE opt_params proc_opts ';' stmts KEYWORD_END opt_id ';'
                                    { $$ = create_node("Procedure", NULL, 4, $2, $3, $5, $7); }
    | KEYWORD_DECLARE decl_list ';'      { $$ = create_node("Declaration", NULL, 1, $2); }
    | KEYWORD_PUT io_opts ';'            { $$ = create_node("PutStatement", NULL, 1, $2); }
    | KEYWORD_GET io_opts ';'            { $$ = create_node("GetStatement", NULL, 1, $2); }
    | ';'                           { $$ = create_node("EmptyStatement", ";", 0); }
    ;

do_group
    : KEYWORD_DO ';' stmts KEYWORD_END opt_id ';'
        { $$ = create_node("DoStatement", NULL, 1, $3); free_ast($5); }
    | KEYWORD_DO KEYWORD_WHILE '(' expr ')' ';' stmts KEYWORD_END opt_id ';'
        { $$ = create_node("DoWhileStatement", NULL, 2, $4, $7); free_ast($9); }
    | KEYWORD_DO KEYWORD_UNTIL '(' expr ')' ';' stmts KEYWORD_END opt_id ';'
        { $$ = create_node("DoUntilStatement", NULL, 2, $4, $7); free_ast($9); }
    | KEYWORD_DO ref '=' expr KEYWORD_TO expr opt_by ';' stmts KEYWORD_END opt_id ';'
        { $$ = create_node("DoToStatement", NULL, 5, $2, $4, $6, $7, $9); free_ast($11); }
    ;

opt_by
    : /* empty */ { $$ = NULL; }
    | KEYWORD_BY expr  { $$ = create_node("ByClause", NULL, 1, $2); }
    ;

select_stmt
    : KEYWORD_SELECT ';' whens opt_other KEYWORD_END ';'
        { $$ = create_node("SelectStatement", NULL, 3, NULL, $3, $4); }
    | KEYWORD_SELECT '(' expr ')' ';' whens opt_other KEYWORD_END ';'
        { $$ = create_node("SelectStatement", NULL, 3, $3, $6, $7); }
    ;

whens
    : /* empty */ { $$ = create_node("WhenList", NULL, 0); }
    | whens KEYWORD_WHEN '(' expr_list ')' stmt
        { $$ = add_child($1, create_node("WhenClause", NULL, 2, $4, $6)); }
    ;

opt_other
    : /* empty */         { $$ = NULL; }
    | KEYWORD_OTHERWISE stmt   { $$ = create_node("OtherwiseClause", NULL, 1, $2); }
    ;

opt_params
    : /* empty */         { $$ = NULL; }
    | '(' id_list ')'     { $$ = create_node("ParameterList", NULL, 1, $2); }
    ;

proc_opts
    : /* empty */ { $$ = create_node("OptionList", NULL, 0); }
    | proc_opts KEYWORD_OPTIONS '(' KEYWORD_MAIN ')'
        { $$ = add_child($1, create_node("Option", "MAIN", 0)); }
    | proc_opts KEYWORD_RECURSIVE
        { $$ = add_child($1, create_node("Option", "RECURSIVE", 0)); }
    | proc_opts KEYWORD_RETURNS '(' attrs ')'
        { $$ = add_child($1, create_node("ReturnsClause", NULL, 1, $4)); }
    ;

decl_list
    : decl                  { $$ = add_child(create_node("DeclaratorList", NULL, 0), $1); }
    | decl_list ',' decl    { $$ = add_child($1, $3); }
    ;

decl
    : IDENTIFIER attrs
        { $$ = create_node("Declarator", $1, 1, $2); free($1); }
    | '(' id_list ')' attrs
        { $$ = create_node("DeclaratorGroup", NULL, 2, $2, $4); }
    | INT_CONST IDENTIFIER attrs
        { $$ = create_node("Declarator", $2, 2, create_node("Level", $1, 0), $3); free($2); free($1); }
    | INT_CONST '(' id_list ')' attrs
        { $$ = create_node("DeclaratorGroup", NULL, 3, create_node("Level", $1, 0), $3, $5); free($1); }
    ;

attrs
    : /* empty */ { $$ = create_node("AttributeList", NULL, 0); }
    | attrs attr  { $$ = add_child($1, $2); }
    ;

attr
    : KEYWORD_FIXED      { $$ = create_node("Attribute", "FIXED", 0); }
    | KEYWORD_FLOAT      { $$ = create_node("Attribute", "FLOAT", 0); }
    | KEYWORD_BINARY     { $$ = create_node("Attribute", "BINARY", 0); }
    | KEYWORD_DECIMAL    { $$ = create_node("Attribute", "DECIMAL", 0); }
    | KEYWORD_COMPLEX    { $$ = create_node("Attribute", "COMPLEX", 0); }
    | KEYWORD_POINTER    { $$ = create_node("Attribute", "POINTER", 0); }
    | KEYWORD_VARYING    { $$ = create_node("Attribute", "VARYING", 0); }
    | KEYWORD_BIT        { $$ = create_node("Attribute", "BIT", 0); }
    | KEYWORD_CHARACTER  { $$ = create_node("Attribute", "CHARACTER", 0); }
    | KEYWORD_INITIAL '(' expr_list ')' { $$ = create_node("Initial", NULL, 1, $3); }
    | '(' expr_list ')'            { $$ = create_node("SizeOrDimensions", NULL, 1, $2); }
    ;

io_opts
    : /* empty */ { $$ = create_node("IoOptionList", NULL, 0); }
    | io_opts KEYWORD_SKIP
        { $$ = add_child($1, create_node("Skip", NULL, 0)); }
    | io_opts KEYWORD_SKIP '(' expr ')'
        { $$ = add_child($1, create_node("Skip", NULL, 1, $4)); }
    | io_opts KEYWORD_LIST '(' expr_list ')'
        { $$ = add_child($1, create_node("List", NULL, 1, $4)); }
    | io_opts KEYWORD_EDIT '(' expr_list ')' '(' expr_list ')'
        { $$ = add_child($1, create_node("Edit", NULL, 2, $4, $7)); }
    ;

opt_id
    : /* empty */ { $$ = NULL; }
    | IDENTIFIER  { $$ = create_node("Identifier", $1, 0); free($1); }
    ;

id_list
    : IDENTIFIER
        { $$ = add_child(create_node("IdentifierList", NULL, 0), create_node("Identifier", $1, 0)); free($1); }
    | id_list ',' IDENTIFIER
        { $$ = add_child($1, create_node("Identifier", $3, 0)); free($3); }
    ;

expr_list
    : expr
        { $$ = add_child(create_node("ExpressionList", NULL, 0), $1); }
    | expr_list ',' expr
        { $$ = add_child($1, $3); }
    ;

ref
    : base                { $$ = $1; }
    | ref '.' base        { $$ = create_node("MemberAccess", NULL, 2, $1, $3); }
    | ref ARROW base      { $$ = create_node("PointerAccess", NULL, 2, $1, $3); }
    ;

base
    : IDENTIFIER          { $$ = create_node("Identifier", $1, 0); free($1); }
    | IDENTIFIER '(' expr_list ')'
        { $$ = create_node("CallOrSubscript", $1, 1, $3); free($1); }
    ;

expr
    : expr '+' expr       { $$ = create_node("BinaryOp", "+", 2, $1, $3); }
    | expr '-' expr       { $$ = create_node("BinaryOp", "-", 2, $1, $3); }
    | expr '*' expr       { $$ = create_node("BinaryOp", "*", 2, $1, $3); }
    | expr '/' expr       { $$ = create_node("BinaryOp", "/", 2, $1, $3); }
    | expr OP_EXPONENT expr     { $$ = create_node("BinaryOp", "**", 2, $1, $3); }
    | expr OP_CONCAT expr    { $$ = create_node("BinaryOp", "||", 2, $1, $3); }
    | expr '=' expr       { $$ = create_node("BinaryOp", "=", 2, $1, $3); }
    | expr '<' expr       { $$ = create_node("BinaryOp", "<", 2, $1, $3); }
    | expr '>' expr       { $$ = create_node("BinaryOp", ">", 2, $1, $3); }
    | expr OP_NE expr        { $$ = create_node("BinaryOp", "NE", 2, $1, $3); }
    | expr OP_LE expr        { $$ = create_node("BinaryOp", "<=", 2, $1, $3); }
    | expr OP_GE expr        { $$ = create_node("BinaryOp", ">=", 2, $1, $3); }
    | expr OP_NLT expr       { $$ = create_node("BinaryOp", "NLT", 2, $1, $3); }
    | expr OP_NGT expr       { $$ = create_node("BinaryOp", "NGT", 2, $1, $3); }
    | expr '&' expr       { $$ = create_node("BinaryOp", "&", 2, $1, $3); }
    | expr '|' expr       { $$ = create_node("BinaryOp", "|", 2, $1, $3); }
    | '-' expr %prec UMINUS { $$ = create_node("UnaryOp", "-", 1, $2); }
    | '+' expr %prec UMINUS { $$ = create_node("UnaryOp", "+", 1, $2); }
    | OP_NOT expr %prec UMINUS { $$ = create_node("UnaryOp", "NOT", 1, $2); }
    | '(' expr ')'        { $$ = $2; }
    | ref                 { $$ = $1; }
    | INT_CONST           { $$ = create_node("IntConstant", $1, 0); free($1); }
    | FLOAT_CONST         { $$ = create_node("FloatConstant", $1, 0); free($1); }
    | CHAR_CONST          { $$ = create_node("CharConstant", $1, 0); free($1); }
    | STRING_LITERAL      { $$ = create_node("StringLiteral", $1, 0); free($1); }
    | BIT_STRING          { $$ = create_node("BitString", $1, 0); free($1); }
    | HEX_STRING          { $$ = create_node("HexString", $1, 0); free($1); }
    | BIN_CONST           { $$ = create_node("BinaryConstant", $1, 0); free($1); }
    | COMPLEX_CONST       { $$ = create_node("ComplexConstant", $1, 0); free($1); }
    ;

%%

/* C Code Section */










void yyerror(const char *s) {
    fprintf(stderr, "Parse error on line %d near '%s': %s\n", line_count, yytext, s);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile.pli>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Cannot open input file");
        return 1;
    }

    yyin = file;
    int result = yyparse();
    fclose(file);

    if (result == 0 && ast_root) {
        printf("\n--- Abstract Syntax Tree ---\n");
        print_ast(ast_root, 0);
        printf("----------------------------\n");
        free_ast(ast_root);
    } else {
        printf("Parsing failed, no AST generated.\n");
    }
    print_symbol_table();
    free_symbol_table();

    printf("\n----------------------------------\n");
    printf("Total lines processed: %d\n", line_count);
    return result;
}
