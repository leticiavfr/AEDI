/*O programa lê em uma única linha uma lista de amigos L, contendo somente o primeiro nome e separados por um espaço em branco. Na segunda linha
* deve ser informada uma nova lista de amigos N. Na última linha, o nome do amigo S da rede que deseja indicar também essa nova lista de amigos 
* N. Caso não queira indicar para ninguém a nova lista de amigos, basta digitar na última linha a palavra “nao”. O programa deverá exibir a nova 
* lista de amigos atualizada. Se houver indicação de um amigo da lista, os novos amigos deverão ser inseridos antes do nome do amigo indicado. 
* Caso não haja indicação, os novos nomes deverão ser inseridos no fim da lista de amigos.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    char nome[100];
    struct no *proximo;
} *no;

no Cria (char *amigo, int tam){
    int i;
    no novo = (no) malloc(sizeof(struct no));
    
    for (i = 0; i < tam; i++){
        novo->nome[i] = amigo[i];
    }

    novo->nome[i] = '\0';
    novo->proximo = NULL;

    return novo;
}

no Insere (no lista, char *amigo, int tam){
    int i;
    no aux = lista;

    no novo = (no) malloc(sizeof(struct no));

    for (i = 0; i < tam; i++){
        novo->nome[i] = amigo[i];
    }
    
    novo->nome[i] = '\0';
    novo->proximo = NULL;
    
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = novo;

    return lista;
}

no Quebra (no lista, char *amigos){
    int i = 0, j, lista_vazia = 0;
    char aux;

    for (j = 0; j < 100; j++){
        aux = amigos[j];
        if (aux == ' ' || aux == '\0'){
            if(lista_vazia == 0){
                lista = Cria(amigos + i, j-i);
                i = j;
                lista_vazia = 1;
                if(aux == '\0') 
                    break;
            } 
            else {
                lista = Insere(lista, amigos + i + 1, j-i-1);
                i = j;
                if(aux == '\0') 
                    break;
            }
        }
    }

    return lista;
}

no Insere_fim (no Lista1, no NovaLista){
    no aux = Lista1;

    while (aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = NovaLista;

    return Lista1;
}

no Insere_meio (no Lista1, no NovaLista, char *S){
    int retorno;
    no aux = Lista1;
    no aux2;

    retorno = (int) strcmp(aux->nome, S);
    if(retorno == 0) 
        return Insere_fim(NovaLista, Lista1);

    while(retorno != 0){
        retorno = (int) strcmp(aux->proximo->nome, S);

        if(retorno == 0) 
            break;
    
        aux = aux->proximo;
    }

    Insere_fim(NovaLista, aux->proximo);

    aux->proximo = NovaLista;

    return Lista1;
}

void Imprime (no Lista1){
    no aux = Lista1;

    printf("%s", aux->nome);

    while (aux->proximo != NULL){
        aux = aux->proximo;
        if(aux->nome != NULL) 
            printf(" %s", aux->nome);
    }  
}

void Limpa (no Lista1){
    no aux = Lista1;
    no aux2 = Lista1->proximo;

    while(aux2 != NULL){
        free(aux);
        aux = aux2;
        aux2 = aux2->proximo;
    }
}

int main (){
    int aux, retorno = 0;
    char L[100], NL[100], S[100];
    no Lista1 = NULL;
    no NovaLista = NULL;

    fgets (L, 100, stdin);
    aux = strlen (L);
    L[aux-1] = '\0';
    Lista1 = Quebra(Lista1, L);

    fgets (NL, 100, stdin);
    aux = strlen (NL);
    NL[aux-1] = '\0';
    NovaLista = Quebra(NovaLista, NL);

    fgets (S, 100, stdin);
    aux = strlen (S);
    S[aux-1] = '\0';
    retorno = (int)strcmp(S, "nao");

    if (retorno == 0){
        Lista1 = Insere_fim(Lista1, NovaLista);
    } 
    else {
        Lista1 = Insere_meio(Lista1, NovaLista, S);
    }

    Imprime(Lista1);
    Limpa(Lista1);

    return 0;
}