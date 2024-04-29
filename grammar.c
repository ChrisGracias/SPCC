#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void procE(char str[]);
void procEdash(char str[]);
void procT(char str[]);
void procTdash(char str[]);
void procF(char str[]);
int i = 0;

void procEdash(char str[]){
    if(str[i] == '+'){
        i++;
        procT(str);
        procEdash(str);
    }
}

void procTdash(char str[]){
    if(str[i] == '*'){
        i++;
        procF(str);
        procTdash(str);
    }
}
void procF(char str[]){
    if(str[i]=='('){
        i++;
        procE(str);
        if(str[i]==')'){
            i++;
        }
        else{
            printf("Error");
        }
    }
    else if (str[i] == 'i') {
        i++;
    }
    
    else{
        printf("error");
    }
}

void procE(char str[]){
    procT(str);
    procEdash(str);
}

void procT(char str[]){
    procF(str);
    procTdash(str);
}

int main(){
    char str[] = "i+i*i";
    procE(str);
    if(i == strlen(str)){
        printf("Parsing successfully\n");
    }
    else{
        printf("Parsing failed\n");
    }
    return 0;
}
