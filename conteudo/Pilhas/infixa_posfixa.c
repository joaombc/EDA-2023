//////////////////////////
// infixa para posfixa //
////////////////////////

#define N 100
char pilha[N];
int t;

// Esta função recebe uma expressão infixa inf
// e devolve a correspondente expressão posfixa.

char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   criapilha ();
   empilha (inf[0]);       // empilha '('

   int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': empilha (inf[i]);
                   break;
         case ')': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   break;
         case '+': 
         case '-': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i])
                   break;
         case '*':
         case '/': x = desempilha ();
                   while (x != '(' && x != '+' && x != '-') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}  

//////////////////////////
// posfixa para infixa //
////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char pilha[N];
int t;

void empilha(char c) {
    pilha[++t] = c;
}

char desempilha() {
    return pilha[t--];
}

int eOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

char *posfixaParaInfixa(char *posf) {
    int n = strlen(posf);
    char *inf = malloc((2 * n + 1) * sizeof(char)); // A expressão infixa pode ser duas vezes mais longa no pior caso
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!eOperador(posf[i])) {
            empilha(posf[i]);
        } else {
            char op2 = desempilha();
            char op1 = desempilha();
            inf[j++] = '(';
            inf[j++] = op1;
            inf[j++] = posf[i];
            inf[j++] = op2;
            inf[j++] = ')';
            empilha(inf[j - 1]);
        }
    }

    inf[j] = '\0';
    return inf;
}

int main() {
    char *posf = "ab+cd-*";
    char *inf = posfixaParaInfixa(posf);
    printf("Expressão Posfixa: %s\n", posf);
    printf("Expressão Infixa: %s\n", inf);

    free(inf);

    return 0;
}
