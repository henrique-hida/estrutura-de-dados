#include <stdio.h>

int buscaBinariaRecursiva(int v[], int inicio, int fim, int chave) {
    if (inicio > fim) {
        return -1; 
    }

    int meio = (inicio + fim) / 2;

    if (v[meio] == chave) {
        return meio; 
    } 
    else if (chave < v[meio]) {
        return buscaBinariaRecursiva(v, inicio, meio - 1, chave);
    } 
    else {
        return buscaBinariaRecursiva(v, meio + 1, fim, chave);
    }
}

int main() {
    int v[] = {10, 20, 30, 40, 50, 60, 70};
    int tamanho = sizeof(v) / sizeof(v[0]);
    int chave = 50;

    int resultado = buscaBinariaRecursiva(v, 0, tamanho - 1, chave);

    if (resultado != -1)
        printf("Elemento %d encontrado na posição %d.\n", chave, resultado);
    else
        printf("Elemento %d não encontrado.\n", chave);

    return 0;
}
