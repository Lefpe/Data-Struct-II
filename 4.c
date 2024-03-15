um#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct proc{
    char data_inicio[11]; // Formato: yyyy-mm-dd. Exemplo: 2024-03-15
    char nome[20];
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

    printf("-- Menu de Tarefas --\n\n");
    printf("1) Inserir Tarefas\n2) Mostrar Ordem por Nome\n3) Mostrar Ordem por Data\n4) Mostrar Ordem por Memória\n5) Sair\n");
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
                insertionSort(processos, num_processos);
                imprimir_processos(processos, num_processos);
            }
            break;
        case 3:
            // Mostrar ordem por data
            if (num_processos == 0) {
                printf("Lista vazia.\n");
            } else {
                quickSort(processos, 0, num_processos - 1);
                imprimir_processos(processos, num_processos);
            }
            break;
        case 4:
            // Mostrar ordem por memória
            if (num_processos == 0) {
                printf("Lista vazia.\n");
            } else {
                // Aqui você precisa implementar a função de ordenação por memória
                // BubbleSort(processos, num_processos);
                printf("Ordenando por memória...\n");
                // imprimir_processos(processos, num_processos);
            }
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    // Liberar memória alocada
    for (int i = 0; i < num_processos; i++) {
        free(processos[i]);
    }

    return 0;
}