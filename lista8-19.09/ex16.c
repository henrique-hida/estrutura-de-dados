#include <stdio.h>
#include <math.h>

long long h(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return 2 * h(n - 1) + 1;
    }
}

int main() {
    int n;

    printf("Digite o numero de discos para as Torres de Hanoi: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: O numero de discos nao pode ser negativo.\n");
        return 1;
    }

    long long movimentos = h(n);

    printf("O numero minimo de movimentos para %d discos eh: %lld\n", n, movimentos);

    return 0;
}