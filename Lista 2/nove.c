#include <stdio.h>
#include <string.h>

int main() {
    char num[1001]; 
    int caseNumber = 1;

    while (1) {
        scanf("%s", num);

        if (num[0] == '0') {
            break; // Fim da entrada.
        }

        int length = strlen(num);
        int sum = 0;

        for (int i = 0; i < length; i++) {
            sum += num[i] - '0';
        }

        int degree = 1;

        while (sum > 9) {
            int newSum = 0;

            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }

            sum = newSum;
            degree++;
        }

        if (sum % 9 == 0) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, degree);
        } else {
            printf("%s is not a multiple of 9.\n", num);
        }

        caseNumber++;
    }

    return 0;
}