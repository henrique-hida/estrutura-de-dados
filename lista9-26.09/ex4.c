#include <stdio.h>
#include <stdlib.h>

void intercala(int v[], int p, int m, int u) {
    int i = p, j = m + 1, k = 0;
    int *w = malloc((u - p + 1) * sizeof(int));
    if (w == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    while (i <= m && j <= u) {
        w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }

    while (i <= m) w[k++] = v[i++];

    while (j <= u) w[k++] = v[j++];

    for (k = 0; k <= u - p; k++)
        v[p + k] = w[k];

    free(w);
}

void exibe(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int v[8] = {31, 48, 60, 80, 19, 27, 52, 75};
    intercala(v, 0, 3, 7);
    exibe(v, 8);

    int w[9] = {10, 82, 27, 38, 41, 53, 60, 75, 99};
    intercala(w, 0, 1, 8);
    exibe(w, 9);

    return 0;
}
