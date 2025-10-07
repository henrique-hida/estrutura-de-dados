#include <stdio.h>

void troca(int v[], int i, int j) {
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void exibe(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

void empurra(int v[], int u) {
    if (u <= 0) return;
    
    empurra(v, u - 1);
    if (v[u - 1] > v[u]) troca(v, u - 1, u);
}

int main(void) {
    int v[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    
    printf("Vetor original: ");
    exibe(v, 9);

    empurra(v, 8);
    
    printf("Vetor apos empurra(v, 8): ");
    exibe(v, 9);

    return 0;
}