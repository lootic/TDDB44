%{

#include <stdlib.h>
#include <string.h>

/* This is where you put #include directives as needed for later labs. */
#include "scanner.hh"

// Note that the order is important
// include ast.hh
// include parser.hh

int column = 0;

extern YYLTYPE yylloc; // Used for position information, see below.


//my function, we have it here for convinience

%}

%option yylineno
%option 8bit
%option noyywrap
%option caseless
%option nodefault
%option outfile = "scanner.cc"
/* Your code here.
 * If you want to include any flex declarations, this is where to do it. */
%x c_comment
DIGIT [0-9]
/* {DIGIT}+"."{DIGIT}*/
LETTER [_a-zA-Z]
ID [_a-zA-Z][_a-zA-Z0-9]*
/* Position information is entered into the yylloc variable, so we will be
   able to generate good error messages later in later phases. */
/* Your code should be entered below the %%. Expressions to handle the 
   following: Diesel comments, Diesel string constants, Diesel 
   identifiers, integers, reals, and whitespace. */
%%

{
	"}"	{
		column += 2;
		BEGIN(INITIAL);
	}
    "{"	{
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

"('[^']*')*" {
	return T_STRINGCONST;
}

"[0-9]+" {
	return T_INTNUM;
}

"([0-9]+\.?|\.[0-9]+)[0-9]*(e|E)-?[0-9]+" {
	return T_REALNUM;
}

\.				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_DOT;
				}

;				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_SEMICOLON;
				}
=				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_EQ;			    
				}
\:				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_COLON; 
				}
\(				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_LEFTPAR;
				}
\)				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_RIGHTPAR;
				}
\[				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_LEFTBRACKET;   
				}
\]				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_RIGHTBRACKET;    
				}
,				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_COMMA;
				    
				}
\<				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_LESSTHAN;
				}
\>				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_GREATERTHAN;
				}
\+				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_ADD;				    
				}
\-				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_SUB;	
				}
\*				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_MUL;	
				}
\/				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_RDIV;	
				}
":="				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_ASSIGN;	
				}
"<>"				{yylloc.first_line=yylineno;
 				 yylloc.first_column=column;
                         column += yyleng;
                         return T_NOTEQ;	
				}
of {
	return T_OF;
}

if {
	return(T_IF);			    
}

do {
	return T_DO;
}

or {
	return T_OR;
}

var {
	return T_VAR;
}

end {
	return T_END;				    
}

and {
	return T_AND;				    
}

div	{    
	return T_IDIV;
}

mod	{
	return T_MOD;
}

not {
	return T_NOT;
}

then {
	return T_THEN;
}

else {
	return T_ELSE;
}

const {
	return T_CONST;
}

array {
	return T_ARRAY;
}

begin {
	return T_BEGIN;				    
}

while {
	return T_WHILE;
}

elsif {
	return T_ELSIF;
}

return {
	return T_RETURN;
}

program {
	return T_PROGRAM;
}

function {
	return T_FUNCTION;
}

procedure {
	return T_PROCEDURE;
}

"[\n \t]+" {
}

"([^']|'')*" {
}

"[a-Z_][0-9a-Z_]*" {
	printf("hello");
	return T_IDENT;
}

{LETTER} {
	yylloc.first_line=yylineno;
 	yylloc.first_column=column;
    column += yyleng;
}

{DIGIT} {
	yylloc.first_line=yylineno;
 	yylloc.first_column=column;
    column += yyleng;
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

. {
	yyerror("Illegal character");
}


%%
