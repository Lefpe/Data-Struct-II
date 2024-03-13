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
    struct ingresso *prox;
    
};
//listar ordernação a partir do primeiro ingresso//
struct listaringressos
{
    ingresso *first;
};


//cadastrar ingressos//
void cadastro (){
    printf ("digite seu nome: \n");
    scanf("%c",novo-> nome);
    printf ("CPF: \n");
    scanf ("%d", novo ->&cpf);




}
//comparação de dedados//
void comparardados(){

}
//inicializar busca por cpf//
void buscaporcpf(){

}
