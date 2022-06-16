#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main(){
    char string[100], combinacao[20], c;
    int i=0, j=0, index;

    printf("\nDigite o texto: ");

    do{
        fflush(stdin);
        c = getchar();
        string[i++] = tolower(c);
    }while(c!='\n');

    string[i-1] = '\0';

    printf("\nDigite o subtexto: ");
    i = 0;

    do{
        fflush(stdin);
        c = getchar();
    }while(c!='n');
}
int main(){

    do
    {
        fflush(stdin);
        c = getchar();
        matchcase[i++] = tolower(c);
    } while (c != '\n');

    matchcase[i - 1] = '\0';
    
    for (i = 0; i < strlen(string) - strlen(matchcase) + 1; i++)
    {
        index = i;
        if (string[i] == matchcase[j])
        {
            do
            {
                i++;
                j++;
            } while(j != strlen(matchcase) && string[i] == matchcase[j]);
            if (j == strlen(matchcase))
            {
                printf("A combinação encontra-se na posição %d para %d.\n", index + 1, i);
                return 0;
            }
            else
            {
                i = index + 1;
                j = 0;
            }
        }
    }
    printf("Nenhum subtexto foi encontrado no texto\n");
 
    return 0;
}