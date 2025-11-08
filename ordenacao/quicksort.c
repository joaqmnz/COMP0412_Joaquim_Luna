#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int vector[], int inicio, int fim) {
    int i, j, pivot, aux;

    i = inicio;
    j = fim;
    pivot = vector[(inicio + fim) / 2];

    while( i <= j) {
        while(vector[i] < pivot) i++;
        while(vector[j] > pivot) j--;

        if(i <= j) {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;    
        }
    }

    if(inicio < j) quicksort(vector, inicio, j);
    if(i < fim) quicksort(vector, i, fim);
}

void vetorOrdenadoCrescente(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = i;

    quicksort(vector, 0, tamanho - 1);

    // for(int i = 0; i < tamanho; i++) printf("%d ", vector[i]);

    printf("\n");

    free(vector);
}

void vetorOrdenadoDecrescente(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = tamanho - i;

    quicksort(vector, 0, tamanho - 1);

    // for(int i = 0; i < tamanho; i++) printf("%d ", vector[i]);

    printf("\n");

    free(vector);
}

void vetorOrdenadoAleatorio(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = rand();

    quicksort(vector, 0, tamanho - 1);

    // for(int i = 0; i < tamanho; i++) printf("%d ", vector[i]);

    printf("\n");

    free(vector);
}

int main() {
    srand(time(NULL));

    // int umMilhao = 1000000;
    int dezMilhoes = 10000000;
    clock_t t;

    t = clock();
    vetorOrdenadoCrescente(dezMilhoes);
    t = clock() - t;

    printf("Tempo Ordenado Crescente: %f\n", (float)t / CLOCKS_PER_SEC);

    t = clock();
    vetorOrdenadoDecrescente(dezMilhoes);
    t = clock() - t;

    printf("Tempo Ordenado Decrescente: %f\n", (float)t / CLOCKS_PER_SEC);

    t = clock();
    vetorOrdenadoAleatorio(dezMilhoes);
    t = clock() - t;

    printf("Tempo Ordenado Aleatorio: %f\n", (float)t / CLOCKS_PER_SEC);

    return 0;
}
