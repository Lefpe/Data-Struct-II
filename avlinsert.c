#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  int num;
  struct node *esq;
  struct node *dir;
} No;

// Declaração das funções
No *criar_no(int num);
void inserir_no(No *node, No *novo);
No *buscar_no(No *node, int num);
void imprimir(No *node, int tab);
int altura(No *node);
int fator_balanceamento(No *node);
No *rotacao_simples_esquerda(No *rot);
No *rotacao_simples_direita(No *rot);
No *balancear(No *node);
No *remover(No *root, int num);
No *minValueNode(No *node);
void inserir_raiz(No **raiz, int num);
void buscar_raiz(No *raiz);

// Função para criar um novo nó
No *criar_no(int num) {
  No *node = (No *)malloc(sizeof(No));
  node->num = num;
  node->esq = NULL;
  node->dir = NULL;
  return node;
}

// Função para inserir um nó na árvore
void inserir_no(No *node, No *novo) {
  if (node == NULL) {
    printf("Erro\n");
    return;
  }

  if (node->num == novo->num) {
    printf("Número já existe\n");
    return;
  }

  if (node->num < novo->num) {
    if (node->dir == NULL) {
      node->dir = novo;
      return;
    }
    inserir_no(node->dir, novo);
  } else {
    if (node->esq == NULL) {
      node->esq = novo;
      return;
    }
    inserir_no(node->esq, novo);
  }
}

// Função para buscar um nó na árvore
No *buscar_no(No *node, int num) {
  if (node == NULL) {
    return NULL;
  }

  if (node->num == num) {
    return node;
  }

  if (node->num < num) {
    return buscar_no(node->dir, num);
  } else {
    return buscar_no(node->esq, num);
  }
}

// Função para imprimir a árvore
void imprimir(No *node, int tab) {
  if (node == NULL) return;

  imprimir(node->dir, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", node->num);
  imprimir(node->esq, tab + 1);
}

// Função para obter a altura de um nó
int altura(No *node) {
  if (node == NULL) {
    return 0;
  }
  return 1 + fmax(altura(node->esq), altura(node->dir));
}

// Função para obter o fator de balanceamento de um nó
int fator_balanceamento(No *node) {
  if (node == NULL) return 0;
  return altura(node->esq) - altura(node->dir);
}

// Função para realizar rotação simples à esquerda
No *rotacao_simples_esquerda(No *rot) {
  No *novo = rot->dir;
  No *esq_novo = novo->esq;
  novo->esq = rot;
  rot->dir = esq_novo;
  return novo;
}

// Função para realizar rotação simples à direita
No *rotacao_simples_direita(No *rot) {
  No *novo = rot->esq;
  No *dir_novo = novo->dir;
  novo->dir = rot;
  rot->esq = dir_novo;
  return novo;
}

// Função para balancear a árvore
No *balancear(No *node) {
  if (node == NULL) {
    return NULL;
  }

  node->esq = balancear(node->esq);
  node->dir = balancear(node->dir);

  int fb = fator_balanceamento(node);
  if (fb > 1) {
    if (fator_balanceamento(node->esq) < 0) {
      node->esq = rotacao_simples_esquerda(node->esq);
    }
    return rotacao_simples_direita(node);
  } else if (fb < -1) {
    if (fator_balanceamento(node->dir) > 0) {
      node->dir = rotacao_simples_direita(node->dir);
    }
    return rotacao_simples_esquerda(node);
  }

  return node;
}

// Função para buscar o nó com o menor valor
No *minValueNode(No *node) {
  No *current = node;
  while (current && current->esq != NULL)
    current = current->esq;
  return current;
}

// Função para remover um nó da árvore
No *remover(No *root, int num) {
  if (root == NULL)
    return root;

  if (num < root->num)
    root->esq = remover(root->esq, num);
  else if (num > root->num)
    root->dir = remover(root->dir, num);
  else {
    if ((root->esq == NULL) || (root->dir == NULL)) {
      No *temp = root->esq ? root->esq : root->dir;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;

      free(temp);
    } else {
      No *temp = minValueNode(root->dir);
      root->num = temp->num;
      root->dir = remover(root->dir, temp->num);
    }
  }

  if (root == NULL)
    return root;

  return balancear(root);
}

// Função para inserir uma raiz na árvore
void inserir_raiz(No **raiz, int num) {
  if (*raiz == NULL) {
    *raiz = criar_no(num);
    return;
  }

  No *novo = criar_no(num);
  inserir_no(*raiz, novo);
  *raiz = balancear(*raiz);
}

// Função para buscar um nó a partir da raiz
void buscar_raiz(No *raiz) {
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);
  No *res = buscar_no(raiz, num);
  if (res == NULL) {
    printf("Numero não encontrado\n");
  } else {
    imprimir(res, 0);
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  No *root = NULL;
  int choice, num;

  do {
    printf("\nMenu:\n");
    printf("1. Inserir nó\n");
    printf("2. Remover nó\n");
    printf("3. Buscar nó\n");
    printf("4. Imprimir árvore\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Digite o número a ser inserido: ");
        scanf("%d", &num);
        inserir_raiz(&root, num);
        break;
      case 2:
        printf("Digite o número a ser removido: ");
        scanf("%d", &num);
        root = remover(root, num);
        break;
      case 3:
        buscar_raiz(root);
        break;
      case 4:
        imprimir(root, 0);
        break;
      case 5:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida!\n");
        break;
    }
  } while (choice != 5);

  return 0;
}
