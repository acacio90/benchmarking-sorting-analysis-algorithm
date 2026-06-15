#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap.h"
#include "ordenacao.h"

// ---- FUNÇÕES AUXILIARES DE GERAÇÃO DE DADOS ----
void gerarVetorAleatorio(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100000;
}

void gerarVetorOrdenado(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = i;
}

void gerarVetorInverso(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = n - i;
}

void copiarVetor(int *destino, const int *origem, int n)
{
    for (int i = 0; i < n; i++)
    {
        destino[i] = origem[i];
    }
}

void heapSortComTad(int *vetor, int n)
{
    Heap *heap = heap_criar(n);

    for (int i = 0; i < n; i++)
    {
        heap_inserir(heap, vetor[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        vetor[i] = heap_remover(heap);
    }

    heap_destruir(heap);
}

double calcularTempo(struct timespec inicio, struct timespec fim)
{
    return (fim.tv_sec - inicio.tv_sec) +
           (fim.tv_nsec - inicio.tv_nsec) / 1e9;
}

int main()
{
    int N = 30000;
    int *vetorOriginal = (int *)malloc(N * sizeof(int));
    int *vetorInsertion = (int *)malloc(N * sizeof(int));
    int *vetorSelection = (int *)malloc(N * sizeof(int));
    int *vetorBubble = (int *)malloc(N * sizeof(int));
    int *vetorQuick = (int *)malloc(N * sizeof(int));
    int *vetorHeap = (int *)malloc(N * sizeof(int));

    if (vetorOriginal == NULL || vetorInsertion == NULL || vetorSelection == NULL ||
        vetorBubble == NULL || vetorQuick == NULL || vetorHeap == NULL)
    {
        free(vetorOriginal);
        free(vetorInsertion);
        free(vetorSelection);
        free(vetorBubble);
        free(vetorQuick);
        free(vetorHeap);
        return 1;
    }

    srand(42);

    gerarVetorAleatorio(vetorOriginal, N);
    copiarVetor(vetorInsertion, vetorOriginal, N);
    copiarVetor(vetorSelection, vetorOriginal, N);
    copiarVetor(vetorBubble, vetorOriginal, N);
    copiarVetor(vetorQuick, vetorOriginal, N);
    copiarVetor(vetorHeap, vetorOriginal, N);

    struct timespec inicio, fim;
    Metricas metricasInsertion;
    Metricas metricasSelection;
    Metricas metricasBubble;
    Metricas metricasQuick;
    Metricas metricasHeap;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetorInsertion, N, &metricasInsertion);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    metricasInsertion.tempo_segundos = calcularTempo(inicio, fim);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selectionSort(vetorSelection, N, &metricasSelection);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    metricasSelection.tempo_segundos = calcularTempo(inicio, fim);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortMelhorado(vetorBubble, N, &metricasBubble);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    metricasBubble.tempo_segundos = calcularTempo(inicio, fim);

    zerarMetricas(&metricasQuick);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    quickSort(vetorQuick, 0, N - 1, &metricasQuick);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    metricasQuick.tempo_segundos = calcularTempo(inicio, fim);

    zerarMetricas(&metricasHeap);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    heapSortComTad(vetorHeap, N);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    metricasHeap.tempo_segundos = calcularTempo(inicio, fim);

    printf("Insertion Sort\n");
    printf("Resultados:\nTempo: %f s\nComparacoes: %llu\nTrocas: %llu\n\n",
           metricasInsertion.tempo_segundos, metricasInsertion.comparacoes, metricasInsertion.trocas);

    printf("Selection Sort\n");
    printf("Resultados:\nTempo: %f s\nComparacoes: %llu\nTrocas: %llu\n\n",
           metricasSelection.tempo_segundos, metricasSelection.comparacoes, metricasSelection.trocas);

    printf("Bubble Sort Melhorado\n");
    printf("Resultados:\nTempo: %f s\nComparacoes: %llu\nTrocas: %llu\n\n",
           metricasBubble.tempo_segundos, metricasBubble.comparacoes, metricasBubble.trocas);

    printf("Quick Sort\n");
    printf("Resultados:\nTempo: %f s\nComparacoes: %llu\nTrocas: %llu\n\n",
           metricasQuick.tempo_segundos, metricasQuick.comparacoes, metricasQuick.trocas);

    printf("Heap Sort com TAD\n");
    printf("Resultados:\nTempo: %f s\n", metricasHeap.tempo_segundos);

    free(vetorOriginal);
    free(vetorInsertion);
    free(vetorSelection);
    free(vetorBubble);
    free(vetorQuick);
    free(vetorHeap);
    return 0;
}
