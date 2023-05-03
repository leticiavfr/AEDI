/*O programa  recebe duas strings e as combina, alternando as letras de cada string, começando com a primeira letra da primeira string, 
seguido pela primeira letra da segunda string, em seguida pela segunda letra da primeira string, e assim sucessivamente*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *CombinaStrings (char *str1, char *str2){
    char *str3 = malloc(strlen(str1) + strlen(str2) + 1);
    int i, j, aux;
    
    i = j = aux = 0;

    while (str1[i] != '\0' || str2[j] != '\0'){
        if (str1[i]!='\0')
            str3[aux++] = str1[i++];
        if (str2[j]!='\0')
            str3[aux++] = str2[j++];
    }

    str3[aux++] = '\0';

    return str3;
}

int main (){
    int n, i = 0, j = 0;
    char str1[50], str2[50], *str3;

    scanf ("%d", &n);

    while (n>0){
        scanf ("%s %s", str1, str2);

        printf ("%s\n", CombinaStrings(str1, str2));

        n--;
    }
    
    return 0;
}