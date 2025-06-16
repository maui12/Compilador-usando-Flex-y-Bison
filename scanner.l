%{
#include "parser.tab.h"
#include "ast.h"
#include <string.h>
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
"imprimir"     { return IMPRIMIR; }
"leer"         { return LEER; }

"=="           { return IGUAL; }
"!="           { return NO_IGUAL; }
"<"            { return MENOR; }
">"            { return MAYOR; }
"<="           { return MENOR_IGUAL; }
">="           { return MAYOR_IGUAL; }

"+"            { return '+'; }
"-"            { return '-'; }
"*"            { return '*'; }
"/"            { return '/'; }
"="            { return '='; }
";"            { return ';'; }
"("            { return '('; }
")"            { return ')'; }
"{"            { return '{'; }
"}"            { return '}'; }

{digito}+      { yylval.entero = atoi(yytext); return ENTERO_LIT; }
{digito}+"."{digito}*  { yylval.flotante = atof(yytext); return FLOTANTE_LIT; }
\"[^"]*\"      { yylval.cadena = strdup(yytext); return CADENA_LIT; }
{id}           { yylval.cadena = strdup(yytext); return ID; }

[ \t\n]        ; /* Ignorar espacios */
.              { printf("Error léxico: caracter '%s' no reconocido\n", yytext); }

%%