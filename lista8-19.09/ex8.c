
#include <stdio.h>

int hanoi(int n, char origem, char aux, char destino)
{
    if(n==1){
        printf("Mova de %c para %c\n", origem, destino);
    } else {
        hanoi(n-1,origem, destino, aux);
        printf("Mova de %c para %c\n", origem, destino);
        hanoi(n-1,aux, origem, destino);
    }
}

int main()
{
    int n;
    printf("Digite quantas n terá a torre de hanoi:");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}