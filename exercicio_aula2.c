// Diga qual será a quantidade de operações realizadas para as seguintes instâncias do problema:

// a) vet[1,2,3,4,5,6,7,8,9,10] -> quantidade de instruções: 55
// b) vet[10,20,30,40,50,60,70] -> quantidade de instruções: 43
// c) vet[1,3,5,7,9,11,13,15,17] -> quantidade de instruções: 65

#include <stdio.h>
#include <stdlib.h>
#define TAM1 10
#define TAM2 10

int main()
{
    int i,j,x; //0
    int vet[]=x; //1
    for(i=0;i<TAM1;i++) //1 + (10 + 1) + 10 = 22
    {
        if (vet[i]%3==0) //1 x 10 = 10
        {
            for(j=0;j<TAM2;j++) //1 + (10 + 1) + 10 = 22
            {
                printf("\n Senhor"); //1
            }
        }
        else
        {
            printf("\n Gzuz"); //1
        }
    }
}