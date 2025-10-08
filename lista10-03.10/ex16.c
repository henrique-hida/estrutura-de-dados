#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

Lista rnd(int n, int m) {
    if (n == 0) {
        return NULL;
    }
    return no(rand() % m, rnd(n - 1, m));
}

int main(void) {
    srand(time(NULL));
    Lista A = rnd(8, 50);
    printf("Lista aleatoria recursiva: ");
    exibe(A);
    return 0;
}