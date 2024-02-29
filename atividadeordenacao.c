// Solicite um número contendo o tamanho para um vetor de inteiros//
//Gere números aleatórios entre 1 e 10 para preencher este vetor///
//Imprima o vetor com os números gerados//
//Utilize o Bubble Sort, Selection Sorte e Insertion Sort para ordenar o vetor //
//Imprima o vetor após a ordenação//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// imprimir vetores//
void imprimirvetor(int vec[], int length) {
    printf("Vetor: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int vec[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                // ordenar elementos
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int vec[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        //ordenar
        int temp = vec[i];
        vec[i] = vec[min_index];
        vec[min_index] = temp;
    }
}

// Insertion Sort
void insertionSort(int vec[], int length) {
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = vec[i];
        j = i - 1;

        
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));

    int length;
    printf("Digite o tamanho para um vetor de inteiros: ");
    scanf("%d", &length);

    int vec[length];

    //iniciando com valores aleatórios
    for (int i = 0; i < length; i++) {
        vec[i] = rand() % 100;  // Assuming integers between 0 and 99
    }

    imprimirvetor(vec, length);

    // Bubble Sort
    bubbleSort(vec, length);
    printf("Após Bubble Sort: ");
    imprimirvetor(vec, length);

    // Selection Sort
    selectionSort(vec, length);
    printf("Após Selection Sort: ");
    imprimirvetor(vec, length);

    // Insertion Sort
    insertionSort(vec, length);
    printf("Após Insertion Sort: ");
    imprimirvetor(vec, length);

    return 0;
}
