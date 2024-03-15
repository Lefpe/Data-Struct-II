#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct proc {
    char data_inicio[11]; //formato yyyy-mm-dd. ex: 2024-03-15
    char nome[20];
    int qnt_memoria;
    struct proc *prox;
    struct proc *ant;
} Processo;

// Inserir dados
Processo *lista() {
    Processo *novo = malloc(sizeof(Processo));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Digite seu nome: ");
    scanf("%s", novo->nome);
    printf("Digite a sua data (FORMATO: AAAA-MM-DD): ");
    scanf("%s", novo->data_inicio);
    printf("Digite a quantidade de memória: ");
    scanf("%d", &(novo->qnt_memoria));
    novo->prox = NULL;
    return novo;
}

// Comparar tamanho da memória entre dois processos
int comparar_memoria(Processo *tm1, Processo *tm2) {
    return tm1->qnt_memoria - tm2->qnt_memoria;
}

// Ordenar por data usando Bubble Sort (não implementado)
void BubbleSort() {
    // Implementação do Bubble Sort
    printf("Ordenando por data usando Bubble Sort...\n");
}

// Particionar para o Quick Sort
int particionar(Processo *lista[], int atual, int proximo) {
    Processo *pivot = lista[proximo];
    int i = atual - 1;

    for (int j = atual; j < proximo; j++) {
        if (strcmp(lista[j]->data_inicio, pivot->data_inicio) < 0) {
            i++;
            // Troca lista[i] com lista[j]
            Processo *temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
        }
    }
    // Troca lista[i+1] com lista[proximo] (o pivô)
    Processo *temp = lista[i + 1];
    lista[i + 1] = lista[proximo];
    lista[proximo] = temp;
    return i + 1;
}

// Ordenar por data usando Quick Sort
void quickSort(Processo *lista[], int atual, int proximo) {
    if (atual < proximo) {
        int indiceParticao = particionar(lista, atual, proximo);
        quickSort(lista, atual, indiceParticao - 1);
        quickSort(lista, indiceParticao + 1, proximo);
    }
}

// Ordenar por nome usando Insertion Sort (não implementado)
void insertionSort(Processo *processos[], int n) {
    // Implementação do Insertion Sort
    printf("Ordenando por nome usando Insertion Sort...\n");
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
    Processo *processos[100]; // Array para armazenar os processos
    int num_processos = 0; // Número de processos inseridos

    do {
        printf("\n-- Menu de Tarefas --\n");
        printf("1) Inserir Tarefa\n");
        printf("2) Mostrar Ordem por Nome\n");
        printf("3) Mostrar Ordem por Data\n");
        printf("4) Mostrar Ordem por Memória\n");
        printf("5) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserir tarefa
                if (num_processos < 100) {
                    processos[num_processos] = lista();
                    num_processos++;
                } else {
                    printf("Limite de processos atingido.\n");
                }
                break;
            case 2:
                // Ordenar por nome e imprimir
                insertionSort(processos, num_processos);
                imprimir_processos(processos, num_processos);
                break;
            case 3:
                // Ordenar por data e imprimir
                quickSort(processos, 0, num_processos - 1);
                imprimir_processos(processos, num_processos);
                break;
            case 4:
                // Ordenar por memória e imprimir
                BubbleSort();
                imprimir_processos(processos, num_processos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    // Liberar memória alocada
    for (int i = 0; i < num_processos; i++) {
        free(processos[i]);
    }

    return 0;
}