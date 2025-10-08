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

void replace(Item x, Item y, Lista L) {
    if (L == NULL) {
        return;
    }
    if (L->item == x) {
        L->item = y;
    }
    replace(x, y, L->prox);
}

int main(void) {
    Lista I = no(1, no(2, no(1, no(3, no(1, NULL)))));
    printf("Lista original: ");
    exibe(I);
    replace(1, 9, I);
    printf("Lista apos substituir 1 por 9: ");
    exibe(I);
    return 0;
}