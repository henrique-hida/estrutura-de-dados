#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista L) {
    printf("[");
    while (L != NULL) {
        printf("%d", L->item);
        if (L->prox != NULL) {
            printf(",");
        }
        L = L->prox;
    }
    printf("]\n");
}

Item maximo(Lista L) {
    if (!L) {
        printf("Erro fatal: a lista esta vazia.\n");
        exit(1);
    }
    Item max_val = L->item;
    L = L->prox;
    while (L != NULL) {
        if (L->item > max_val) {
            max_val = L->item;
        }
        L = L->prox;
    }
    return max_val;
}

int main(void) {
    Lista I = no(3, no(8, no(5, no(2, NULL))));
    printf("Lista: ");
    exibe(I);
    printf("O item maximo e: %d\n", maximo(I));
    return 0;
}