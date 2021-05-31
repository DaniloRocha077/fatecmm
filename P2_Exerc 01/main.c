#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int acertos=0, i, quant;
    char resp[51];
    char gaba[51]={'a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a'};
    int candi[5][3], aux[5][3];

    printf("   Correção da Avaliação\n");
    printf("Quantos candidatos deseja verificar: ");
    scanf("%d", &quant);

    respostas(quant, candi, resp, acertos, gaba);

    troca(quant, candi, aux);

    imprimir(quant, candi);



    return 0;
}
