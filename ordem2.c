//a) armazenar dados//
//b) utilizar lista encadeada simples//
//c) uma opção emissão de ingressos pelo mesmo cpf, usando insertsort//
//d) inserir novo ingresso e verificar usuário//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct dedidaca a organizar a data;
typedef struct data
{
    int dia;
    int mes;
    int ano;
};
//struct de ordenar dados//
typedef struct dados
{
    char nome [50];
    int cpf [11];
    data *dataevento;
    struct ingresso *next;
    
};
//listar ordernação a partir do primeiro ingresso//
struct listaringressos
{
    ingresso *first;
};


//cadastrar ingressos//
cadastro *cadastroingresso (){
ingresso  *novo = malloc(sizeof(ingresso));
//estrutura//
    printf ("digite seu nome: \n");
    scanf("%c",novo-> nome);
    printf ("CPF: \n");
    scanf ("%d", &novo-> cpf);

    printf ("data do evento  Dia, Mes, ano: (use apenas 2 digitos para cada, para ano, os 2 digitos finais) \n");
    scanf ("%d %d %d", &novo-> datavento.dia, &novo-> dataevento.mes, %novo-> dataevento.ano);

    novo -> next = NULL;
    

    //verificar se há conflitos antes de cadastrar// 
     Ingresso *atual = listaringressos -> first;
   

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
        // Inserir ordenadamente utilizando InsertionSort//
        Ingresso *atual = lista->first;
        Ingresso *anterior = NULL;
        //verifica data do evento//
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

        printf("Ingresso cadastrado!\n");
    }
 
}
//comparação de de dados//
int comparardados(ingresso *ingresso1, ingresso *ingresso2){


}
//inicializar busca por cpf//
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

// Inserir ordenadamente na lista por data usando o método Insertion Sort//
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
 int main (){
    int options;

    printf ("selecione as opções: 1) cadastrar ingresso \n 2) exibir lista \n 3) buscar ingressos por cpf \n 4) exibir lista ordenada (quicksort) \n sair ");
    scanf ("%d", &options);

    

    do while (options) {
        case 1:

        break;

        case 2:
         
         break;

         case 3:
          
          break;

          case 4:

          break;

          

           default:
           break;
    }
    return 0;

 }
