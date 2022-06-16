/*Felippe percebeu que após ter resolvido o problema da vidraçaria poderia levar para casa os retalhos de vidro que coubesse em sua maleta.
Faça um programa que leia do usuário a capacidade da maleta de Felippe e o nome de um arquivo que irá conter o valor e o tamanho de todos retalhos
disponíveis para Felippe. O objetivo e maximizar o valor a ser levado por ele.
Mostre na tela qual a combinação de retalhos a ser levado por Felippe para que ele maximize o valor que está levando e o valor que ele irá levar
utilizando uma solução recursiva.

Exemplo do arquivo (tamanho;valor):
2;5
3;7
4;5
2;4
3;5*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *arq;
    
    char linha[100];
    char nome_arquivo[100];

    int i = 1;
    int j = 0;
    int tam_vao = 0;

    int tamanho, valor;
    int numero;
    int vetor[100];

    printf("\nDigite o nome do arquivo: ");
    scanf("%s",&nome_arquivo);

    printf("\nDigite o tamanho do vão a ser preenchido: ");
    scanf("%s",&tam_vao);

    arq = fopen(nome_arquivo, "rt");

    if(arq==NULL){
        printf("\nArquivo não encontrado");
        return;
    }

    i = 0;

    while(fscanf(arq,"%d;%d\n",&tamanho,&valor)!=EOF){
        printf("\nTamanho: %d\nValor: %d",tamanho,valor);
        vetor[i] = numero;
        i++;
    }

    while(i--){
        printf("\nNúmero: %d",vetor[i]);
    }

    int n = 0;

    //int result = dinamica(vetor, n+1, tam_vao);

    fclose(arq);

    return 0;
}
