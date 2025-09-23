#include <stdio.h>

int quoc(int m, int n, int soma) {
    if (m < n) {
        printf("soma: %d", soma);
        return 0;
    }
    else {
        soma += 1;
        return quoc(m-n, n, soma);
    }
}
int main(void) {
    int m;
    int n;
    
    printf("Digite o dividendo e o divisor: ");
    scanf("%d %d", &m, &n);
    quoc(m, n, 0);
    
    return 0;
}