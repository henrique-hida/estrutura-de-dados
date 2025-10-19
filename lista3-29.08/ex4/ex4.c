#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o) {
    switch(o) {
        case '(': return 0;
        case '|': return 1;
        case '&': return 2;
        case '!': return 3;
    }
    
    return -1;
}

int isBoolean(char c) {
    return (c == 'F' || c == 'V');
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (e[i] == '(') {
            empilha('(', P);
        }
        else if (isBoolean(e[i])) {
            s[j++] = e[i];
        }
        else if (strchr("|&!", e[i])) {
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if (e[i] == ')') {
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P); // Remove '('
        }
    }

    while (!vaziap(P))
        s[j++] = desempilha(P);

    s[j] = '\0';
    destroip(&P);
    return s;
}

int valor(char *e) {
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (e[i] == 'F') {
            empilha(0, P);
        } else if (e[i] == 'V') {
            empilha(1, P);
        } else {
            if (e[i] == '!') {
                int x = desempilha(P);
                empilha(!x, P);
            } else {
                int y = desempilha(P);
                int x = desempilha(P);
                switch (e[i]) {
                    case '&': empilha(x && y, P); break;
                    case '|': empilha(x || y, P); break;
                }
            }
        }
    }

    int z = desempilha(P);
    destroip(&P);
    return z;
}

void main()
{
    char e[513];
    char *resultado_posfixa;
    
    printf("Escreva uma expressão aritmética na forma infixa: ");
    fgets(e, 513, stdin);

    resultado_posfixa = posfixa(e);
    
    printf("Expressão na forma posfixa: %s\n", resultado_posfixa);
    printf("Valor da expressão: %d\n", valor(resultado_posfixa));
}