#include <stdio.h>

void bsort(int vetor[], int tamanho){
    int i, j, temp;
    for (i=0; i < tamanho - 1; i++){
        for (j=0; j < tamanho - i - 1; j ++){
            if (vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void exibe(int vetor [], int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    bsort(v, 10);
    exibe(v, 10);
    return 0;
}