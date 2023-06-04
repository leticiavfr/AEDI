#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Palavra {
    char a[6];
} palavra;

typedef struct Texto {
    char b[100000];
} texto;

/* Recebe uma palavra a[1..m] e um texto b[1..n], com m >= 1 e n >= 0, e devolve o número de ocorrências de a em b. 
* Supõe que cada elemento de a e b pertence ao conjunto de caracteres 0..255. */
int BoyerMoore(palavra a, int m, texto b, int n) {
    int T1[256], i, k, r, ocorrs;

    /* pré-processamento da palavra a */
    for (i = 0; i < 256; i++)
        T1[i] = m;

    for (i = 0; i < m; i++)
        T1[tolower(a.a[i])] = m - i - 1;

    /* busca da palavra a no texto b */
    ocorrs = 0;
    k = m;

    while (k <= n) {
        r = 0;

        while (r < m && tolower(a.a[m - r - 1]) == tolower(b.b[k - r - 1]))
            r += 1;

        if (r == m)
            ocorrs += 1;

        if (k == n)
            k += 1;
        else
            k += T1[tolower(b.b[k])] + 1;
    }

    return ocorrs;
}

int main() {
    palavra p;
    texto t;
    int n, ocorrencia;

    strncpy(p.a, "zelda", sizeof(p.a));
    fgets(t.b, sizeof(t.b), stdin);

    n = strlen(t.b);

    ocorrencia = BoyerMoore(p, strlen(p.a), t, n);

    if (ocorrencia > 0) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}