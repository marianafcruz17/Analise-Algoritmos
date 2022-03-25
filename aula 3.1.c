#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double raiz_exata(double numero);

int main(){
    double numero = 121; // 1
    double squareRoot; // 0

    double vet[] = {100, 121, 144, 169}; // 1
    int i; // 0

    for(i=0;i<4;i++){ // 1 + (tam_vet + 1) + tam_vet -> O(n)
        squareRoot = raiz_exata(numero); // 1 + numero + (numero - 1) + (1 * (numero - 1))
        // (1 + (4 + 1) + 4)
        // (1 + 100 + (100 - 1) + (1 * (100 - 1))) * (1 + (4 + 1) + 4) = (101 + 99 + 99) * 10 = 299 * 10 = 2990
        // (1 + 121 + (121 - 1) + (1 * (121 - 1))) * (1 + (4 + 1) + 4) = (122 + 120 + 120) * 10 = 366 * 10 = 3660
        // (1 + 144 + (144 - 1) + (1 * (144 - 1))) * (1 + (4 + 1) + 4) = (145 + 143 + 143) * 10 = 431 * 10 = 4310
        // (1 + 169 + (169 - 1) + (1 * (169 - 1))) * (1 + (4 + 1) + 4) = (170 + 168 + 168) * 10 = 506 * 10 = 5060


        printf("\n %lf",squareRoot); // 1
    }
    
    printf("\n");// 1

    return 0; // 0
}

double raiz_exata(double numero){
    int i; // 0

    for(i=1;i<numero;i++){ // 1 + numero + (numero - 1) -> O(m)
        if(numero/i==i){ // 1 * (numero - 1)
            return i; // 0
        }
    }

    return 0; // 0
}

//pior caso: 1 + numero + (numero - 1) + (1 * (numero - 1))
//melhor caso: 1 + 1 = 2

//complexidade do código: O(n) * O(m) ~ O(n^2)