#include <stdio.h>
#include <string.h>

int main(){
    int n, i, k, aux, count;
    char s[20];
    
    scanf ("%d", &n);
    
    for (i=0; i<n; i++){
        scanf ("%d", &k);
        aux = k;
        
        char temp[20];
        count = 0;
        
        do {
            scanf ("%s", s);
            
            if (aux == k)
                strcpy (temp, s);
            
            if (aux < k){
                if (strcmp (temp, s) != 0)
                    count++;
            }
            aux--;
        } while (aux>0);
        
        if (count == 0){
            printf ("%s\n", s);
        }
        else {
            printf ("ingles\n");
        }
    }

    return 0;
}