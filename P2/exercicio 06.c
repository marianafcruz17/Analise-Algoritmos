/*Felippe percebeu que após ter resolvido o problema da vidraçaria poderia levar para casa os retalhos de vidro que coubesse em sua maleta.
Faça um programa que leia do usuário a capacidade da maleta de Felippe e o nome de um arquivo que irá conter o valor e o tamanho de todos retalhos
disponíveis para Felippe. O objetivo e maximixar o valor a ser levado por ele.
Mostre na tela qual a combinação de retalhos a ser levado por Felippe para que ele maximize o valor que está levando e o valor que ele irá levar utilizando uma solução com programação dinâmica.

Exemplo do arquivo (tamanho;valor):
2;5
3;7
4;5
2;4
3;5*/


#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int l, int c);
//int *bp(int *valores, int *pesos, int qtd_elementos, int capacidade);
int *bp(int valores[], int pesos[], int qtd_elementos, int capacidade);
int max(int a, int b);
int knapSack(int W, int wt[], int val[], int n);
int bp_recursiva(int W, int wt[], int val[], int n);
float bp_gulosa(int valores[], int pesos[], int qtd_elementos, int capacidade);


int main()
{
	 int capacidade ;
    int qtd_objetos = 0 ;
    int valores[qtd_objetos] ;
    int pesos[qtd_objetos] ;
    int a,b,i;
    
	printf("Digite a capacidade da maleta de felippe \n");
	scanf("%d",&capacidade);
	FILE *arq;
    arq = fopen("teste.txt", "r");
	 while (fscanf(arq, "%d;%d\n", &a, &b) != EOF)
    {
        printf("\n Tamanho: %dkg Valor: %d$", a, b);

         pesos[qtd_objetos] = a;
         valores[qtd_objetos] = b;
        qtd_objetos ++;
    }
     printf("\n");
    printf("\n Valor Total Adcionado :%0.2f ",bp_gulosa(valores,pesos,  qtd_objetos,  capacidade));
  

    printf("\n");
    return 0;
}
int bp_recursiva(int W, int wt[], int val[], int n)
{
    
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return bp_recursiva(W, wt, val, n - 1);

    else
        return max(
            val[n - 1]
                + bp_recursiva(W - wt[n - 1],
                           wt, val, n - 1),
            bp_recursiva(W, wt, val, n - 1));
}
float bp_gulosa(int valores[], int pesos[], int qtd_elementos, int capacidade) {
    int peso_atual;
    float valor_total;
    int i, maximo;
    int n = qtd_elementos;
    int W = capacidade;
    int usado[10];

    for (i = 0; i < n; ++i)
        usado[i] = 0;

    peso_atual = W;
    while (peso_atual > 0) { // enquanto ainda tiver espaço na mochila, procurar o melhor objeto
        maximo = -1;
        for (i = 0; i < n; ++i)
            if ((usado[i] == 0) &&
                ((maximo == -1) || ((float)valores[i]/pesos[i] > (float)valores[maximo]/pesos[maximo])))
                maximo = i;

        usado[maximo] = 1;
        peso_atual -= pesos[maximo]; // com o objeto já na mochila, posso carregar menos peso
        valor_total += valores[maximo];
        if (peso_atual >= 0)
            printf("objeto %d (%d$, %dKg) adicionado na mochila. Espaco sobrando: %d.\n", maximo + 1, valores[maximo], pesos[maximo], peso_atual);
        else {
            valor_total -= valores[maximo];
        }
    }
    return valor_total;
}
 
int max(int a, int b) { return (a > b) ? a : b; }

