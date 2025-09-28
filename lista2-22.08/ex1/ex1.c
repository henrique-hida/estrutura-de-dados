#include <stdio.h>
#include "pilha.h"

void ordenaPilha(Pilha A, Pilha B) {
    while (!vaziap(A)) {
        Itemp temp = desempilha(A);

        while (!vaziap(B) && topo(B) > temp) {
            empilha(desempilha(B), A);
        }

        empilha(temp, B);
    }

    while (!vaziap(B)) {
        empilha(desempilha(B), A);
    }
}

int main() {
    int n, valor;

    printf("Quantos números você deseja inserir? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1;
    }

    Pilha A = pilha(n);
    Pilha B = pilha(n);

    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        empilha(valor, A);
    }

    ordenaPilha(A, B);

    printf("\nPilha ordenada em ordem crescente:\n");
    while (!vaziap(A)) {
        printf("%d ", desempilha(A));
    }
    printf("\n");

    destroip(&A);
    destroip(&B);

    return 0;
}

