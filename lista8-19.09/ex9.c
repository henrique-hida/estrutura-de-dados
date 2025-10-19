#include <stdio.h>

int par(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    
    return par(n - 2);    
}

int main() {
    int numero;

    printf("Digite um numero natural para verificar se eh par: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: O numero deve ser natural (maior ou igual a zero).\n");
        return 1;
    }

    if (par(numero)) {
        printf("O numero %d nao eh par.\n", numero);
    } else {
        printf("O numero %d eh par.\n", numero);
    }

    return 0;
}