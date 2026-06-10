#include "ordenacao.h"

void zerarMetricas(Metricas *m)
{
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo_segundos = 0.0;
}

void selectionSort(int *vetor, int n, Metricas *m)
{
    zerarMetricas(m);

    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; j < n; j++)
        {
            m->comparacoes++;

            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            m->trocas++;
        }
    }
}

void insertionSort(int *vetor, int n, Metricas *m)
{
    zerarMetricas(m);

    for (int i = 1; i < n; i++)
    {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0)
        {
            m->comparacoes++;

            if (vetor[j] > chave)
            {
                vetor[j + 1] = vetor[j];
                m->trocas++;
                j--;
            }
            else
            {
                break;
            }
        }

        vetor[j + 1] = chave;
    }
}