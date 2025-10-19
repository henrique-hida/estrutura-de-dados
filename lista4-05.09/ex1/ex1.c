#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
    char s[256];
    char sUpper;
    Fila F = fila(256);
    Pilha P = pilha(256);

    printf("\nFrase? ");
    fgets(s, 256, stdin);

    for (int i = 0; s[i]; i++)
        sUpper = toupper(s[i]);
        
        if (isalpha(sUpper)) {
            enfileira(sUpper, F);
            empilha(sUpper, P);
        }

    while (!vaziaf(F) && desenfileira(F) == desempilha(P));

    if (vaziaf(F))
        puts("A frase eh palindroma");
    else
        puts("A frase nao e palindroma");

    destroif(&F);
    destroip(&P);

    return 0;
}