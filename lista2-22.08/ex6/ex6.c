#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    Pilha P = pilha(5);
    char s[11];

    printf("Digite as 3 cadeias de caracteres:\n");
    for (int i = 1; i <= 3; i++) {
        printf("? ");
       
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0;

        empilha(strdup(s), P);
    }

    printf("\nDesempilhando as strings:\n");
    while (!vaziap(P)) {
        char *string_copiada = desempilha(P);
       
        puts(string_copiada);
       
        free(string_copiada);
    }

    destroip(&P);
    return 0;
}