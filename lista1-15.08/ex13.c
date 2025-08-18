#include <stdio.h>

void troca(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int x = 5;
    int y = 3;
    printf("Valor de x antes da troca: %d\n", x);
    printf("Valor de y antes da troca: %d\n", y);
    
    troca(&x, &y);

    printf("Valor de x depois da troca: %d\n", x);
    printf("Valor de y depois da troca: %d\n", y);
    return 0;
}