/* O programa lê um vetor X[10] e substitui todos os valores nulos e negativos do vetor por 1.*/

#include <stdio.h>

int main (){
    int X[10], i;

    for (i=0; i<10; i++)
        scanf ("%d", &X[i]);
    
    for (i=0; i<10; i++){
        if (X[i]<1)
            X[i] = 1;
        printf ("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}