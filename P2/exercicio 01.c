/*Felippe é funcionário de uma vidraçaria e precisa encontrar retalhos de vidro que consigam preencher um vão em uma obra.
Seu programa deverá solicitar ao usuário o tamanho do vão a ser preenchido e o nome do arquivo que contem o tamanho dos retalhos.
Exemplo do arquivo
10
13
15
12
1
5
19
45
Para o tamanho dos retalhos lidos diga se é possível ou não preencher o vão utilizando uma solução recursiva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int backPack(int capacidade, int retalhos[], int qtdRetalhos);

int main()
{
	int i=0, qtdRetalhos = 0, resultado = 0;
	int tamVao = 0, totalRetalhos = 0, *retalhos;
    char nome_arquivo[100];
    char linha[500];

    FILE *arq;

	printf("\nDigite o tamanho do vao: ");
	scanf("%d", &tamVao);
    
	printf("\nDigite o nome do arquivo: ");
    fflush(stdin);
    
    fgets(nome_arquivo, 50, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
    	while (fgets(linha, 500, arq) != NULL)
        {
        	qtdRetalhos++;
        }
		
		fclose(arq);
		
		arq = fopen(nome_arquivo, "r");
        
        retalhos = (int *) malloc(sizeof(int));
		while (i != qtdRetalhos)
        {	
        	fscanf(arq,"%d", &retalhos[i]);
            printf("\n%d) Retalho: %d", i, retalhos[i]);
            i++;
        }

		resultado = backPack(tamVao, retalhos, qtdRetalhos);
		
		if(resultado == tamVao){
			printf("\n\nResultado: e possivel preencher.");
		}else{
			printf("\n\nResultado: nao possivel preencher.");
		}
		
        fclose(arq);
    }

    return 0;
}

int backPack(int capacidade, int retalhos[], int qtdRetalhos){
	
	if(qtdRetalhos == 0 || capacidade == 0){
		return 0;
	}
	
	if (retalhos[qtdRetalhos - 1] > capacidade){
		return backPack(capacidade, retalhos, qtdRetalhos - 1);
	}
	
	return valorMaximo(retalhos[qtdRetalhos - 1] + backPack(capacidade - retalhos[qtdRetalhos - 1], retalhos, qtdRetalhos - 1), 
	   				    backPack(capacidade - retalhos[qtdRetalhos - 1], retalhos, qtdRetalhos - 1));
}

int valorMaximo(int a, int b){
	if(a > b){
		return a;
	}
	
	return b;
}