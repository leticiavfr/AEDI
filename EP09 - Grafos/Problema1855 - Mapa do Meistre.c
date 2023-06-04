#include <stdio.h>
#include <string.h>

int main(){
    int x, y, i, area, altura = 0, largura = 0, validez, comando;

    scanf("%d %d", &x, &y);

    char mapa[y][x+1];

    for (i = 0; i < y; i++)
        scanf("%s", mapa[i]);

    area = x * y;

    for (validez = 1; validez <= area; ){
        if (mapa[altura][largura] == '>')
        {
            largura++; 
            validez++; 
            comando = 1;
            if(largura >= x) 
                break;
        }
        else if (mapa[altura][largura] == 'v')
        {
            altura++; 
            validez++; 
            comando = 2;
            if(altura >= y) 
                break;
        }
        else if (mapa[altura][largura] == '<')
        {
            largura--; 
            validez++; 
            comando = 3;
            if(largura < 0) 
                break;
        }
        else if (mapa[altura][largura] == '^')
        {
            altura--; 
            validez++; 
            comando = 4;
            if(altura < 0) 
                break;
        }
        else if (mapa[altura][largura] == '*')
        {
            validez = 1000;
            break;
        }
        else if (mapa[altura][largura] == '.'){
            if (comando == 1){
                largura++; 
                validez++;
                if(largura >= x) 
                    break;
            }
            else if (comando == 2){
                altura++; 
                validez++;
                if(altura >= y) 
                    break;
            }
            else if (comando == 3){
                largura--; 
                validez++;
                if(largura < 0) 
                    break;
            }
            else if (comando == 4){
                altura--; 
                validez++;
                if (altura < 0) 
                    break;
            }
        }
    }

    if (validez == 1000) 
        printf("*\n");
    else 
        printf("!\n");

    return 0;
}