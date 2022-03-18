#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=0; //quantidade de instrução = 1

    while(i<3){ //quantidade de instrução = 1 + quantas vezes a condição repete + a saída da condição = 1 + 1 + 1 + 1 = 4
        i = i + 1; //quantidade de instrução = 1 x quantas vezes entra na condição = 1 x 3 = 3
    }
}

//Quantidade de instruções: No pior caso é 8