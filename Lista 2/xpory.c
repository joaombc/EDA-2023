#include <stdio.h>

void substituirXY(char *str, int index) {
    if (str[index] == '\0') {
        return; 
    }

    if (str[index] == 'x') {
        str[index] = 'y';
    }

    substituirXY(str, index + 1); 
}

int main() {
    char str[81];
    scanf("%s", str);

    substituirXY(str, 0);

    printf("%s\n", str);

    return 0;
}