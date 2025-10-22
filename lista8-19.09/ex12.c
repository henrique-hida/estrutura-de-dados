#include <stdio.h>

int resto(int m, int n)
{
    if(m<=n){
        printf("resultado: %d", m);
    } else {
        resto(m - n, n);
    }
}

int main()
{
    int m;
    int n;
    printf("Digite o dividendo:");
    scanf("%d", &m);
    printf("Digite o divisor:");
    scanf("%d", &n);
    resto(m,n);
    return 0;
}