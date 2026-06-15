#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

#define N 30000

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

double calcularTempo(struct timespec inicio, struct timespec fim)
{
    return (fim.tv_sec - inicio.tv_sec) +
           (fim.tv_nsec - inicio.tv_nsec) / 1e9;
}

void salvarResultadoCsv(FILE *arquivo, const char *cenario, const char *algoritmo, Metricas m)
{
    fprintf(arquivo, "1;%s;%s;%d;%f;%llu;%llu\n",
            cenario,
            algoritmo,
            N,
            m.tempo_segundos,
            m.comparacoes,
            m.trocas);
}

void salvarResultadoTxt(FILE *arquivo, const char *cenario, const char *algoritmo, Metricas m)
{
    fprintf(arquivo, "Cenario: %s\n", cenario);
    fprintf(arquivo, "%s\n", algoritmo);
    fprintf(arquivo, "Resultados:\n");
    fprintf(arquivo, "Tempo: %f s\n", m.tempo_segundos);
    fprintf(arquivo, "Comparacoes: %llu\n", m.comparacoes);
    fprintf(arquivo, "Trocas: %llu\n\n", m.trocas);
}

void salvarCabecalhoCsv(FILE *arquivo)
{
    fprintf(arquivo, "Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas\n");
}

void salvarResultado(FILE *csv, FILE *txt, const char *cenario, const char *algoritmo, Metricas m)
{
    salvarResultadoCsv(csv, cenario, algoritmo, m);
    salvarResultadoTxt(txt, cenario, algoritmo, m);
}

void executarInsertion(const char *cenario, const int *vetorOriginal, FILE *csv, FILE *txt)
{
    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL)
        exit(1);

    copiarVetor(vetor, vetorOriginal, N);

    struct timespec inicio, fim;
    Metricas m;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetor, N, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultado(csv, txt, cenario, "Insertion Sort", m);

    free(vetor);
}

void executarSelection(const char *cenario, const int *vetorOriginal, FILE *csv, FILE *txt)
{
    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL)
        exit(1);

    copiarVetor(vetor, vetorOriginal, N);

    struct timespec inicio, fim;
    Metricas m;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selectionSort(vetor, N, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultado(csv, txt, cenario, "Selection Sort", m);

    free(vetor);
}

void executarBubble(const char *cenario, const int *vetorOriginal, FILE *csv, FILE *txt)
{
    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL)
        exit(1);

    copiarVetor(vetor, vetorOriginal, N);

    struct timespec inicio, fim;
    Metricas m;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortMelhorado(vetor, N, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultado(csv, txt, cenario, "Bubble Sort Melhorado", m);

    free(vetor);
}

void executarCenario(const char *cenario, int *vetorOriginal, FILE *csv, FILE *txt)
{
    executarInsertion(cenario, vetorOriginal, csv, txt);
    executarSelection(cenario, vetorOriginal, csv, txt);
    executarBubble(cenario, vetorOriginal, csv, txt);
}

int main()
{
    int *vetorOriginal = (int *)malloc(N * sizeof(int));

    if (vetorOriginal == NULL)
        return 1;

    FILE *csv = fopen("data/resultado.csv", "w");
    FILE *txt = fopen("data/resultado.txt", "w");

    if (csv == NULL || txt == NULL)
    {
        free(vetorOriginal);

        if (csv != NULL)
            fclose(csv);

        if (txt != NULL)
            fclose(txt);

        return 1;
    }

    salvarCabecalhoCsv(csv);

    srand(42);
    gerarVetorAleatorio(vetorOriginal, N);
    executarCenario("Aleatorio", vetorOriginal, csv, txt);

    gerarVetorOrdenado(vetorOriginal, N);
    executarCenario("Ordenado", vetorOriginal, csv, txt);

    gerarVetorInverso(vetorOriginal, N);
    executarCenario("Inverso", vetorOriginal, csv, txt);

    fclose(csv);
    fclose(txt);
    free(vetorOriginal);
    return 0;
}
