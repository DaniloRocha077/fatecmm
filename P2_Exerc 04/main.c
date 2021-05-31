#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int base[12]={5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, num=0, i=0, soma=0, resto=0, div=11, dig1=0, dig2=0;
    int base2[13]={6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    char cnpj[15];

    printf(">>-----Validação de CNPJ-----<<\n");
    printf("Digite os 14 digitos do CNPJ: ");

    for(i=0;i<=13;i++){                 //for para colocar pontuação conforme digitação
        if(i-1==1)printf(".");
        if(i-1==4)printf(".");
        if(i-1==7)printf("/");
        if(i-1==11)printf("-");
        cnpj[i]=getche();
    }

    for (i=0; i<12; i++){               //for para primeiro digito
        num = cnpj[i]-48;
        soma += (num*base[i]);
    }

    resto=soma%div;                     //soma dividido por 11

    if(resto<2){
        dig1=0;
    }
    else{
        dig1=div-resto;
    }

    soma=0;
    num=0;

    for (i=0; i<13; i++){               //for para ultimo digito
        num = cnpj[i]-48;
        soma += (num*base2[i]);
    }

    resto=soma%div;                     //som dividido por 11

    if(resto<2)
        dig2=0;
    else
        dig2=div-resto;

    if(cnpj[12]-48==dig1&&cnpj[13]-48==dig2){
        printf("\n\n>>---Este CNPJ é válido---<<\n");
    }
    else{
        printf(">>---Este CNPJ é inválido---<<\n");
    }
    return 0;
}
