#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define NO_OF_CHARS 256

int max(int a, int b);
void bad_char_heuristic(char *str, int size, int bad_char[NO_OF_CHARS]);
void search(char *texto, char *texto_padrao);

int main(){
	char texto[] = "ABAAABCDACDABCAAABCDDAACCBADCABCDDDBBABCAB";
	char texto_padrao[] = "ABC";
	search(texto, texto_padrao);
	return 0;
}

int max(int a, int b) { 
    return (a>b)? a:b; 
}

void bad_char_heuristic(char *str, int size, int bad_char[NO_OF_CHARS]){
	int i;

	for(i=0;i<NO_OF_CHARS;i++){
        bad_char[i] = -1;
    }
		
	for(i=0;i<size;i++){
        bad_char[(int) str[i]] = i;
    }
}

void search(char *texto, char *texto_padrao){
	int m = strlen(texto_padrao);
	int n = strlen(texto);

	int bad_char[NO_OF_CHARS];

	bad_char_heuristic(texto_padrao, m, bad_char);

	int s = 0; 

	while(s <= (n - m)){
		int j = m-1;

		while(j >= 0 && texto_padrao[j] == texto[s+j]){
            j--;
        }

		if (j < 0){
			printf("\n Texto padrão ocorre em = %d", s);

			s += (s+m < n)? m-bad_char[texto[s+m]] : 1;

		}else{
			s += max(1, j - bad_char[texto[s+j]]);
		}
	}
}

