#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int acertos=0, i, j, quant;
    char resp[51];
    char gaba[51]={'a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a'};
    int candi[5][3], aux[5][3];

    printf("   Correção da Avaliação\n");
    printf("Quantos candidatos deseja verificar: ");
    scanf("%d", &quant);
    for(i=0; i<quant; i++){
        printf("\n    Olá %dº Candidato\n", i+1);
        printf("Digite sua matrícula com 5 digitos: ");
        scanf("%d", &candi[i][0]);
        printf("Digite suas respostas para comparar com o Gabarito------>\n Resp: ");
        fflush(stdin);
        gets(resp);
        candi[i][1]=resp;           //recebe a entrada e armazena na matriz
        acertos=0;
        for(j=0; j<50; j++){
            if(gaba[j]==resp[j]){
                acertos+=1;
            }
        }
        candi[i][2]=acertos;
    system("cls");
    }
    for(i=0; i<quant; i++){
        for(j=i+1; j<quant; j++){
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

    printf("------Resultado do Vestibular----\n");
    printf("      Matricula   |   Acertos \n");

    for(i=0; i<quant; i++){             //printf para mostrar todas as posições
        printf("        %d     |     %d\n", candi[i][0], candi[i][2]);
    }

    return 0;
}
