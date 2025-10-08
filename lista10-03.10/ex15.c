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

Lista clone(Lista L) {
    if (L == NULL) {
        return NULL;
    }
    return no(L->item, clone(L->prox));
}

int main(void) {
    Lista A = no(10, no(20, no(30, NULL)));
    Lista B = clone(A);
    printf("Lista Original A: ");
    exibe(A);
    printf("Lista Clonada B: ");
    exibe(B);
    return 0;
}