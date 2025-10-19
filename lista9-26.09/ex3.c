#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void empurra(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            troca(&v[i], &v[i + 1]);
        }
    }
}

void bsr(int v[], int n) {
    if (n <= 1) {
        return;
    }
    empurra(v, n);
    bsr(v, n - 1);
}

void exibe(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    int v[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    int n = 9;

    printf("Entrada: ");
    exibe(v, n);
    
    bsr(v, n);

    printf("Saída: ");
    exibe(v, n);

    return 0;
}