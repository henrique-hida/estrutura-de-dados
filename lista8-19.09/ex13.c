#include <stdio.h>

int q(int n) {
    if (n == 0) return 0;
    
    return q(n - 1) + (2 * n - 1);
}

int main() {
    int numero;

    printf("Digite um numero natural para calcular seu quadrado: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: O numero deve ser natural (maior ou igual a zero).\n");
        return 1;
    }

    printf("O quadrado de %d eh: %d\n", numero, q(numero));

    return 0;
}