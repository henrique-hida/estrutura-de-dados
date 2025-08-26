#include <stdio.h>
#include <string.h>
#include "pilha.h"

void inverterPalavras(char *frase) {
    int tamanhoFrase = strlen(frase);
    Pilha palavraStack = pilha(tamanhoFrase);
    
    for(int i=0; i <= tamanhoFrase; i++) {
        char caractere = frase[i];

        if (caractere == ' ' || caractere == '\0') {
            while(vaziap(palavraStack) == 0) {
                printf("%c", desempilha(palavraStack));
            } 
            printf("%c", caractere);
        } else {
            empilha(caractere, palavraStack);
        }
    }
    
    destroip(&palavraStack);
    
}

int main() {
    
    char frase[256];
    
    printf("===== INVERTE PALAVRAS =====\n");
    printf("Insira a frase que você deseja inverter as palavras\n");
    gets(frase);
    
    inverterPalavras(frase);

    return 0;
}
