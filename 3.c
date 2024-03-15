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
        scanf("%d", &novo->qnt_memoria);
        novo->prox = NULL; 
        return novo; 
 }
//parte 1, quicksort//
// Particionar para o Quick Sort
int particionar(Processo *lista[], int atual, int proximo) {
    Processo *pivot = lista[proximo];
    int i = atual - 1;

    for (int j = atual; j < proximo; j++) {
        if (strcmp(lista[j]->data_inicio, pivot->data_inicio) < 0) {
            i++;
        
            Processo *temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
        }
    }
    // Troca lista[i+1] com lista[proximo] (o pivô)//
    Processo *temp = lista[i + 1];
    lista[i + 1] = lista[proximo];
    lista[proximo] = temp;
    return i + 1;
}
//parte2//
// Ordenar por data usando Quick Sort
void quickSort(Processo *lista[], int atual, int proximo) {
    if (atual < proximo) {
        int indiceParticao = particionar(lista, atual, proximo);
        quickSort(lista, atual, indiceParticao - 1);
        quickSort(lista, indiceParticao + 1, proximo);
    }
}
//quicksort finalizado//
//ordenar por nome//
// Ordenar por nome usando Insertion Sort
void insertionSort(Processo **processos[], int n) {
    int i, j;
    Processo *key;

    for (i = 1; i < n; i++) {
        key = processos[i];
        j = i - 1;
//comparei// 
        while (j >= 0 && strcmp(processos[j]->nome, key->nome) > 0) {
            processos[j + 1] = processos[j];
            j = j - 1;
        }
        processos[j + 1] = key;
    }
}
//ordenar pela data de inicio//
void BubbleSort (){
}



int main (void){

int opcao;
 Processo *processos;
    int num_processos = 0; 
   
printf("--menu de tarefas-- \n\n");
    printf("1) inserir tarefas \n 2) mostrar ordem por nome 3) mostrar ordem por data 4) mostrar ordem por memória \n sair ");
    scanf("%d", &opcao);
switch (opcao){
case '1':
break;
case  '2':
if (Processo == NULL){
printf ("lista vazia");
}
else {
                insertionSort (processos, num_processos);
                imprimir_processos (processos, num_processos);
}
break;
case '3':
if (Processo == NULL){
printf ("lista vazia");
}
// Ordenar por data e imprimir
                quickSort(processos, 0, num_processos - 1);
                imprimir_processos(processos, num_processos);
                break;
break;
case '4':
if (Processo== NULL){
printf ("lista vazia");
}else{
 // Ordenar por memória e imprimir
                BubbleSort();
                imprimir_processos(processos, num_processos);
}

                break;
break;
default:
printf ("saindo...");
break;

}

}

