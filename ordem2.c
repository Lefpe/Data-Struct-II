#include <stdio.h>
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
                inserirOrdenado(&lista, novoIngresso);
                break;
            }

            case 2: {
                // Exibir lista
                Ingresso *atual = lista.first;
                printf("\nLista de Ingressos:\n");

                while (atual != NULL) {
                    printf("Nome: %s, CPF: %d, Data do Evento: %02d/%02d/%04d\n",
                           atual->nome, atual->cpf,
                           atual->dataevento.dia, atual->dataevento.mes, atual->dataevento.ano);
                    atual = atual->next;
                }
                break;
            }

            case 3: {
                // Buscar por CPF
                int cpfBusca;
                printf("Digite o CPF para busca: ");
                scanf("%d", &cpfBusca);
                buscarPorCPF(lista, cpfBusca);
                break;
            }

            case 4: {
                // Exibir lista ordenada (quicksort)
                // Implemente o método quickSort e a função para exibir a lista ordenada
                break;
            }

            case 0: {
                printf("Saindo do programa.\n");
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