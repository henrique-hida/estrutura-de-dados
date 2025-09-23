#include <stdio.h>
#include <string.h>

char* inv(char *s, int p, int u) {
    if (p >= u) return s;
    char temp = s[p];
    s[p] = s[u];
    s[u] = temp;

    return inv(s, p + 1, u - 1);
}


int main() {
    char string[100];
    
    printf("String a ser invertida: ");
    gets(string);

    int tamanho = strlen(string);
    inv(string, 0, tamanho - 1);

    printf("String invertida: %s\n", string);

    return 0;
}