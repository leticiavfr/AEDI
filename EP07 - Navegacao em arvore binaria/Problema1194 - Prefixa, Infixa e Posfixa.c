#include <stdio.h>
#include <stdlib.h>

struct cel {
    char conteudo;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;

// Função auxiliar para criar um novo nó da árvore
no* criaNo(char conteudo) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->conteudo = conteudo;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

int aux = 0;
// Função para construir a árvore binária a partir dos percursos prefixo e infixo
no* arvore(char* prefixo, char* infixo, int comeco, int fim) {
    int posicao, i;

    if (comeco > fim) {
        return NULL;
    }

    // Cria um nó com o próximo caractere do percurso prefixo
    no* novoNo = criaNo(prefixo[aux++]);

    // Verifica se o nó não tem filhos
    if (comeco == fim) {
        return novoNo;
    }

    // Encontra a posição do nó atual no percurso infixo
    for (i = comeco; i <= fim; i++) {
        if (infixo[i] == novoNo->conteudo) {
            posicao = i;
            break;
        }
    }

    // Constrói a subárvore esquerda e a subárvore direita recursivamente
    novoNo->esq = arvore(prefixo, infixo, comeco, posicao - 1);
    novoNo->dir = arvore(prefixo, infixo, posicao + 1, fim);
    
    return novoNo;
}

void posfixa(no *pRaiz){
    if(pRaiz != NULL){
        posfixa(pRaiz->esq);
        posfixa(pRaiz->dir);
        printf("%c", pRaiz->conteudo);
    }
}

int main (){
    int c, n, count;
    char prefixa[53], infixa[53];

    scanf ("%d", &c);

    for (count = 0; count < c; count++) {
        scanf("%d", &n);
        scanf("%s", prefixa);
        scanf("%s", infixa);
        
        no* raiz = arvore(prefixa, infixa, 0, n - 1);
        
        posfixa(raiz);
        printf("\n");
        
        // Libera a memória alocada pela árvore
        free(raiz);
        
        aux = 0;
    }

    return 0;
}