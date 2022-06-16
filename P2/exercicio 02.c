/*Felippe é funcionário de uma vidraçaria e precisa encontrar retalhos de vidro que consigam preencher em vão em uma obra.
Seu programa deverá solicitar ao usuário o tamanho do vão a ser preechido e o nome do arquivo que contem o tamanho dos retalhos.
Exemplo do arquivo:
10
13
15
12
1
5
19
45
Para o tamanho dos retalhos lidos diga se é possível ou não preencher o vão utilizando programação dinâmica.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subset(int *retalhos, int qtdRetalhos, int valor, int somatorio, int tamVao);

int main()
{
	int i=0, qtdRetalhos = 0, resultado = 0;
	int tamVao = 0, totalRetalhos = 0, somatorio = 0, *retalhos;
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
        	somatorio = somatorio + retalhos[i];
            printf("\n%d) Retalho: %d", i, retalhos[i]);
            i++;
        }

		resultado = subset(retalhos, qtdRetalhos, 0, somatorio, tamVao);
		
		if(resultado){
			printf("\n\nResultado: e possivel preencher.");
		}else{
			printf("\n\nResultado: nao possivel preencher.");
		}
		
        fclose(arq);
    }

    return 0;
}

int subset(int *retalhos, int qtdRetalhos, int valor, int somatorio, int tamVao){
    if (qtdRetalhos == -1)
        return 0;

    if (valor + retalhos[qtdRetalhos] == tamVao)
        return 1;

    return subset(retalhos, qtdRetalhos - 1, valor + retalhos[qtdRetalhos], somatorio - retalhos[qtdRetalhos], tamVao) || 
				subset(retalhos, qtdRetalhos - 1, valor, somatorio - retalhos[qtdRetalhos], tamVao);
}

int valorMaximo(int a, int b){
	if(a > b){
		return a;
	}
	
	return b;
}