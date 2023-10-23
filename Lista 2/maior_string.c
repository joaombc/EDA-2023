#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int find(int dir, int i, char* str1, char* str2) {
    int len1 = strlen(str1);
    if (i >= (int)strlen(str2)) return -1;

    char* cpy = malloc(101);
    strncpy(cpy, str2 + i, len1);
    if (!strcmp(cpy, str1)) return i;
    return find(dir, i + dir, str1, str2);
}

int main() {
    char* str = malloc(101), * sub = malloc(101), c;
    gets(str, sizeof(str), stdin);
    gets(sub, sizeof(sub), stdin);

    int len1 = strlen(str), len2 = strlen(sub);
    int start = find(1, 0, sub, str);
    if (start == -1) {
        printf("0\n");
        return 0;
    }

    int end = find(-1, len1 - len2, sub, str);
    printf("%d\n", end - start + len2);

    return 0;
}