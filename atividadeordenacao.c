// Solicite um número contendo o tamanho para um vetor de inteiros//
//Gere números aleatórios entre 1 e 10 para preencher este vetor///
//Imprima o vetor com os números gerados//
//Utilize o Bubble Sort, Selection Sorte e Insertion Sort para ordenar o vetor //
//Imprima o vetor após a ordenação//

#include <stdio.h>
#include <stlib.h>
#include <math.h>
#include <time.h>

//função imprimir vetor //
 void imprimirvetor (int vec [], int length){
    printf ("digite um número contendo o tamanho para um vetor de inteiros");
    //loop principal   //
    for (i = 0, i < length; i++){
        printf ("%d", vec[i]);
    }
    printf ("\n");
 }
 //utilizando bubblesort//
 //gerando numeros aleatorios para completar o vetor//
