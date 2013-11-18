#include <stdlib.h>
#include <string.h>

/* This is where you put #include directives as needed for later labs. */
#include "scanner.hh"


int column = 0;

extern YYLTYPE yylloc;

%}

%option yylineno
%option 8bit
%option noyywrap
%option caseless
%option nodefault
%option outfile = "scanner.cc"

%%

DIGIT [0-9]
LETTER [_a-zA-Z]


{DIGIT} {
	printf("digit");
}

{LETTER} {
	printf("letter");
}

. {
	printf("other");
}


%%
