#include<stdio.h>
#include<stdlib.h>
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, …

int fibonacci(int n);

int main(void){
    int n;

    scanf("%d",&n);
    printf("%d\n",fibonacci(n));

    return 0;
}

int fibonacci(int n){
    if(n==1){
        return 1;
    }else{
        if(n==2){
            return 1;
        }else{
            return fibonacci(n-1) + fibonacci(n-2;
        }
    }
}