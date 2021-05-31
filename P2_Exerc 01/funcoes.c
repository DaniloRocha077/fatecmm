#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

void respostas(int quant, int candi[5][3], char resp[51], int acertos, char gaba[51]){

for(int i=0; i<quant; i++){
        printf("\n    Olá %dº Candidato\n", i+1);
        printf("Digite sua matrícula com 5 digitos: ");
        scanf("%d", &candi[i][0]);
        printf("Digite suas respostas para comparar com o Gabarito------>\n Resp: ");
        fflush(stdin);
        gets(resp);
        candi[i][1]=resp;           //recebe a entrada e armazena na matriz
        acertos=0;
        for(int j=0; j<50; j++){
            if(gaba[j]==resp[j]){
                acertos+=1;
            }
        }
        candi[i][2]=acertos;
    system("cls");
    }
}

void troca(int quant, int candi[5][3], int aux[5][3]){

for(int i=0; i<quant; i++){
        for(int j=i+1; j<quant; j++){
            if(candi[i][2]<candi[j][2]){
                aux[i][0] = candi[i][0];
                aux[i][2] = candi[i][2];
                candi[i][0]=candi[j][0];
                candi[i][2]=candi[j][2];
                candi[j][0]=aux[i][0];
                candi[j][2]=aux[i][2];
            }
        }
    }
}

void imprimir(int quant, int candi[5][3]){

    printf("------Resultado do Vestibular-----\n");
    printf("      Matricula   |   Acertos \n");

    for(int i=0; i<quant; i++){             //printf para mostrar todas as posições
        printf("        %d     |     %d\n", candi[i][0], candi[i][2]);
    }
}
