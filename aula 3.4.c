#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int n = 100;
    
    for(i=n;i>=1;i=1/3){ // log(n)
        for(j=n;j>=1;j=j/3){ // log(n)
            printf("\n teste");
        }
    }
}

//complexidade do código: log(n)^2