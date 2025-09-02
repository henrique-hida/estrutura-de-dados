#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prioridade(char o) {
    switch(o) {
        case '(':
        case ')': return 0;
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
    }
    return -1;
}

void inverte_string(char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    char temp;

    while (inicio < fim) {
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

void prefixa(char *e, char *saida) {
    char infixa_invertida[256];
    char temp_posfixa[256];
    char pilha_op[256];
    int topo = -1;
    int j = 0;

    strcpy(infixa_invertida, e);
    inverte_string(infixa_invertida);

    for (int i = 0; infixa_invertida[i] != '\0'; i++) {
        if (infixa_invertida[i] == '(') {
            infixa_invertida[i] = ')';
        } else if (infixa_invertida[i] == ')') {
            infixa_invertida[i] = '(';
        }
    }

    for (int i = 0; infixa_invertida[i] != '\0'; i++) {
        char token = infixa_invertida[i];

        if (isdigit(token)) {
            temp_posfixa[j++] = token;
        } else if (token == '(') {
            pilha_op[++topo] = token;
        } else if (token == ')') {
            while (topo != -1 && pilha_op[topo] != '(') {
                temp_posfixa[j++] = ' ';
                temp_posfixa[j++] = pilha_op[topo--];
            }
            if (topo != -1) topo--;
        } else if (strchr("+-*/", token)) {
            temp_posfixa[j++] = ' ';
            while (topo != -1 && prioridade(pilha_op[topo]) >= prioridade(token)) {
                temp_posfixa[j++] = pilha_op[topo--];
                temp_posfixa[j++] = ' ';
            }
            pilha_op[++topo] = token;
        }
    }
    
    while (topo != -1) {
        temp_posfixa[j++] = ' ';
        temp_posfixa[j++] = pilha_op[topo--];
    }
    temp_posfixa[j] = '\0';

    strcpy(saida, temp_posfixa);
    inverte_string(saida);
}

int main() {
    char expressao_infixa[256];
    char expressao_prefixa[256];

    printf("Digite a expressao infixa totalmente parentesiada:\n");
    
    gets(expressao_infixa);

    prefixa(expressao_infixa, expressao_prefixa);

    printf("\nExpressao Infixa: %s\n", expressao_infixa);
    printf("Expressao Prefixa: %s\n", expressao_prefixa);
    
    return 0;
}