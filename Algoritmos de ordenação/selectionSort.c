#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort (int *a, int n) {
    int i, j, min, aux;
    
    //Considera o primeiro elemento do vetor como o menor e compara todos os outros elementos com ele
    for (i = 0; i < n; i++){
        min = i;
        for (j = i+1; j < n; j++){
            //Se um elemento for menor que o menor anteriormente atribuído, a variável min recebe esse elemento
            if (a[j] < a[min]){
                min = j;
            }
        }
        //Se min for diferente do índice inicialmente atribuído, as posições são trocadas no vetor
        if (i != min){
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }
}

int main(){
    clock_t t; 
    int vetor[] = {56, 72, 84, 43, 28, 31};
    int i, n = sizeof(vetor) / sizeof(vetor[0]); 
    
    t = clock(); //Armazena o tempo de execução
    selectionSort(vetor, n);
    t = clock() - t; //Tempo final - tempo inicial
    
    printf ("Valores ordenados:\n");
    for(i = 0; i < n; i++){
        printf ("%d\n", vetor[i]);
    }
    
    //Imprime o tempo de execução convertido de segundos para milissegundos
    printf("Tempo de execução: %lf milissegundos", ((double)t)/((CLOCKS_PER_SEC/1000))); 

    return 0;
}