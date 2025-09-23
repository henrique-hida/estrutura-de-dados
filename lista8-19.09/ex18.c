#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pal(char* s, int p, int u) {
    if (p >= u) return 1;
    else {
        if (isspace(s[p])) return pal(s, p+1, u);
        if (isspace(s[u])) return pal(s, p, u-1);
        if (s[p] == s[u]) return pal(s, p+1, u-1);
        else return 0;
    }
}

int main() {
    char string[100];
    
    printf("Digite uma palavra ou frase: ");
    gets(string);
    
    int tamanho = strlen(string);
    int res = pal(string, 0, tamanho-1);
    
    if (res) printf("A palavra é um palíndromo!");
    else printf("A palavra não é um palíndromo");

    return 0;
}