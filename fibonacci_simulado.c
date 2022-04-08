#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long int fibonacci_recursivo(long long int n);
long long int fibonacci_iterativo(long long int n);
void multiplicar_duas_matrizes(long long int m1[2][2], long long int m2[2][2]);
void potencia_matriz(long long int m[2][2], int exp);
long long int fibonacci_matricial(long long int n);

int main(){
    time_t time_inicial, time_final;
    long long int casos[] = {1,5,15,20,25,30,35,40,45,50};
    int tamanho = sizeof(casos)/sizeof(casos[0]);
    
    printf("\n Tempos de execução em forma recursivo\n");
    for(int i = 0; i < tamanho; i++){
        time_inicial = time(NULL);
        printf("-> %lld:",fibonacci_recursivo(casos[i]));
        time_final = time(NULL);

        printf("%lld-esimo termo: ", casos[i]);
        printf("%f s\n", difftime(time_final,time_inicial));
    }

    printf("\n Tempos de execução em forma iterativa\n");
    for(int i = 0; i < tamanho; i++){
        time_inicial = time(NULL);
        printf("-> %lld:",fibonacci_iterativo(casos[i]));
        time_final = time(NULL);

        printf("%lld-esimo termo: ", casos[i]);
        printf("%f s\n", difftime(time_final,time_inicial));
    }

    printf("\n Tempos de execução em forma matricial\n");
    for(int i = 0; i < tamanho; i++){
        time_inicial = time(NULL);
        printf("-> %lld:",fibonacci_matricial(casos[i]));
        time_final = time(NULL);

        printf("%lld-esimo termo: ", casos[i]);
        printf("%f s\n", difftime(time_final,time_inicial));
    }
}

//Questão 1.a
long long int fibonacci_recursivo(long long int n) {
    if(n==1){
        return 0;
    }else{
        if(n==2){
            return 1;
        }else{
            return fibonacci_iterativo(n-1) + fibonacci_iterativo(n-2);
        }
    }
}

//Questão 1.b
long long int fibonacci_iterativo(long long int n){
    long long int a=0,b=1,c;
    int i=2;

    if(n==1){
        return a;
    }else{
        if(n==2){
            return b;
        }else{
            while(i<n){
                c = a + b;
                a = b;
                b = c; 
                i++;
            }
            return c;
        }
    }
}

//Questão 1.c
void multiplicar_duas_matrizes(long long int m1[2][2], long long int m2[2][2]){
    long long int a =  m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    long long int b =  m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
    long long int c =  m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    long long int d =  m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
    m1[0][0] = a;
    m1[0][1] = b;
    m1[1][0] = c;
    m1[1][1] = d;
}

void potencia_matriz(long long int m[2][2], int exp){
    if (exp == 0 || exp == 1){
        return;
    }

    long long int matrix_auxiliar[2][2] = {{1,1},{1,0}};

    potencia_matriz(m,exp/2);
    multiplicar_duas_matrizes(m,m);
    if (exp % 2 != 0){
        multiplicar_duas_matrizes(m, matrix_auxiliar);
    } 
}

long long int fibonacci_matricial(long long int n){
    long long int matriz_principal[2][2] = {{1,1}, {1,0}};

    if(n == 0)
        return 0;

    potencia_matriz(matriz_principal, n-1);

    return matriz_principal[0][0];
}