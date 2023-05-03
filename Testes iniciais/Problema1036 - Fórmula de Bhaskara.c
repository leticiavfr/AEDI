/*O programa calcula as raízes da equação de Bhaskara*/

#include <stdio.h>
#include <math.h>

void CalculaBhaskara(double A, double B, double C){
    double delta, bhaskara1, bhaskara2;

    delta = (B*B) - 4*A*C;
    
    if (A == 0.0 || delta < 0.0)
        printf ("Impossivel calcular\n");

    else{
        bhaskara1 = (-B + sqrt(delta)) / (2*A);
        bhaskara2 = (-B - sqrt(delta)) / (2*A);

        printf ("R1 = %.5lf\nR2 = %.5lf\n", bhaskara1, bhaskara2);
    }
}

int main (){
    double A, B, C;

    scanf ("%lf %lf %lf", &A, &B, &C);

    CalculaBhaskara(A, B, C);

    return 0;
}