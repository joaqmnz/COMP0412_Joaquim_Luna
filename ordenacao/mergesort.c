#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vector[], int inicio, int pivot, int fim) {
    int tamVector1 = pivot - inicio + 1;
    int tamVector2 = fim - pivot;

    int *vector1 = malloc(tamVector1 * sizeof(int));
    int *vector2 = malloc(tamVector2 * sizeof(int));

    for (int i = 0; i < tamVector1; i++) vector1[i] = vector[inicio + i];
    for (int i = 0; i < tamVector2; i++) vector2[i] = vector[pivot + 1 + i];

    int i = 0, j = 0, k = inicio;

    while (i < tamVector1 && j < tamVector2) {
        if (vector1[i] <= vector2[j]) {
            vector[k] = vector1[i];
            i++;
        } else {
            vector[k] = vector2[j];
            j++;
        }
        k++;
    }

    while (i < tamVector1) {
        vector[k] = vector1[i];
        i++;
        k++;
    }

    while (j < tamVector2) {
        vector[k] = vector2[j];
        j++;
        k++;
    }

    free(vector1);
    free(vector2);
}

void mergesort(int vector[], int inicio, int fim) {
    if (inicio < fim) {
        int pivot = (inicio + fim) / 2;

        mergesort(vector, inicio, pivot);
        mergesort(vector, pivot + 1, fim);

        merge(vector, inicio, pivot, fim);
    }
}

void vetorOrdenadoCrescente(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = i;

    mergesort(vector, 0, tamanho - 1);

    // for(int i = 0; i < tamanho; i++) printf("%d ", vector[i]);

    printf("\n");

    free(vector);
}

void vetorOrdenadoDecrescente(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = tamanho - i;

    mergesort(vector, 0, tamanho - 1);

    // for(int i = 0; i < tamanho; i++) printf("%d ", vector[i]);

    printf("\n");

    free(vector);
}

void vetorOrdenadoAleatorio(int tamanho) {
    int *vector = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) vector[i] = rand();

    mergesort(vector, 0, tamanho - 1);

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