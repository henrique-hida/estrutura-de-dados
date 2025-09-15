#include <stdio.h> 
#include "pilha.h" 
#include "fila.h"

int ttm(Fila F, Pilha P) {
    int tempo = 0;
    while (!vaziap(P)) {
        int processo_ideal = desempilha(P);
        while (1) {
            int processo_atual = desenfileira(F);
            if (processo_atual == processo_ideal) {
                tempo++;
                break;
            } else {
                enfileira(processo_atual, F);
                tempo++;
            }
        }
    }
    return tempo;
}

int main(void) { 
    Fila F = fila(3); 
    enfileira(2,F); 
    enfileira(3,F); 
    enfileira(1,F);
    
    Pilha P = pilha(3); 
    empilha(2,P);
    empilha(3,P);
    empilha(1,P);
    
    printf("\nTempo total mínimo: %ds\n\n", ttm(F,P) );
    
    destroif(&F); 
    destroip(&P);
    return 0;
}
