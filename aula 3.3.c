#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int n = 100;
    
    for(i=n;i>=1;i=1/3){ // log(n)
        for(j=0;j<500;j++){ // n
            printf("\n teste");
        }
    }
}

//complexidade do código: n log(n)