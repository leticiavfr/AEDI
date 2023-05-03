/*O programa dita as risadas digitais mais engraçadas de acordo com a seguinte regra: as sequências de vogais são iguais quando lidas na 
ordem natural (da esquerda para a direita) ou na ordem inversa (da direita para a esquerda), ignorando as consoantes*/

#include <stdio.h>
#include <string.h>

int main(){
    char risada[50], novarisada[50] = {0}, aux[50] = {0};
    int i, j=0;

    scanf ("%s", risada);

    for (i=0; i<strlen(risada); i++){
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u'){
            novarisada[j] = risada[i];
            j++;
        }
    }
    
    novarisada[j] = '\0'; 

    j--;

    for (i=0; i<strlen(novarisada); i++){
        aux[i] = novarisada[j];
        j--;
    }
    
    aux[i] = '\0'; 

    if (strcmp(aux, novarisada) == 0){
        printf ("S\n");
    }
    else
        printf ("N\n");

    return 0;
}