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

int in(Item x, Lista L) {
    if (L == NULL) {
        return 0;
    }
    if (L->item == x) {
        return 1;
    }
    return in(x, L->prox);
}

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    int item1 = 5;
    int item2 = 9;
    printf("O item %d pertence (recursivo)? %s\n", item1, in(item1, I) ? "Sim" : "Nao");
    printf("O item %d pertence (recursivo)? %s\n", item2, in(item2, I) ? "Sim" : "Nao");
    return 0;
}