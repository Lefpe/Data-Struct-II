#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct proc{
    char data_inicio [11]; //formato yyyy-mm-dd. ex: 2024-03-15
    char nome [20];
    int qnt_memoria;
    struct proc *prox;
    struct proc *ant;
} Processo;

//inserir dados//
 Processo *lista (){
      Processo *novo = malloc(sizeof(Processo));
        printf ("digite seu nome: ");
        scanf ("%s", novo->nome );
        printf ("digite a sua data (FORMATO: AAAA-MM-DD): \n");
        scanf ("%s", novo->data_inicio);
        printf ("Digite a quantidade de memória: \n");
        scanf("%d", novo->qnt_memoria);
        novo->prox = NULL; 
        return novo; 
 }
//comparar memória//
void comparar_memoria(){

}

void BubbleSort(){
}
void quickSort(){
}
void insertionSort(){
}
int main (void){

int opcao;

}
