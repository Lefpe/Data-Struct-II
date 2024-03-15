#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define DATE_LENGTH 11
#define MAX_PROCESSOS 100

typedef struct proc {
    char data_inicio[DATE_LENGTH]; // Formato: yyyy-mm-dd. Exemplo: 2024-03-15
    char nome[MAX_NAME_LENGTH];
    int qnt_memoria;
    struct proc *prox;
    struct proc *ant;
} Processo;

// Função para inserir dados
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

// Função de troca
void trocar(Processo **a, Processo **b) {
    Processo *temp = *a;
    *a = *b;
    *b = temp;
}

// Ordenar por memória usando Bubble Sort
void bubbleSort(Processo *processos[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processos[j]->qnt_memoria > processos[j+1]->qnt_memoria) {
                trocar(&processos[j], &processos[j+1]);
            }
        }
    }
}

// Função para imprimir os processos
void imprimir_processos(Processo *processos[], int n) {
    printf("\n--- Lista de Processos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Data: %s, Memória: %d\n", processos[i]->nome, processos[i]->data_inicio, processos[i]->qnt_memoria);
    }
    printf("-------------------------\n");
}

// Função principal
int main(void) {
    int opcao;
    Processo *processos[MAX_PROCESSOS]; // Array para armazenar os processos
    int num_processos = 0;

    do {
        printf("-- Menu de Tarefas --\n\n");
        printf("1) Inserir Tarefas\n");
        printf("2) Mostrar Ordem por Nome\n");
        printf("3) Mostrar Ordem por Data\n");
        printf("4) Mostrar Ordem por Memória\n");
        printf("5) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserir tarefas
                if (num_processos < MAX_PROCESSOS) {
                    processos[num_processos] = lista();
                    num_processos++;
                } else {
                    printf("Limite de processos atingido.\n");
                }
                break;
            case 2:
                // Mostrar ordem por nome
                if (num_processos == 0) {
                    printf("Lista vazia.\n");
                } else {
                    // Ordenar por nome usando Bubble Sort
                    // insertionSort(processos, num_processos);
                    printf("Ordenando por nome...\n");
                    // imprimir_processos(processos, num_processos);
                }
                break;
            case 3:
                // Mostrar ordem por data
                if (num_processos == 0) {
                    printf("Lista vazia.\n");
                } else {
                    // Ordenar por data e imprimir
                    // quickSort(processos, 0, num_processos - 1);
                    printf("Ordenando por data...\n");
                    // imprimir_processos(processos, num_processos);
                }
                break;
            case 4:
                // Mostrar ordem por memória
                if (num_processos == 0) {
                    printf("Lista vazia.\n");
                } else {
                    // Ordenar por memória usando Bubble Sort
                    bubbleSort(processos, num_processos);
                    imprimir_processos(processos, num_processos);
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 5);

    // Liberar memória alocada
    for (int i = 0; i < num_processos; i++) {
        free(processos[i]);
    }

    return 0;
}