#include <stdio.h>
#include <string.h>

void moveXToEnd(char *str) {
    int len = strlen(str);
    char result[101]; // string temporária 
    int resultIndex = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != 'x') {
            result[resultIndex] = str[i];
            resultIndex++;
        }
    }

    for (int i = 0; i < len; i++) {
        if (str[i] == 'x') {
            result[resultIndex] = 'x';
            resultIndex++;
        }
    }

    result[resultIndex] = '\0';
    strcpy(str, result);
}

int main() {
    char str[101];
    scanf("%s", str);

    moveXToEnd(str);

    printf("%s\n", str);
}