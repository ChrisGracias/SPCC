#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool ifKeyword(char word[10]) {
    if (!strcmp("auto", word) || !strcmp("goto", word) || !strcmp("int", word) || !strcmp("return", word) || !strcmp("loop", word)) {
        return true;
    } else {
        return false;
    }
}

bool ifOperator(char word[10]) {
    if (!strcmp("+", word) || !strcmp("-", word) || !strcmp("*", word) || !strcmp("/", word)) {
        return true;
    } else {
        return false;
    }
}

bool ifSpecialSymbol(char word[]) {
    if (!strcmp("[", word) || !strcmp("]", word) || !strcmp("{", word) || !strcmp("}", word) ||
        !strcmp(",", word) || !strcmp(";", word) || !strcmp(":", word) || !strcmp("(", word) ||
        !strcmp(")", word)) {
        return true;
    }
    return false;
}

bool ifConst(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isdigit(word[i])) {
            return false;
        }
    }
    return true;
}

bool isLiteral(char word[]) {
    int len = strlen(word);
    if (len >= 2 && ((word[0] == '"' && word[len - 1] == '"') || (word[0] == '\'' && word[len - 1] == '\''))) {
        return true;
    }
    return false;
}

int main() {
    char word[80];
    char file_name[80] = "path/to/your/file.txt"; // Provide the correct file path here
    FILE *in_file;
    in_file = fopen(file_name, "r");
    if (in_file == NULL) {
        printf("ERROR LOADING");
        return 1;
    } else {
        while (fscanf(in_file, "%s", word) != EOF) {
            if (ifKeyword(word)) {
                printf("%s is a keyword\n", word);
            } else if (ifOperator(word)) {
                printf("%s is an operator\n", word);
            } else if (ifConst(word)) {
                printf("%s is a constant\n", word);
            } else if (ifSpecialSymbol(word)) {
                printf("%s is a special symbol\n", word);
            } else if (isLiteral(word)) {
                printf("%s is a literal\n", word);
            } else {
                printf("%s is an identifier\n", word);
            }
        }
        fclose(in_file);
    }
    return 0;
}
