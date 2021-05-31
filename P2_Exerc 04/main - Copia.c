#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int base[12]={5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, num=0, i=0, soma=0, resto=0, div=11, dig1=0, dig2=0;
    int base2[13]={6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    char cnpj[15];

    printf("Digite os 12 digitos do CNPJ: ");
    //gets(cnpj);

    //for(i=0; i<18;i++){
    //    if(cnpj[i]=='.'){
     //       cnpj[i]=cnpj[i+1];
    //    }
        //if(cnpj[i]=='/'){
        //    cnpj[i]=cnpj[i+1];
        //}
    //}
    char numeros[14];
     for(i=0;i<=13;i++)
         {
            if(i-1==1)printf(".");
            if(i-1==4)printf(".");
            if(i-1==7)printf("/");
            if(i-1==11)printf("-");
            //numeros[i]=getche();
            cnpj[i]=getche();
            //cnpj[i]=numeros[i];
            //numeros[i]=' ';
         }
    printf("\nCNPJ: %s\n", cnpj);

    for (i=0; i<12; i++){
        num = cnpj[i]-48;
        soma += (num*base[i]);
    }

    resto=soma%div;

    if(resto<2){
        dig1=0;
    }
    else{
        dig1=div-resto;
    }

    soma=0;
    num=0;

    //Segundo for para ultimo digito
    for (i=0; i<13; i++){
        num = cnpj[i]-48;
        soma += (num*base2[i]);
    }

    resto=soma%div;

    if(resto<2)
        dig2=0;
    else
        dig2=div-resto;

    if(cnpj[12]-48==dig1&&cnpj[13]-48==dig2){
        printf("Este CNPJ é válido\n");
    }
    else{
        printf("Este CNPJ é inválido\n");
    }
    return 0;
}

