#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void insertionSort(int *a, int n){
    int i, j, tmp;
    
    for(i = 1; i < n; i++){
        tmp = a[i];
        //Compara com o valor anterior e troca
        for(j = i-1; j >= 0 && tmp < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

int main(){
    clock_t t; 
    int vetor[] = {56, 72, 84, 43, 28, 31};
    int i, n = sizeof(vetor) / sizeof(vetor[0]); 
    
    t = clock(); //Armazena o tempo de execução
    insertionSort(vetor, n);
    t = clock() - t; //Tempo final - tempo inicial
    
    printf ("Valores ordenados:\n");
    for(i = 0; i < n; i++){
        printf ("%d\n", vetor[i]);
    }
    
    //Imprime o tempo de execução convertido de segundos para milissegundos
    printf("Tempo de execução: %lf milissegundos", ((double)t)/((CLOCKS_PER_SEC/1000))); 
    
    return 0;
}