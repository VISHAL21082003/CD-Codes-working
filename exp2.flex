%{
int count = 0;
%}

%%
[0-9]+ {printf("%s is a digit\n", yytext);}
[A-Z] {printf("%s capital letter\n", yytext); count++; }
.* {printf("%s not a capital letter\n", yytext);}
%%

void main()
{
yylex();
printf("\nNumber of Capital letters in the given input - %d\n", count);
}

int yywrap(){}
