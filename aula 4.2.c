//for quadratico recursivo
#include<stdio.h>
#include<stdlib.h>
#define n 10

void mostrar(int x);

int main(){
    for(int i=0;i<=n;i++){
        if(n<=5){
            mostrar(n);
        }else{
            printf("\n n é maior que 5");
        }
    }
    
    return 0;
}

void mostrar(int x){
    if(x==0){ 
        return;
    }

    printf("\n Oi");
    mostrar(x-1); 
}