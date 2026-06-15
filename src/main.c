#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ordenacao.h"

#define N_PROBLEMA1 30000
#define N_PROBLEMA2 5000
#define N_PROBLEMA3 50000
#define EXECUCOES_PROBLEMA2 10

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

void gerarVetorQuaseOrdenado(int *v, int n)
{
    gerarVetorOrdenado(v, n);

    int quantidadeTrocas = n / 200;

    for (int i = 0; i < quantidadeTrocas; i++)
    {
        int posicao = rand() % (n - 1);
        int temp = v[posicao];
        v[posicao] = v[posicao + 1];
        v[posicao + 1] = temp;
    }
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

void salvarResultadoCsv(FILE *arquivo, int problema, const char *cenario, const char *algoritmo, int n, Metricas m)
{
    fprintf(arquivo, "%d;%s;%s;%d;%f;%llu;%llu\n",
            problema,
            cenario,
            algoritmo,
            n,
            m.tempo_segundos,
            m.comparacoes,
            m.trocas);
}

void salvarResultadoTxt(FILE *arquivo, int problema, const char *cenario, const char *algoritmo, Metricas m)
{
    fprintf(arquivo, "Problema: %d\n", problema);
    fprintf(arquivo, "Cenario: %s\n", cenario);
    fprintf(arquivo, "%s\n", algoritmo);
    fprintf(arquivo, "Resultados:\n");
    fprintf(arquivo, "Tempo: %f s\n", m.tempo_segundos);
    fprintf(arquivo, "Comparacoes: %llu\n", m.comparacoes);
    fprintf(arquivo, "Trocas: %llu\n\n", m.trocas);
}

double calcularMedia(const double *valores, int quantidade)
{
    double soma = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        soma += valores[i];
    }

    return soma / quantidade;
}

double calcularDesvioPadrao(const double *valores, int quantidade, double media)
{
    double soma = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        double diferenca = valores[i] - media;
        soma += diferenca * diferenca;
    }

    return sqrt(soma / (quantidade - 1));
}

void problema1(FILE *csv, FILE *txtProblema1)
{
    struct timespec inicio, fim;
    Metricas m;

    int *vetorOriginalProblema1 = (int *)malloc(N_PROBLEMA1 * sizeof(int));
    int *vetorTrabalhoProblema1 = (int *)malloc(N_PROBLEMA1 * sizeof(int));

    if (vetorOriginalProblema1 == NULL || vetorTrabalhoProblema1 == NULL)
    {
        free(vetorOriginalProblema1);
        free(vetorTrabalhoProblema1);
        exit(1);
    }

    // ---- PROBLEMA 1: ALEATÓRIO ----
    srand(42);
    gerarVetorAleatorio(vetorOriginalProblema1, N_PROBLEMA1);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Aleatorio", "Insertion Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Aleatorio", "Insertion Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selectionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Aleatorio", "Selection Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Aleatorio", "Selection Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortMelhorado(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Aleatorio", "Bubble Sort Melhorado", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Aleatorio", "Bubble Sort Melhorado", m);

    // ---- PROBLEMA 1: ORDENADO ----
    gerarVetorOrdenado(vetorOriginalProblema1, N_PROBLEMA1);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Ordenado", "Insertion Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Ordenado", "Insertion Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selectionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Ordenado", "Selection Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Ordenado", "Selection Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortMelhorado(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Ordenado", "Bubble Sort Melhorado", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Ordenado", "Bubble Sort Melhorado", m);

    // ---- PROBLEMA 1: INVERSO ----
    gerarVetorInverso(vetorOriginalProblema1, N_PROBLEMA1);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Inverso", "Insertion Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Inverso", "Insertion Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selectionSort(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Inverso", "Selection Sort", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Inverso", "Selection Sort", m);

    copiarVetor(vetorTrabalhoProblema1, vetorOriginalProblema1, N_PROBLEMA1);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortMelhorado(vetorTrabalhoProblema1, N_PROBLEMA1, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 1, "Inverso", "Bubble Sort Melhorado", N_PROBLEMA1, m);
    salvarResultadoTxt(txtProblema1, 1, "Inverso", "Bubble Sort Melhorado", m);

    free(vetorOriginalProblema1);
    free(vetorTrabalhoProblema1);
}

void problema2(FILE *csv, FILE *txtProblema2)
{
    struct timespec inicio, fim;
    Metricas m;
    int *vetorOriginalProblema2 = (int *)malloc(N_PROBLEMA2 * sizeof(int));
    int *vetorTrabalhoProblema2 = (int *)malloc(N_PROBLEMA2 * sizeof(int));
    double temposHeap[EXECUCOES_PROBLEMA2];
    double temposQuick[EXECUCOES_PROBLEMA2];

    if (vetorOriginalProblema2 == NULL || vetorTrabalhoProblema2 == NULL)
    {
        free(vetorOriginalProblema2);
        free(vetorTrabalhoProblema2);
        exit(1);
    }

    // ---- PROBLEMA 2 ----
    gerarVetorOrdenado(vetorOriginalProblema2, N_PROBLEMA2);

    for (int i = 0; i < EXECUCOES_PROBLEMA2; i++)
    {
        char cenario[32];
        sprintf(cenario, "Ordenado Execucao %d", i + 1);

        copiarVetor(vetorTrabalhoProblema2, vetorOriginalProblema2, N_PROBLEMA2);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        heapSort(vetorTrabalhoProblema2, N_PROBLEMA2, &m);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        m.tempo_segundos = calcularTempo(inicio, fim);
        temposHeap[i] = m.tempo_segundos;
        salvarResultadoCsv(csv, 2, cenario, "Heap Sort", N_PROBLEMA2, m);
        salvarResultadoTxt(txtProblema2, 2, cenario, "Heap Sort", m);

        copiarVetor(vetorTrabalhoProblema2, vetorOriginalProblema2, N_PROBLEMA2);
        zerarMetricas(&m);
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        quickSort(vetorTrabalhoProblema2, 0, N_PROBLEMA2 - 1, &m);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        m.tempo_segundos = calcularTempo(inicio, fim);
        temposQuick[i] = m.tempo_segundos;
        salvarResultadoCsv(csv, 2, cenario, "Quick Sort", N_PROBLEMA2, m);
        salvarResultadoTxt(txtProblema2, 2, cenario, "Quick Sort", m);
    }

    double mediaHeap = calcularMedia(temposHeap, EXECUCOES_PROBLEMA2);
    double mediaQuick = calcularMedia(temposQuick, EXECUCOES_PROBLEMA2);
    double desvioHeap = calcularDesvioPadrao(temposHeap, EXECUCOES_PROBLEMA2, mediaHeap);
    double desvioQuick = calcularDesvioPadrao(temposQuick, EXECUCOES_PROBLEMA2, mediaQuick);

    fprintf(txtProblema2, "Problema: 2\n");
    fprintf(txtProblema2, "Cenario: Ordenado\n");
    fprintf(txtProblema2, "Heap Sort\n");
    fprintf(txtProblema2, "Resumo de 10 execucoes:\n");
    fprintf(txtProblema2, "Tempo medio de execucao: %f s\n", mediaHeap);
    fprintf(txtProblema2, "Desvio padrao: %f s\n\n", desvioHeap);

    fprintf(txtProblema2, "Problema: 2\n");
    fprintf(txtProblema2, "Cenario: Ordenado\n");
    fprintf(txtProblema2, "Quick Sort\n");
    fprintf(txtProblema2, "Resumo de 10 execucoes:\n");
    fprintf(txtProblema2, "Tempo medio de execucao: %f s\n", mediaQuick);
    fprintf(txtProblema2, "Desvio padrao: %f s\n\n", desvioQuick);

    free(vetorOriginalProblema2);
    free(vetorTrabalhoProblema2);
}

void problema3(FILE *csv, FILE *txtProblema3)
{
    struct timespec inicio, fim;
    Metricas m;
    int *vetorOriginalProblema3 = (int *)malloc(N_PROBLEMA3 * sizeof(int));
    int *vetorTrabalhoProblema3 = (int *)malloc(N_PROBLEMA3 * sizeof(int));

    if (vetorOriginalProblema3 == NULL || vetorTrabalhoProblema3 == NULL)
    {
        free(vetorOriginalProblema3);
        free(vetorTrabalhoProblema3);
        exit(1);
    }

    // ---- PROBLEMA 3 ----
    srand(42);
    gerarVetorQuaseOrdenado(vetorOriginalProblema3, N_PROBLEMA3);

    copiarVetor(vetorTrabalhoProblema3, vetorOriginalProblema3, N_PROBLEMA3);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSort(vetorTrabalhoProblema3, N_PROBLEMA3, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 3, "Quase Ordenado", "Insertion Sort", N_PROBLEMA3, m);
    salvarResultadoTxt(txtProblema3, 3, "Quase Ordenado", "Insertion Sort", m);

    copiarVetor(vetorTrabalhoProblema3, vetorOriginalProblema3, N_PROBLEMA3);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    shellSort(vetorTrabalhoProblema3, N_PROBLEMA3, &m);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    m.tempo_segundos = calcularTempo(inicio, fim);
    salvarResultadoCsv(csv, 3, "Quase Ordenado", "Shell Sort", N_PROBLEMA3, m);
    salvarResultadoTxt(txtProblema3, 3, "Quase Ordenado", "Shell Sort", m);

    free(vetorOriginalProblema3);
    free(vetorTrabalhoProblema3);
}

int main()
{
    FILE *csvProblema1 = fopen("data/problema1.csv", "w");
    FILE *csvProblema2 = fopen("data/problema2.csv", "w");
    FILE *csvProblema3 = fopen("data/problema3.csv", "w");

    FILE *txtProblema1 = fopen("data/resultado_problema1.txt", "w");
    FILE *txtProblema2 = fopen("data/resultado_problema2.txt", "w");
    FILE *txtProblema3 = fopen("data/resultado_problema3.txt", "w");

    if (csvProblema1 == NULL || csvProblema2 == NULL || csvProblema3 == NULL ||
        txtProblema1 == NULL || txtProblema2 == NULL || txtProblema3 == NULL)
    {
        if (csvProblema1 != NULL)
            fclose(csvProblema1);

        if (csvProblema2 != NULL)
            fclose(csvProblema2);

        if (csvProblema3 != NULL)
            fclose(csvProblema3);

        if (txtProblema1 != NULL)
            fclose(txtProblema1);

        if (txtProblema2 != NULL)
            fclose(txtProblema2);

        if (txtProblema3 != NULL)
            fclose(txtProblema3);

        return 1;
    }

    fprintf(csvProblema1, "Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas\n");
    fprintf(csvProblema2, "Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas\n");
    fprintf(csvProblema3, "Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas\n");

    problema1(csvProblema1, txtProblema1);
    problema2(csvProblema2, txtProblema2);
    problema3(csvProblema3, txtProblema3);

    fclose(csvProblema1);
    fclose(csvProblema2);
    fclose(csvProblema3);

    fclose(txtProblema1);
    fclose(txtProblema2);
    fclose(txtProblema3);

    return 0;
}
