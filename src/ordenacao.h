#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct
{
    unsigned long long comparacoes;
    unsigned long long trocas;
    double tempo_segundos;
} Metricas;

void zerarMetricas(Metricas *m);

void insertionSort(int *vetor, int n, Metricas *m);
void selectionSort(int *vetor, int n, Metricas *m);

#endif