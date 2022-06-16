#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define d 256

void search(char texto_padrao[], char texto[], int qtd);

int main(){
	char texto[] = "ABAAABCDACDABCAAABCDDAACCBADCABCDDDBBABCAB";
	char texto_padrao[] = "ABC";
	int qtd = 101;

	search(texto_padrao, texto, qtd);
	return 0;
}

void search(char texto_padrao[], char texto[], int qtd){
	int tam_texto_padrao = strlen(texto_padrao);
	int tam_texto = strlen(texto);
	int i, j, p=0, t=0, h=1;

	for(i=0;i<(tam_texto_padrao-1);i++){
        h = (h*d)%qtd;
    }
		
	for(i=0;i<tam_texto_padrao;i++){
		p = (d*p+texto_padrao[i])%qtd;
		t = (d*t+texto[i])%qtd;
	}

	for(i=0;i<=tam_texto-tam_texto_padrao;i++){
		if(p==t){
			for(j=0;j<tam_texto_padrao;j++){
				if(texto[i+j] != texto_padrao[j]){
                    break;
                }
			}

			if(j==tam_texto_padrao){
                printf("Texto padrão encontrado no index %d \n", i);
            }
		}

		if(i<(tam_texto-tam_texto_padrao)){
			t = (d*(t - texto[i]*h) + texto[i+tam_texto_padrao])%qtd;

			if (t<0){
                t = (t+qtd);
            }
		}
	}
}