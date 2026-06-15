#include "ordenacao.h"

void zerarMetricas(Metricas *m)
{
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo_segundos = 0.0;
}

static void trocarElementos(int *a, int *b, Metricas *m)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    m->trocas++;
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
void bubbleSortMelhorado(int *vetor, int n, Metricas *m)
{
    zerarMetricas(m);

    int limite = n - 1;

    while (limite > 0)
    {
        int ultimaTroca = 0;

        for (int i = 0; i < limite; i++)
        {
            m->comparacoes++;

            if (vetor[i] > vetor[i + 1])
            {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;

                m->trocas++;
                ultimaTroca = i;
            }
        }

        if (ultimaTroca == 0)
        {
            break;
        }

        limite = ultimaTroca;
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

void shellSort(int *vetor, int n, Metricas *m)
{
    zerarMetricas(m);

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int chave = vetor[i];
            int j = i;

            while (j >= gap)
            {
                m->comparacoes++;

                if (vetor[j - gap] > chave)
                {
                    vetor[j] = vetor[j - gap];
                    m->trocas++;
                    j -= gap;
                }
                else
                {
                    break;
                }
            }

            vetor[j] = chave;
        }
    }
}

void quickSort(int *vetor, int inicio, int fim, Metricas *m)
{
    if (inicio < fim)
    {
        int pivo = vetor[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++)
        {
            m->comparacoes++;

            if (vetor[j] <= pivo)
            {
                i++;

                if (i != j)
                {
                    trocarElementos(&vetor[i], &vetor[j], m);
                }
            }
        }

        if (i + 1 != fim)
        {
            trocarElementos(&vetor[i + 1], &vetor[fim], m);
        }

        int posicaoPivo = i + 1;

        quickSort(vetor, inicio, posicaoPivo - 1, m);
        quickSort(vetor, posicaoPivo + 1, fim, m);
    }
}

static void descerHeap(int *vetor, int n, int i, Metricas *m)
{
    while (2 * i + 1 < n)
    {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = esq;

        if (dir < n)
        {
            m->comparacoes++;

            if (vetor[dir] > vetor[esq])
            {
                maior = dir;
            }
        }

        m->comparacoes++;

        if (vetor[i] >= vetor[maior])
        {
            return;
        }

        trocarElementos(&vetor[i], &vetor[maior], m);
        i = maior;
    }
}

void heapSort(int *vetor, int n, Metricas *m)
{
    zerarMetricas(m);

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        descerHeap(vetor, n, i, m);
    }

    for (int fim = n - 1; fim > 0; fim--)
    {
        trocarElementos(&vetor[0], &vetor[fim], m);
        descerHeap(vetor, fim, 0, m);
    }
}
