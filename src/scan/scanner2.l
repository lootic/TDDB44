%{
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* This is where you put #include directives as needed for later labs. */
#include "scanner.hh"


int column = 0;
int row = 0;

static void updatePosition() {
	yylloc.first_line=yylineno;
	yylloc.first_column=column;
	column += yyleng;
}

extern YYLTYPE yylloc;

%}

%option yylineno
%option 8bit
%option noyywrap
%option caseless
%option nodefault
%option outfile = "scanner.cc"

%x c_comment

DIGIT [0-9]
INTEGER [0-9]+
LETTER [_a-zA-Z]
FLOAT ([0-9]+\.?[0-9]*)|(\.[0-9]+)
EXPONENT [eE]-?[0-9]+
REAL ({FLOAT}{EXPONENT}?)|{INTEGER}{EXPONENT}
WHITESPACE [\t ]
ID {LETTER}({LETTER}|{DIGIT})*
PASCALCOMMENT \{[^\}]*\}
STRING '([^']|'')*'

%%

; {
	updatePosition();
	return T_SEMICOLON;
}

= {
	updatePosition();
	return T_EQ;
}

\: {
	updatePosition();
	return T_COLON;
}

\( {
	updatePosition();
	return T_LEFTPAR;
}

\) {
	updatePosition();
	return T_RIGHTPAR;
}

\[ {
	updatePosition();
	return T_LEFTBRACKET;
}

\] {
	updatePosition();
	return T_RIGHTBRACKET;
}

, {
	updatePosition();
	return T_COMMA;
}

\< {
	updatePosition();
	return T_LESSTHAN;
}

\> {
	updatePosition();
	return T_GREATERTHAN;
}

\+ {
	updatePosition();
	return T_ADD;
}

- {
	updatePosition();
	return T_SUB;	
}

\* {
	updatePosition();
	return T_MUL;
}

\/ {
	updatePosition();
	return T_RDIV;
}

\. {
	updatePosition();	
	return T_DOT;
}

\:= {
	updatePosition();
	return T_ASSIGN;
}
\<\> {
	updatePosition();
	return T_NOTEQ;
}

or {
	updatePosition();
	return T_OR;
}

var {
	updatePosition();
	return T_VAR;
}

end {
	updatePosition();
	return T_END;
}

and {
	updatePosition();
	return T_AND;
}

div {
	updatePosition();
	return T_IDIV;
}

mod {
	updatePosition();
	return T_MOD;
}

not {
	updatePosition();
	return T_NOT;
}

then {
	updatePosition();
	return T_THEN;
}

else {
	updatePosition();
	return T_ELSE;
}

const {
	updatePosition();
	return T_CONST;
}

array {
	updatePosition();
	return T_ARRAY;
}

begin {
	updatePosition();
	return T_BEGIN;
}

while {
	updatePosition();
	return T_WHILE;
}

elsif {
	updatePosition();
	return T_ELSIF;
}

return {
	updatePosition();
	return T_RETURN;
}

program  {
	updatePosition();
	return T_PROGRAM;
}

function {
	updatePosition();
	return T_FUNCTION;
}

procedure {
	updatePosition();
	return T_PROCEDURE;
}

of {
	updatePosition();
	return T_OF;
}

if {
	updatePosition();
	return T_IF;
}

do {
	updatePosition();
	return T_DO;
}

{PASCALCOMMENT} {
	updatePosition();
}

{STRING} {
	yylval.str = sym_tab->pool_install(sym_tab->fix_string(yytext));
	return T_STRINGCONST;
}

{WHITESPACE} {
	updatePosition();
}

{ID} {
	updatePosition();
	yylval.pool_p = sym_tab->pool_install(sym_tab->capitalize(yytext));
	return T_IDENT;
}

{INTEGER} {
	updatePosition();
	yylval.ival = atoi(yytext);
	return T_INTNUM;
}

{REAL} {
	updatePosition();
	float floatPart = atof(strtok(sym_tab->capitalize(yytext), "E"));
	float exponentPart = 1;
	if(strchr(sym_tab->capitalize(yytext), 'E') != NULL) {
		exponentPart = pow(10, atoi(strtok(NULL, "E")));
	}
	yylval.rval = floatPart*exponentPart;	
	
	return T_REALNUM;
}

\n {
	column = 0;
	yylloc.first_column=column;
	yylloc.first_line=yylineno;
}

. {
	yyerror("Illegal character");
}

\/\/.*$	column = 0; /* Skip single-line comment */
"/\*"	{
	column += yyleng;
	BEGIN(c_comment);
}

<c_comment>
{
	"\*/"	{
		column += 2;
		BEGIN(INITIAL);
	}
    "/\*"	{
		column += 2;
		yyerror("Suspicious comment");
	}
	[^\n]	column++; /* Skip stuff in comments */
    \n		column = 0; 
    <<EOF>>	{
		yyerror("Unterminated comment");
		yyterminate();
	}
}

<<EOF>> {
	yyterminate();
}

%%
