%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "parser.tab.h"

/* For Windows compatibility, as unistd.h is not available */
#define YY_NO_UNISTD_H 1

int line_count = 1;
int comment_start_line = 0;

char string_buffer[4096];
char *string_buffer_ptr;

typedef struct Symbol {
    char *name;
    struct Symbol *next;
} Symbol;

Symbol *symbol_table_head = NULL;

void add_to_symbol_table(const char *name);
void print_symbol_table(void);
void free_symbol_table(void);

void print_token(int line, const char *token_type, const char *text) {
    printf("L%-4d %-25s : %s\n", line, token_type, text);
}

void print_error(int line, const char *error_type, const char *text) {
    fprintf(stderr, "Error on line %d: %s %s\n", line, error_type, text);
}

// forward declaration for the parser
void yyerror(const char *s);

int yywrap(void);
%}

%option caseless
%x IN_COMMENT
%x IN_STRING

ID      [a-zA-Z$#@_][a-zA-Z0-9$#@_]*

INT_CONST      [0-9]+

BIN_CONST [01]+[Bb]

EXP             [eE][+-]?[0-9]+
FLOAT_CONST     ([0-9]*\.[0-9]+|[0-9]+\.){EXP}?|[0-9]+{EXP}
CPLX_CONST      ({FLOAT_CONST}|[0-9]+)[iI]

CHAR_CONST      '\'([^\'\\]|\\.)\''

%%
\n                   { line_count++; } // Increment line counter
[ \t\r]+             ;   // skip other whitespace

"/*"                 { comment_start_line = line_count; BEGIN(IN_COMMENT); }
<IN_COMMENT>{
"*/"                 { BEGIN(INITIAL); }
\n                   { line_count++; }
[^*\n]+              {  }
"*"                  {  }
<<EOF>>              { print_error(comment_start_line,
                                   "Unterminated comment starting on line", "");
                       exit(0); }
}

\'[01]*\'[Bb]                    { yylval.str = strdup(yytext); return BIT_STRING; }
\'[0-9A-Fa-f]*\'[Xx]             { yylval.str = strdup(yytext); return HEX_STRING; }

\'           { 
    string_buffer_ptr = string_buffer; 
    *string_buffer_ptr++ = '\''; 
    *string_buffer_ptr = '\0'; 
    BEGIN(IN_STRING); 
}
<IN_STRING>{
\'           { *string_buffer_ptr++ = '\'';  *string_buffer_ptr = '\0';
               BEGIN(INITIAL);
               yylval.str = strdup(string_buffer);
               return STRING_LITERAL; }

([^\\\'\n]+) { strcpy(string_buffer_ptr, yytext); string_buffer_ptr += yyleng; }
\'\'         { strcpy(string_buffer_ptr, yytext); string_buffer_ptr += yyleng; }
(\\[^\'])   { strcpy(string_buffer_ptr, yytext); string_buffer_ptr += yyleng; }
\n          { print_error(line_count, "Unterminated string literal", ""); line_count++; BEGIN(INITIAL); }
<<EOF>>     { print_error(line_count, "Unterminated string literal at end of file", ""); exit(1); }
}


"%"[^\n]*           ;

","                  { return ','; }
"."                  { return '.'; }
";"                  { return ';'; }
":"                  { return ':'; }
"("                  { return '('; }
")"                  { return ')'; }
"->"                 { return ARROW; }
"=>"                 { return ARROW; }


"+"                  { return '+'; }
"-"                  { return '-'; }
"**"                 { return OP_EXPONENT; }
"*"                  { return '*'; }
"/"                  { return '/'; }

"¬="                 { return OP_NE; }
"<>"                 { return OP_NE; }
"¬<"                 { return OP_NLT; }
"¬>"                 { return OP_NGT; }
"<="                 { return OP_LE; }
">="                 { return OP_GE; }
"="                  { return '='; }
"<"                  { return '<'; }
">"                  { return '>'; }

"||"                 { return OP_CONCAT; }

"¬"                  { return OP_NOT; }
"&"                  { return '&'; }
"|"                  { return '|'; }


{INT_CONST}          { yylval.str = strdup(yytext); return INT_CONST; }
{FLOAT_CONST}        { yylval.str = strdup(yytext); return FLOAT_CONST; }
{CHAR_CONST}         { yylval.str = strdup(yytext); return CHAR_CONST; }
{BIN_CONST}     { yylval.str = strdup(yytext); return BIN_CONST; }
{CPLX_CONST}    { yylval.str = strdup(yytext); return COMPLEX_CONST; }
[0-9]+{ID}           { yyerror("Invalid identifier or number"); }

"declare"|"dcl"             { return KEYWORD_DECLARE; }
"procedure"|"proc"          { return KEYWORD_PROCEDURE; }
"options"                   { return KEYWORD_OPTIONS; }
"main"                      { return KEYWORD_MAIN; }
"recursive"                 { return KEYWORD_RECURSIVE; }
"returns"                   { return KEYWORD_RETURNS; }
"return"                    { return KEYWORD_RETURN; }
"call"                      { return KEYWORD_CALL; }
"end"                       { return KEYWORD_END; }

"fixed"                     { return KEYWORD_FIXED; }
"float"                     { return KEYWORD_FLOAT; }
"binary"|"bin"              { return KEYWORD_BINARY; }
"decimal"|"dec"             { return KEYWORD_DECIMAL; }
"bit"                       { return KEYWORD_BIT; }
"character"|"char"          { return KEYWORD_CHARACTER; }
"complex"                   { return KEYWORD_COMPLEX; }
"pointer"                   { return KEYWORD_POINTER; }
"varying"                   { return KEYWORD_VARYING; }
"initial"|"init"            { return KEYWORD_INITIAL; }

"if"                        { return KEYWORD_IF; }
"then"                      { return KEYWORD_THEN; }
"else"                      { return KEYWORD_ELSE; }
"do"                        { return KEYWORD_DO; }
"while"                     { return KEYWORD_WHILE; }
"until"                     { return KEYWORD_UNTIL; }
"to"                        { return KEYWORD_TO; }
"by"                        { return KEYWORD_BY; }
"leave"                     { return KEYWORD_LEAVE; }
"iterate"                   { return KEYWORD_ITERATE; }
"select"                    { return KEYWORD_SELECT; }
"when"                      { return KEYWORD_WHEN; }
"otherwise"                 { return KEYWORD_OTHERWISE; }
"go"                        { return KEYWORD_GO; }
"goto"                      { return KEYWORD_GOTO; }

"put"                       { return KEYWORD_PUT; }
"get"                       { return KEYWORD_GET; }
"skip"                      { return KEYWORD_SKIP; }
"list"                      { return KEYWORD_LIST; }
"edit"                      { return KEYWORD_EDIT; }

{ID}                 { 
                        add_to_symbol_table(yytext); 
                        yylval.str = strdup(yytext); return IDENTIFIER; 
                     }



.                    { yyerror("Unknown character"); }
%%

void add_to_symbol_table(const char *name) {
    
    char *upper = strdup(name);
    if (!upper) {
        perror("Failed to allocate memory for symbol");
        exit(1);
    }
    for (char *p = upper; *p; p++)
        *p = toupper((unsigned char)*p);

    
    Symbol *current = symbol_table_head;
    while (current != NULL) {
        if (strcmp(current->name, upper) == 0) {
            free(upper);
            return; 
        }
        current = current->next;
    }

    
    Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
    if (!new_symbol) {
        perror("Failed to allocate memory for symbol");
        exit(1);
    }
    new_symbol->name = upper;
    new_symbol->next = symbol_table_head;
    symbol_table_head = new_symbol;
}

void free_symbol_table(void) {
    Symbol *current = symbol_table_head;
    while (current) {
        Symbol *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    symbol_table_head = NULL;
}

void print_symbol_table(void) {
    printf("\n--- Symbol Table (Unique Identifiers) ---\n");
    Symbol *current = symbol_table_head;
    while (current != NULL) {
        printf("  %s\n", current->name);
        current = current->next;
    }
    printf("-----------------------------------------\n");
}

int yywrap(void) {
    return 1; // Signal that there are no more files to process
}
