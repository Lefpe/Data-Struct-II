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
    scanf ("%d %d %d", &novo-> datavento.dia, &novo-> dataevento.mes, &novo-> dataevento.ano);

    novo -> next = NULL;

    return novo; 


}
//comparação de dedados//
int comparardados(ingresso *ingresso1, ingresso *ingresso2){


}
//inicializar busca por cpf//
void buscaporcpf(){

}
//inserir ordendada//
void inserirordem(listaringressos *lista, ingresso *novoigresso){
    ingresso *atual = lista -> first;;
    ingresso *anterior = NULL;
    //finalizar função anterior//
    while (atual != NULL &&)
    {
        
    }
    


}
