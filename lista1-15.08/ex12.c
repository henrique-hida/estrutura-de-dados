#include <stdio.h>

int troca(int a, int b){
    int c = a;
    a = b;
    b = c;
    return a, b; // exemplo: retorna o novo valor de 'a'
}

int main(){
    int x = 10, y = 20, valor;
    printf("Valor antigo de A: %d ", x);
    printf("Valor antigo de B: %d\n", y);
    valor = troca(x, y);
    printf("Valor novo de A: %d ", x);
    printf("Valor novo de B: %d", y);
    return 0;
}

 