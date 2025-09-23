#include <stdio.h>

int binDigits(int n, int dig) {
    if (n<2) printf("Dígitos em binário: %d", dig+1);
    else {
        dig += 1;
        return binDigits(n/2, dig);
    }
    return 1;
}

int main(void) {
    int n;
    
    printf("Digite o número: ");
    scanf("%d", &n);
    binDigits(n, 0);
    
    return 0;
}