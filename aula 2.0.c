#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int x=13; //quantidade de instrução = 1
    int a,b=input(),c=10; //quantidade de instrução = 2

    if(x>10 && b=c){ //quantidade de instrução = 1
        printf("\n Teste"); //quantidade de instrução = 1
    }

    return 0; //quantidade de instrução = 0
}

//Quantidade de instruções: No pior caso é 5 e o melhor é 4
//Para escolher se usa o melhor ou o pior caso, vai depender da frequência com que ocorre cada caso