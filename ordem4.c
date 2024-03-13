eu#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct dedicada a organizar a data
typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

// Struct de ordenar dados
typedef struct Ingresso {
    char nome[50];
    int cpf;
    Data dataevento;
    struct Ingresso *next;
} Ingresso;

// Lista de ordenação a partir do primeiro ingresso
struct ListaIngressos {
    Ingresso *first;
};

// Cadastrar ingressos
Ingresso *cadastroIngresso() {
    Ingresso *novo = malloc(sizeof(Ingresso));

    printf("Digite seu nome: ");
    scanf("%s", novo->nome);

    printf("CPF: ");
    scanf("%d", &novo->cpf);

    printf("Data do evento (Dia Mes Ano): ");
    scanf("%d %d %d", &novo->dataevento.dia, &novo->dataevento.mes, &novo->dataevento.ano);

    novo->next = NULL;

    return novo;
}

// Comparação de dados
int compararDados(Ingresso *ingresso1, Ingresso *ingresso2) {
    // Implemente a comparação de dados conforme necessário
    if (ingresso1->dataevento.ano > ingresso2->dataevento.ano)
        return 1;
    else if (ingresso1->dataevento.ano < ingresso2->dataevento.ano)
        return -1;
    else {
        if (ingresso1->dataevento.mes > ingresso2->dataevento.mes)
            return 1;
        else if (ingresso1->dataevento.mes < ingresso2->dataevento.mes)
            return -1;
        else {
            if (ingresso1->dataevento.dia > ingresso2->dataevento.dia)
                return 1;
            else if (ingresso1->dataevento.dia < ingresso2->dataevento.dia)
                return -1;
            else
                return 0;
        }
    }
}

// Função para trocar dois ingressos
void trocarIngressos(Ingresso *a, Ingresso *b) {
    Ingresso temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o ponto de partição para o QuickSort
int particionar(Ingresso *ingressos[], int inicio, int fim) {
    Ingresso *pivot = ingressos[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (compararDados(ingressos[j], pivot) < 0) {
            i++;
            trocarIngressos(ingressos[i], ingressos[j]);
        }
    }

    trocarIngressos(ingressos[i + 1], ingressos[fim]);
    return i + 1;
}

// Função QuickSort para ordenar ingressos por data
void quickSort(Ingresso *ingressos[], int inicio, int fim) {
    if (inicio < fim) {
        int indiceParticao = particionar(ingressos, inicio, fim);

        quickSort(ingressos, inicio, indiceParticao - 1);
        quickSort(ingressos, indiceParticao + 1, fim);
    }
}

// Inicializar busca por CPF
void buscarPorCPF(struct ListaIngressos lista, int cpf) {
    Ingresso *atual = lista.first;
    printf("Ingressos encontrados para CPF %d:\n", cpf);

    while (atual != NULL) {
        if (atual->cpf == cpf) {
            printf("Nome: %s, Data do Evento: %02d/%02d/%04d\n",
                   atual->nome, atual->dataevento.dia,
                   atual->dataevento.mes, atual->dataevento.ano);
        }
        atual = atual->next;
    }
}

// Inserir ordenadamente na lista por data usando o método Insertion Sort
void inserirOrdenado(struct ListaIngressos *lista, Ingresso *novoIngresso) {
    Ingresso *atual = lista->first;
    Ingresso *anterior = NULL;

    while (atual != NULL && compararDados(novoIngresso, atual) > 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (anterior == NULL) {
        novoIngresso->next = lista->first;
        lista->first = novoIngresso;
    } else {
        anterior->next = novoIngresso;
        novoIngresso->next = atual;
    }
}

int main() {
    struct ListaIngressos lista;
    lista.first = NULL;

    int opcao;

    do {
        printf("\nSelecione as opções:\n");
        printf("1) Cadastrar ingresso\n");
        printf("2) Exibir lista\n");
        printf("3) Buscar ingressos por CPF\n");
        printf("4) Exibir lista ordenada (quicksort)\n");
        printf("0) Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Ingresso *novoIngresso = cadastroIngresso();

                // Verificar duplicidade antes de cadastrar
                Ingresso *atual = lista.first;
                int duplicado = 0;

                while (atual != NULL) {
                    if (atual->cpf == novoIngresso->cpf && compararDados(&atual->dataevento, &novoIngresso->dataevento) == 0) {
                        printf("Duplicidade detectada. Não cadastrado.\n");
                        duplicado = 1;
                        free(novoIngresso);
                        break;
                    }
                    atual = atual->next;
                }

                // Cadastrar se não for duplicado
                if (!duplicado)// ... (continuação do código)

                // Cadastrar se não for duplicado
                if (!duplicado) {
                    // Inserir ordenadamente utilizando InsertionSort
                    atual = lista.first;
                    Ingresso *anterior = NULL;

                    while (atual != NULL && compararDados(novoIngresso, atual) > 0) {
                        anterior = atual;
                        atual = atual->next;
                    }

                    if (anterior == NULL) {
                        novoIngresso->next = lista.first;
                        lista.first = novoIngresso;
                    } else {
                        anterior->next = novoIngresso;
                        novoIngresso->next = atual;
                    }

                    printf("Ingresso cadastrado!\n");
                }
                break;
            }
            case 2: {
                // Exibir lista
                Ingresso *atual = lista.first;
                while (atual != NULL) {
                    printf("Nome: %s, CPF: %d, Data do Evento: %02d/%02d/%04d\n",
                           atual->nome, atual->cpf, atual->dataevento.dia,
                           atual->dataevento.mes, atual->dataevento.ano);
                    atual = atual->next;
                }
                break;
            }
            case 3: {
                // Buscar ingressos por CPF
                int cpfBusca;
                printf("Digite o CPF para busca: ");
                scanf("%d", &cpfBusca);
                buscarPorCPF(lista, cpfBusca);
                break;
            }
            case 4: {
                // Exibir lista ordenada (quicksort)
                Ingresso *ingressosOrdenados[100];  // Assumindo um máximo de 100 ingressos
                int count = 0;

                // Preencher array de ingressos
                Ingresso *atual = lista.first;
                while (atual != NULL) {
                    ingressosOrdenados[count++] = atual;
                    atual = atual->next;
                }

                // Ordenar array de ingressos usando QuickSort
                quickSort(ingressosOrdenados, 0, count - 1);

                // Exibir lista ordenada
                for (int i = 0; i < count; i++) {
                    printf("Nome: %s, CPF: %d, Data do Evento: %02d/%02d/%04d\n",
                           ingressosOrdenados[i]->nome, ingressosOrdenados[i]->cpf,
                           ingressosOrdenados[i]->dataevento.dia, ingressosOrdenados[i]->dataevento.mes,
                           ingressosOrdenados[i]->dataevento.ano);
                }
                break;
            }
            case 0: {
                // Sair
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}