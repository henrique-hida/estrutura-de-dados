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

int pertence(Item x, Lista L) {
    while (L != NULL) {
        if (L->item == x) {
            return 1;
        }
        L = L->prox;
    }
    return 0;
}

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    int item1 = 1;
    int item2 = 7;
    printf("O item %d pertence a lista? %s\n", item1, pertence(item1, I) ? "Sim" : "Nao");
    printf("O item %d pertence a lista? %s\n", item2, pertence(item2, I) ? "Sim" : "Nao");
    return 0;
}