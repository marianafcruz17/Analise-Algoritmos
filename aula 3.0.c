#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double raiz_exata(double numero);

int main(){
    double numero = 121; // 1
    double squareRoot; // 0

    squareRoot = sqrt(numero); // 1
    printf("\n %lf",squareRoot); // 1

    squareRoot = raiz_exata(numero); // 1 + numero + (numero - 1) + (1 * (numero - 1))
    printf("\n %lf",squareRoot); // 1

    printf("\n");// 1

    return 0; // 0
}

double raiz_exata(double numero){
    int i; // 0

    for(i=1;i<numero;i++){ // 1 + numero + (numero - 1)
        if(numero/i==i){ // 1 * (numero - 1)
            return i; // 0
        }
    }

    return 0; // 0
}

//pior caso: 1 + numero + (numero - 1) + (1 * (numero - 1))
//melhor caso: 1 + 1 = 2