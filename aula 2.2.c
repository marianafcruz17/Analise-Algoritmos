#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int x; //quantidade de instrução = 0
    scanf("%d",&x); //quantidade de instrução = 1

    if(x>10){ //quantidade de instrução = 1
        printf("\n Teste"); //quantidade de instrução = 1
    }else{ //quantidade de instrução = 0
        printf("\n Teste 2"); //quantidade de instrução = 1
        printf("\n Teste 3"); //quantidade de instrução = 1

        if(1){ //quantidade de instrução = 1
            printf("\n hello"); //quantidade de instrução = 1
            printf("\n hello"); //quantidade de instrução = 1
        }else{
            printf("\n world"); //quantidade de instrução = 1
        }
    }

    return 0; //quantidade de instrução = 0
}

//Quantidade de instruções: No pior caso é 7 e o melhor é 3