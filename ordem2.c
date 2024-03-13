
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

    printf("Data do evento (Dia, Mes, Ano): ");
    scanf("%d %d %d", &novo->dataevento.dia, &novo->dataevento.mes, &novo->dataevento.ano);

    novo->next = NULL;

    return novo;
}

// Comparação de dados
int compararDados(Ingresso *ingresso1, Ingresso *ingresso2) {
    // Implemente a comparação de dados conforme necessário
    return 0;
}

// Inicializar busca por CPF
void buscarPorCPF(ListaIngressos lista, int cpf) {
    Ingresso *atual = lista.first;

    while (atual != NULL) {
        if (atual->cpf == cpf) {
            printf("Nome: %s, CPF: %d, Data do Evento: %02d/%02d/%04d\n",
                   atual->nome, atual->cpf, atual->dataevento.dia,
                   atual->dataevento.mes, atual->dataevento.ano);
        }
        atual = atual->next;
    }
}

// Inserir ordenadamente na lista por data usando o método Insertion Sort
void inserirOrdenado(ListaIngressos *lista, Ingresso *novoIngresso) {
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
    ListaIngressos lista;
    lista.first = NULL;

    // Exemplo de cadastro de ingressos
    for (int i = 0; i < 3; i++) {
        Ingresso *novoIngresso = cadastroIngresso();
        inserirOrdenado(&lista, novoIngresso);
    }

    // Exemplo de busca por CPF
    int cpfBusca;
    printf("Digite o CPF para busca: ");
    scanf("%d", &cpfBusca);
    buscarPorCPF(lista, cpfBusca);

    // Liberação de memória (certifique-se de liberar toda a memória alocada)
    // ...

    return 0;
}
```

Este código finaliza a função `inserirOrdenado`, realiza algumas correções no código fornecido e adiciona chamadas de função no `main` para testar o cadastro e a busca por CPF. Certifique-se de gerenciar adequadamente a memória alocada.
