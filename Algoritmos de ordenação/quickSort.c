#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

int separa (int *a, int inicio, int fim){
    int pivo = a[fim]; 
    int tmp, i, j = inicio - 1;
    
    for (i = inicio; i < fim; i++){
        //Se o vetor na posição inicial for menor ou igual ao vetor na última posição, eles são trocados de lugar
        if (a[i] <= pivo) {
            j++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        } 
    }
    
    //Troca os elementos do vetor de posição
    tmp = a[j + 1];
    a[j + 1] = a[fim];
    a[fim] = tmp;
    
    return j+1; 
}

void quickSort (int *a, int inicio, int fim){
    //Se o início for menor que o final, as funções para ordenar o vetor são chamadas
    if (inicio < fim) {                   
        int pivo = separa (a, inicio, fim);   
        quickSort (a, inicio, pivo - 1);      
        quickSort (a, pivo + 1, fim);  
    }
}

int main(){
    clock_t t; 
    int vetor[] = {56, 72, 84, 43, 28, 31};
    int i, n = sizeof(vetor) / sizeof(vetor[0]); 

    t = clock(); //Armazena o tempo de execução
    quickSort(vetor, 0, n);
    t = clock() - t; //Tempo final - tempo inicial
    
    printf ("Valores ordenados:\n");
    for(i = 0; i < n; i++){
        printf ("%d\n", vetor[i]);
    }
    
    //Imprime o tempo de execução convertido de segundos para milissegundos
    printf("Tempo de execução: %lf milissegundos", ((double)t)/((CLOCKS_PER_SEC/1000))); 
    
    return 0;
}