#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void sacodeHeap(int *a, int n, int i) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    //Compara se o filho da esquerda é maior que o valor da variável maior
    if (esquerda < n && a[esquerda] > a[maior]) {
        maior = esquerda;
    }

    //Compara se o filho da direita é maior que o valor da variável maior
    if (direita < n && a[direita] > a[maior]) {
        maior = direita;
    }

    //Se o valor de maior for diferente da sua posição inicial, os valores do vetor são trocados de lugar
    if (maior != i) {
        int tmp = a[i];
        a[i] = a[maior];
        a[maior] = tmp;

        sacodeHeap(a, n, maior);
    }
}

void heapSort(int *a, int n){
	int i, tmp;

	for (i = n/2 - 1; i >= 0; i--){
		sacodeHeap(a, n, i);
	}

	for (i = n - 1; i >= 0; i--){
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		
		sacodeHeap(a, i, 0);
	}
}

int main(){
    clock_t t; 
    int vetor[] = {56, 72, 84, 43, 28, 31};
    int i, n = sizeof(vetor) / sizeof(vetor[0]); 

    t = clock(); //Armazena o tempo de execução
    heapSort(vetor, n);
    t = clock() - t; //Tempo final - tempo inicial
    
    printf ("Valores ordenados:\n");
    for(i = 0; i < n; i++){
        printf ("%d\n", vetor[i]);
    }
    
    //Imprime o tempo de execução convertido de segundos para milissegundos
    printf("Tempo de execução: %lf milissegundos", ((double)t)/((CLOCKS_PER_SEC/1000))); 
    
    return 0;
}