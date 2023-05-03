/*O programa troca cada letra de uma sentença pelo seu equivalente em n posições à esquerda do alfabeto*/

#include <stdio.h>
#include <string.h>

void Decodifica (char *sentenca, int variacao){
    char resultado[50] = {0};
    int i, j, aux = 0;
    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    if (variacao == 0)
        printf("%s\n", sentenca);
    else {
        for (i = 0; i < strlen(sentenca); i++){
            for (j = 0; j < 26; j++){
                if (sentenca[i] == alfabeto[j]){
                    aux = j - variacao;
                    if (aux < 0){
                        aux*= -1;
                        resultado[i] = alfabeto[26-aux];
                    }
                    else
                        resultado[i] = alfabeto[aux];
                }
            }
        }
        printf ("%s\n", resultado);
    }

}

int main (){
    int n, variacao;
    char sentenca[50];

    scanf ("%d", &n);

    while (n>0){
        scanf ("%s", sentenca);
        do{
            scanf ("%d", &variacao);
        } while (variacao<0 || variacao>25);

        Decodifica (sentenca, variacao);

        n--;
    }

    return 0;
}