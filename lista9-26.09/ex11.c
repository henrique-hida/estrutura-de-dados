#include <stdio.h>

int rlsearch(int x, int v[], int n) {
    if (n <= 0) return 0;
    if (v[n - 1] == x) return 1;
    
    return rlsearch(x, v, n - 1);
}

int main(void) {
    int v[8] = {66, 80, 31, 48, 27, 75, 19, 52};
    
    int item1 = 27;
    printf("%d: %s\n", item1, rlsearch(item1, v, 8) ? "Encontrado" : "Nao encontrado");

    int item2 = 51;
    printf("%d: %s\n", item2, rlsearch(item2, v, 8) ? "Encontrado" : "Nao encontrado");

    return 0;
}