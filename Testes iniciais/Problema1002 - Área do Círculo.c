/*O programa calcula a área de uma circunferência utilizando a fórmula área = π * (raio*raio)*/

#include <stdio.h>

#define N 3.14159

int main (){
    double raio, area;

    scanf ("%lf", &raio);

    area = N * (raio * raio);

    printf ("A=%.4lf\n", area);

    return 0;
}