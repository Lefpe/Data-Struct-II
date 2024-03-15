#include <stdio.h>
#include <stdlib.h>

void printArray(int vetor[], int tamanho){
    for (int i=0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n"); 
}

// Implementação do algoritmo Shell Sort
void shellSort(int vetor[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap){
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }
    }
}

int main (){
    int n;
    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &n);

    int *vetor = (int*)malloc(n * sizeof(int));

    printf ("Digite os elementos do vetor:\n ");
    for (int i = 0; i < n; i++){
        printf ("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf ("Vetor inserido:\n");
    printArray(vetor, n);

    // Ordena o vetor usando o algoritmo Shell Sort
    shellSort(vetor, n);

    printf ("Vetor ordenado:\n");
    printArray(vetor, n);

    free(vetor);
    return 0;
}
