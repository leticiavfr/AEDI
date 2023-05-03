/*Tia Joana é uma respeitada professora e tem vários alunos. Em sua última aula, ela prometeu que iria sortear um aluno para ganhar um bônus 
* especial na nota final: ela colocou N pedaços de papel numerados de 1 a N em um saquinho e sorteou um determinado número K; o aluno premiado 
* foi o K-ésimo aluno na lista de chamada. O problema é que a Tia Joana esqueceu o diário de classe, então ela não tem como saber qual número 
* corresponde a qual aluno. Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem 
* alfabética, mas os alunos dela estão muito ansiosos e querem logo saber quem foi o vencedor. Dado os nomes dos alunos da Tia Joana e o número 
* sorteado, determine o nome do aluno que deve receber o bônus.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[21];
} Alunos;

int Compara(const void *a, const void *b) {
	Alunos *i = (Alunos *)a, *j = (Alunos *)b;
	
	return strcmp(i->nome, j->nome);
}

int main (){
    int n, k, i;
    
    Alunos a[20];

    do{
        scanf ("%d", &n);
    } while (n<1 || n>100); 

    do{
        scanf ("%d", &k);
    } while (k<1 || k>100); 

    for (i=0; i<n; i++){
        scanf ("%s", a[i].nome);
    }

    qsort(a, n, sizeof(Alunos), Compara);

    printf("%s\n", a[k-1].nome);
	
	return 0;
}