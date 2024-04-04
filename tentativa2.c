#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Ingresso {
    char nome[50];
    int cpf;
    Data dataevento;
    struct Ingresso *next;
} Ingresso;

struct ListaIngressos {
    Ingresso *first;
};

void cadastrarIngresso(struct ListaIngressos *lista) {
    Ingresso *novoIngresso = malloc(sizeof(Ingresso));

    printf("Digite seu nome: ");
    scanf("%s", novoIngresso->nome);

    printf("CPF: ");
    scanf("%d", &novoIngresso->cpf);

    printf("Data do evento (Dia Mes Ano): ");
    scanf("%d %d %d", &novoIngresso->dataevento.dia, &novoIngresso->dataevento.mes, &novoIngresso->dataevento.ano);

    novoIngresso->next = NULL;

    // Verificar duplicidade antes de cadastrar
    Ingresso *atual = lista->first;
    int duplicado = 0;

    while (atual != NULL) {
        if (atual->cpf == novoIngresso->cpf && memcmp(&atual->dataevento, &novoIngresso->dataevento, sizeof(Data)) == 0) {
            printf("Duplicidade detectada. Não cadastrado.\n");
            duplicado = 1;
            free(novoIngresso);
            break;
        }
        atual = atual->next;
    }

    // Cadastrar se não for duplicado
    if (!duplicado) {
        // Inserir ordenadamente utilizando Insertion Sort
        Ingresso *atual = lista->first;
        Ingresso *anterior = NULL;

        while (atual != NULL && atual->dataevento.ano < novoIngresso->dataevento.ano) {
            anterior = atual;
            atual = atual->next;
        }

        while (atual != NULL && atual->dataevento.ano == novoIngresso->dataevento.ano &&
               atual->dataevento.mes < novoIngresso->dataevento.mes) {
            anterior = atual;
            atual = atual->next;
        }

        while (atual != NULL && atual->dataevento.ano == novoIngresso->dataevento.ano &&
               atual->dataevento.mes == novoIngresso->dataevento.mes &&
               atual->dataevento.dia < novoIngresso->dataevento.dia) {
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

        printf("Ingresso cadastrado com sucesso!\n");
    }
}

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

void insertionSort(struct ListaIngressos *lista) {
    if (lista->first == NULL || lista->first->next == NULL) {
        return;
    }

    Ingresso *sorted = NULL;
    Ingresso *current = lista->first;

    while (current != NULL) {
        Ingresso *next = current->next;

        if (sorted == NULL || memcmp(&sorted->dataevento, &current->dataevento, sizeof(Data)) > 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Ingresso *temp = sorted;
            while (temp->next != NULL && memcmp(&temp->next->dataevento, &current->dataevento, sizeof(Data)) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    lista->first = sorted;
}

void quickSort(struct ListaIngressos *lista) {
    // Implementação do Quick Sort para ordenar a lista por data
    // ...
}

void exibirQuantidadePorData(struct ListaIngressos lista) {
    // Implementação para contar e exibir a quantidade de ingressos por data
    // ...
}

void liberarMemoria(struct ListaIngressos *lista) {
    Ingresso *atual = lista->first;
    while (atual != NULL) {
        Ingresso *temp = atual;
        atual = atual->next;
        free(temp);
    }
    lista->first = NULL; // Certificar-se de que a lista está vazia após a liberação de memória
}

int main() {
    struct ListaIngressos lista;
    lista.first = NULL;

    // Exemplo de cadastro de ingressos
    for (int i = 0; i < 3; i++) {
        cadastrarIngresso(&lista);
    }

    // Exemplo de busca por CPF
    int cpfBusca;
    printf("Digite o CPF para busca: ");
    scanf("%d", &cpfBusca);
    buscarPorCPF(lista, cpfBusca);

    // Exemplo de ordenação da lista por data usando Insertion Sort
    insertionSort(&lista);

    // Exemplo de  Exemplo de exibição da quantidade de ingressos por data
    exibirQuantidadePorData(lista);

    // Liberar memória
    liberarMemoria(&lista);

    return 0;
}
