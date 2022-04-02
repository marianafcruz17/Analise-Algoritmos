#include<stdio.h>
#include<stdlid.h>
#define n 10

int main(){
    int i;

    mostrar(n);
    return 0;
}

mostrar(int x){
    if(x==0){ // 1
        return;
    }

    print("\nOi"); // 1+
    mostrar(x-1); //f(n-1)
}

//f(n) = c + f(n-1) -> custo atrelado a f(n)

//f(n) = c + (c + f(n-2))
//f(n) = c + (c + (c + f(n-3)))
//f(n) = kc + f(n-k)
//quantidade de chamadas recursivas + constante + f(n-quantidade de chamadas recursivas)

//n - k = 1
//k = n - 1
//f(n) = (n-1)c + 1
//f(n) = cn - c + 1 -> O(n)