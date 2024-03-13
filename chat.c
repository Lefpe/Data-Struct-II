#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a data do evento
typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para um ingresso
typedef struct Ingresso {
    char cpf[12];
    char nomeComprador[50];
    Data dataEvento;
    struct Ingresso* proximoIngresso;
} Ingresso;

// Estrutura para a lista de ingressos
typedef struct {
    Ingresso* primeiroIngresso;
} ListaIngressos;

// Função para buscar ingressos por CPF e ordenar com Insertion Sort
void buscarIngressosPorCPF(ListaIngressos lista, const char cpf[]) {
    // Implementação do Insertion Sort para ordenar a lista por data
    // ...

    // Exemplo de como pode ser feita a busca
    Ingresso* atual = lista.primeiroIngresso;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            // Imprimir ou processar o ingresso encontrado
            printf("CPF: %s, Nome: %s, Data do Evento: %02d/%02d/%04d\n",
                   atual->cpf, atual->nomeComprador, atual->dataEvento.dia,
                   atual->dataEvento.mes, atual->dataEvento.ano);
        }
        atual = atual->proximoIngresso;
    }
}

// Função para inserir um novo ingresso ordenadamente na lista
void inserirOrdenado(ListaIngressos* lista, Ingresso* novoIngresso) {
    // Verificar se já existe um ingresso com o mesmo CPF e data
    Ingresso* atual = lista->primeiroIngresso;
    Ingresso* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->cpf, novoIngresso->cpf) == 0 &&
            memcmp(&atual->dataEvento, &novoIngresso->dataEvento, sizeof(Data)) == 0) {
            printf("Já existe um ingresso cadastrado para o CPF %s na data do evento.\n", novoIngresso->cpf);
            free(novoIngresso);  // Liberar memória alocada para o novo ingresso
            return;
        }
        anterior = atual;
        atual = atual->proximoIngresso;
    }

    // Inserir ordenadamente na lista
    if (anterior == NULL) {
        novoIngresso->proximoIngresso = lista->primeiroIngresso;
        lista->primeiroIngresso = novoIngresso;
    } else {
        novoIngresso->proximoIngresso = anterior->proximoIngresso;
        anterior->proximoIngresso = novoIngresso;
    }
}

// Função para ordenar a lista pela data do evento usando o método Quick Sort
void quickSort(ListaIngressos* lista) {
    // Implementação do Quick Sort para ordenar a lista por data
    // ...
}

// Função para exibir quantos ingressos foram cadastrados em cada data
void exibirQuantidadePorData(ListaIngressos lista) {
    // Implementação para contar e exibir a quantidade de ingressos por data
    // ...
}

// Função principal para teste
int main() {
    ListaIngressos lista;
    lista.primeiroIngresso = NULL;

    // Exemplo de cadastro de ingressos
    Ingresso* ingresso1 = malloc(sizeof(Ingresso));
    strcpy(ingresso1->cpf, "12345678901");
    strcpy(ingresso1->nomeComprador, "João Silva");
    ingresso1->dataEvento.dia = 13;
    ingresso1->dataEvento.mes = 3;
    ingresso1->dataEvento.ano = 2024;
    ingresso1->proximoIngresso = NULL;

    Ingresso* ingresso2 = malloc(sizeof(Ingresso));
    strcpy(ingresso2->cpf, "12345678901");
    strcpy(ingresso2->nomeComprador, "Maria Oliveira");
    ingresso2->dataEvento.dia = 14;
    ingresso2->dataEvento.mes = 3;
    ingresso2->dataEvento.ano = 2024;
    ingresso2->proximoIngresso = NULL;

    inserirOrdenado(&lista, ingresso1);
    inserirOrdenado(&lista, ingresso2);

    // Exemplo de busca por CPF
    buscarIngressosPorCPF(lista, "12345678901");

    // Exemplo de ordenação da lista por data usando Quick Sort
    quickSort(&lista);

    // Exemplo de exibição da quantidade de ingressos por data
    exibirQuantidadePorData(lista);

    // Liberar memória (certifique-se de liberar toda a memória alocada)
    // ...

    return 0;
}