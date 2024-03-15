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
 }]
//comparar tamanho //
//quantidade processo//
void comparar_memo(Processo *tm1, Processo *tm2){
        Processo 

}
//ordenar por data
void BubbleSort(){

}
//particionar quickSort//
int particionar (Processo *lista[], int atual, int proximo) {]
//pivot//
    Processo *pivot = lista[proximo];
    int i = atual - 1;

    for (int j = atual; j < proximo; j++) {
        if (compararDados(lista[j], pivot) < 0) {

         
}
    //ordenando com quickSort//
        //ordena pela quantidade de memoria//
void quickSort(proc *lista [],  int atual, int proximo){
if (atual < proximo){
 int indiceParticao = particionar(lista, atual, proximo);

        quickSort(lista, atual, indiceParticao - 1);
        quickSort(lista, indiceParticao + 1, proximo);
    }
}


}
//ordena pelo nome//
void insertionSort(){
}
int main (void){

int opcao;
printf("--menu de tarefas-- \n\n");
    printf("1) inserir tarefas \n 2) mostrar ordem por nome 3) mostrar ordem por data 4) mostrar ordem por memória \n sair ");
    scanf("%d", opcao);
switch (opcao){
case '1':
break;
case  '2':
break;
case '3':
break;
case '4':
break;
default:
printf ("saindo...");
break:

}

}
