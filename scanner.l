%{
#include "parser.tab.h"
#include "ast.h"
%}

%option noyywrap

digito    [0-9]
letra     [a-zA-Z]
id        {letra}({letra}|{digito})*

%%

"entero"       { return ENTERO; }
"flotante"     { return FLOTANTE; }
"cadena"       { return CADENA; }
"si"           { return SI; }
"sino"         { return SINO; }
"mientras"     { return MIENTRAS; }
"imprimirKeye"     { return IMPRIMIR; }
"leer"         { return LEER; }
"potencia"     { return POTENCIA; }

"+"            { return '+'; }
"-"            { return '-'; }
"*"            { return '*'; }
"/"            { return '/'; }
"="            { return '='; }
"^"            { return '^'; }
","            { return ','; }
";"            { return ';'; }
"("            { return '('; }
")"            { return ')'; }
"{"            { return '{'; }
"}"            { return '}'; }

{digito}+      { yylval.entero = atoi(yytext); return ENTERO_LIT; }
{digito}+"."{digito}*  { yylval.flotante = atof(yytext); return FLOTANTE_LIT; }
{id}           { yylval.cadena = strdup(yytext); return ID; }

[ \t\n]        ; 
.              { printf("Error léxico: %s\n", yytext); }

%%