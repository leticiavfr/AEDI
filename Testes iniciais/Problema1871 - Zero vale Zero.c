/*O programa some dois números e, caso o resultado tenha algum algarismo zero, ele é retirado antes da soma ser exibida*/

#include <stdio.h>

void TiraZero(int m, int n){
    int soma, i, count = 0, j = 0, resultado = 0, aux;
    int vet[10];
    
    if (m!=0 && n!=0){
        soma = m + n;
        aux = soma;
        
        for (i=0; i<10; i++){
            if (soma >= 1 && soma <= 9){
                vet[i] = soma;
                count++;
                break;
            }
            else{
                vet[i] = soma%10;
                soma/=10;
                count++;
            }
        }
        
        for (i=0; i<count; i++){
            if (vet[i] == 0)
            j++;
        }
        
        if (j == 0)
            printf ("%d\n", aux);
        else{
            do{
                resultado = aux/10 + aux%10;
                aux = resultado;
                j--;
            } while (j>0);
            printf ("%d\n", resultado);
        }
    }
}

int main(){
    int m, n;

    do{
        scanf ("%d %d", &m, &n);
        TiraZero(m, n);
    } while (m!=0 && n!=0);

    return 0;
}