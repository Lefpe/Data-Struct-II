#include <stdio.h>
#include <stdlib.h>

enum cor { VERMELHO, PRETO };

struct node {
    int valor;
    struct node *esquerda, *direita, *pai;
    enum cor cor;
};

// Função para criar um novo nó Red-Black
struct node* criar_no(int valor) {
    struct node* no = (struct node*)malloc(sizeof(struct node));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->pai = NULL;
    no->cor = VERMELHO; // Novos nós são sempre vermelhos
    return no;
}

// Função para fazer uma rotação à esquerda
void rotacao_esquerda(struct node **raiz, struct node *x) {
    struct node *y = x->direita;
    x->direita = y->esquerda;

    if (y->esquerda != NULL)
        y->esquerda->pai = x;

    y->pai = x->pai;

    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esquerda)
        x->pai->esquerda = y;
    else
        x->pai->direita = y;

    y->esquerda = x;
    x->pai = y;
}

// Função para fazer uma rotação à direita
void rotacao_direita(struct node **raiz, struct node *y) {
    struct node *x = y->esquerda;
    y->esquerda = x->direita;

    if (x->direita != NULL)
        x->direita->pai = y;

    x->pai = y->pai;

    if (y->pai == NULL)
        *raiz = x;
    else if (y == y->pai->esquerda)
        y->pai->esquerda = x;
    else
        y->pai->direita = x;

    x->direita = y;
    y->pai = x;
}

// Função para corrigir as propriedades da árvore Red-Black após a inserção
void corrigir_insercao(struct node **raiz, struct node *k) {
    struct node *pai_k = NULL;
    struct node *avo_k = NULL;

    while ((k != *raiz) && (k->cor != PRETO) && (k->pai->cor == VERMELHO)) {
        pai_k = k->pai;
        avo_k = k->pai->pai;

        // Caso A: Pai de k é o filho à esquerda do avô de k
        if (pai_k == avo_k->esquerda) {
            struct node *tio_k = avo_k->direita;

            // Caso 1: O tio de k é vermelho
            if (tio_k != NULL && tio_k->cor == VERMELHO) {
                avo_k->cor = VERMELHO;
                pai_k->cor = PRETO;
                tio_k->cor = PRETO;
                k = avo_k;
            } else {
                // Caso 2: k é o filho à direita
                if (k == pai_k->direita) {
                    rotacao_esquerda(raiz, pai_k);
                    k = pai_k;
                    pai_k = k->pai;
                }

                // Caso 3: k é o filho à esquerda
                rotacao_direita(raiz, avo_k);
                enum cor temp_cor = pai_k->cor;
                pai_k->cor = avo_k->cor;
                avo_k->cor = temp_cor;
                k = pai_k;
            }
        }
        // Caso B: Pai de k é o filho à direita do avô de k
        else {
            struct node *tio_k = avo_k->esquerda;

            // Caso 1: O tio de k é vermelho
            if (tio_k != NULL && tio_k->cor == VERMELHO) {
                avo_k->cor = VERMELHO;
                pai_k->cor = PRETO;
                tio_k->cor = PRETO;
                k = avo_k;
            } else {
                // Caso 2: k é o filho à esquerda
                if (k == pai_k->esquerda) {
                    rotacao_direita(raiz, pai_k);
                    k = pai_k;
                    pai_k = k->pai;
                }

                // Caso 3: k é o filho à direita
                rotacao_esquerda(raiz, avo_k);
                enum cor temp_cor = pai_k->cor;
                pai_k->cor = avo_k->cor;
                avo_k->cor = temp_cor;
                k = pai_k;
            }
        }
    }
    (*raiz)->cor = PRETO;
}

// Função para inserir um nó na árvore Red-Black
void inserir(struct node **raiz, struct node *novo) {
    struct node *y = NULL;
    struct node *x = *raiz;

    while (x != NULL) {
        y = x;
        if (novo->valor < x->valor)
            x = x->esquerda;
        else
            x = x->direita;
    }

    novo->pai = y;
    if (y == NULL)
        *raiz = novo;
    else if (novo->valor < y->valor)
        y->esquerda = novo;
    else
        y->direita = novo;

    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->cor = VERMELHO;

    corrigir_insercao(raiz, novo);
}

// Função para imprimir a árvore Red-Black em pré-ordem
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d(%s) ", root->valor, root->cor == VERMELHO ? "Vermelho" : "Preto");
        preOrder(root->esquerda);
        preOrder(root->direita);
    }
}

// Função principal para testar
int main() {
    struct node *root = NULL;
    int valor;
    char continuar;

    do {
        printf("Digite um valor para inserir na árvore Red-Black: ");
        scanf("%d", &valor);
        struct node *novo = criar_no(valor);
        inserir(&root, novo);

        printf("Deseja inserir outro valor? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Impressão da travessia pré-ordem da árvore
    printf("Travessia pré-ordem da árvore Red-Black construída é: \n");
    preOrder(root);

    return 0;
}
