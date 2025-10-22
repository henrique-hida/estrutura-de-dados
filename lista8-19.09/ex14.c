#include <stdio.h>

int sd(int n)
{
    if(n==0){
        return 0;
    } else {
        return (n%10)+sd(n/10);
    }
}

int main()
{
    int n;
    printf("Digite um número:");
    scanf("%d", &n);
    printf("Soma: %d",sd(n));
    return 0;
}