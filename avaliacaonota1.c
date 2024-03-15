#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct proc {
    char data_inicio[11]; // formato yyyy-mm-dd. ex: 2024-03-15
    char nome[20];
    int qnt_memoria;
    struct proc *prox;
    struct proc *ant;
} Processo;

//aux
void trocar(Processo **a, Processo **b);

// Função para inserir dados
Processo *lista() {
    Processo *novo = malloc(sizeof(Processo));
    printf("Digite seu nome: ");
    scanf("%s", novo->nome);
    printf("Digite a sua data (FORMATO: AAAA-MM-DD):\n");
    scanf("%s", novo->data_inicio);
    printf("Digite a quantidade de memória:\n");
    scanf("%d", &novo->qnt_memoria);
    novo->prox = NULL;
    return novo;
}
//parte 1//
// Particionar para o QuickSort
int particionar(Processo *lista[], int atual, int proximo) {
    Processo *pivot = lista[proximo];
    int i = atual - 1;

    for (int j = atual; j < proximo; j++) {
        if (strcmp(lista[j]->data_inicio, pivot->data_inicio) < 0) {
            i++;
            trocar(&lista[i], &lista[j]);
        }
    }
    trocar(&lista[i + 1], &lista[proximo]);
    return i + 1;
}
//parte 2//
// Ordenar por data usando Quick Sort
void QuickSort(Processo *lista[], int atual, int proximo) {
    if (atual < proximo) {
        int indiceParticao = particionar(lista, atual, proximo);
        QuickSort(lista, atual, indiceParticao - 1);
        QuickSort(lista, indiceParticao + 1, proximo);
    }
}

// Ordenar por nome usando Insertion Sort
void insertionSort(Processo *processos[], int n) {
    int i, j;
    Processo *key;

    for (i = 1; i < n; i++) {
        key = processos[i];
        j = i - 1;

        while (j >= 0 && strcmp(processos[j]->nome, key->nome) > 0) {
            processos[j + 1] = processos[j];
            j = j - 1;
        }
        processos[j + 1] = key;
    }
}]
//complemento void
//funcao de trocar//
void trocar(Processo **a, Processo **b) {
    Processo *temp = *a;
    *a = *b;
    *b = temp;
}

// Função para imprimir os processos
void imprimir_processos(Processo *processos[], int n) {
    printf("\n--- Lista de Processos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Data: %s, Memória: %d\n", processos[i]->nome, processos[i]->data_inicio, processos[i]->qnt_memoria);
    }
    printf("-------------------------\n");
}

int main(void) {
    int opcao;
    Processo *processos = NULL;
    int num_processos = 0;

    printf("-- Menu de Tarefas --\n\n");
    printf("1) Inserir Tarefas\n2) Mostrar Ordem por Nome\n3) Mostrar Ordem por Data\n4) Mostrar Ordem por Memória\nSair\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            processos = lista();
            num_processos++;
            break;
        case 2:
            if (processos == NULL) {
                printf("Lista vazia\n");
            } else {
                insertionSort(&processos, num_processos);
                imprimir_processos(&processos, num_processos);
            }
            break;
        case 3:
            if (processos == NULL) {
                printf("Lista vazia\n");
            } else {
        
            }
            break;
        case 4:
            if (processos == NULL) {
                printf("Lista vazia\n");
            } else {
                // Ordenar por memória e imprimir
                QuickSort(&processos, 0, num_processos - 1);
                imprimir_processos(&processos, num_processos);
            }
            break;
        default:
            printf("Saindo...\n");
            break;
    }

    return 0;
}

