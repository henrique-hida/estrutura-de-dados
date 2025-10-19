#include <stdio.h>

int prod(int m, int n) {
    if (n == 0) return 0;
    
    return m + prod(m, n - 1);
}

int main() {
    int m, n, resultado;

    printf("Digite o primeiro numero natural: ");
    scanf("%d", &m);

    printf("Digite o segundo numero natural: ");
    scanf("%d", &n);

    if (m < 0 || n < 0) {
        printf("Erro: Os numeros devem ser naturais (maiores ou iguais a zero).\n");
        return 1;
    }

    resultado = prod(m, n);

    printf("%dx%d = %d\n", m, n, resultado);

    return 0;
}