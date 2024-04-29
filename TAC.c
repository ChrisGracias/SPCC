#include <stdio.h>
#include <stdlib.h>
void assignment_TAC(char *result, char *arg1){
    printf("%s = %s\n",result,arg1);
}

void aritmetic_TAC(char *result, char *arg1, char operator,char* arg2){
    printf("%s = %s %c %s\n",result,arg1,operator,arg2);
}

void relational_TAC(char *result, char *arg1, char operator, char* arg2){
    printf("%s = %s %c %s\n",result,arg1,operator,arg2);
}

int main(){
    assignment_TAC("X", "5");
    aritmetic_TAC("temp1","X",'+',"3");
    relational_TAC("temp2","temp1",'>',"10");
    return 0;
}