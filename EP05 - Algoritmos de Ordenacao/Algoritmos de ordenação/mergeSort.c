#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void merge(int *a, int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1, n2 = direita - meio;
    int E[n1], D[n2];

    for (i = 0; i < n1; i++){
        E[i] = a[esquerda + i];
    }

    for (j = 0; j < n2; j++){
        D[j] = a[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esquerda;

    //Compara os elementos do vetor E com o vetor D e, dependendo do caso, os insere no vetor original a
    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            a[k] = E[i];
            i++;
        } 
        else{
            a[k] = D[j];
            j++;
        }
        
        k++;
    }

    //Se o comando while anterior não tiver percorrido o valor de n1 ou n2 completamente, adiciona os elementos restantes no vetor a
    while (i < n1){
        a[k] = E[i];
        i++;
        k++;
    }

    while (j < n2){
        a[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int *a, int esquerda, int direita) {
    if (esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(a, esquerda, meio);
        mergeSort(a, meio + 1, direita);

        merge(a, esquerda, meio, direita);
    }
}

int main(){
    clock_t t; 
    int vetor[] = {56, 72, 84, 43, 28, 31};
    int i, n = sizeof(vetor) / sizeof(vetor[0]); 
    
    t = clock(); //Armazena o tempo de execução
    mergeSort(vetor, 0, n-1);
    t = clock() - t; //Tempo final - tempo inicial
    
    printf ("Valores ordenados:\n");
    for(i = 0; i < n; i++){
        printf ("%d\n", vetor[i]);
    }
    
    //Imprime o tempo de execução convertido de segundos para milissegundos
    printf("Tempo de execução: %lf milissegundos", ((double)t)/((CLOCKS_PER_SEC/1000))); 
    
    return 0;
}