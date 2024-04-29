%{
int operator_count = 0;
int operand_count=0;
%}

%% rules for operator and operand
[+\-*/%^=] { operator_count++};
[a-zA-Z0-9]+ {operand_count++};
%%

int main(){
    yylex();
    print("Operators: %d\n Operands: %d\n",operator_count,operand_count);
    return 0;
}

%% rules for newline space and words
\n {newline++};
[\t] {space++};
[^ \t\n]+ {word++};
%%

%% rules for identifiers, constants and special symbols
[a-zA-Z][a-zA-Z0-9]* {identifiers++}
[0-9]+ {constants++}
[+/-*\%^=] {operator++}
{^a-zA-Z0-9 \t\n} {special++}
%%

%%rules for vowels and consonants
[a-zA-Z]{
    if(strchr("aeiouAEIOU",yytext[0])){
        vowel_count++;
}
else{
    consonants++
}
}

%%rules for positive and negative integers
[0-9]+ {positive_integer}
-?[0-9]+ {negative++}
[0-9]+/[0-9]+ {fraction ++}