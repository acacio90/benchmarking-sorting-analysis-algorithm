#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXECUCOES 50
#define MAX_LINHA 256

double calcularMedia(double valores[], int quantidade)
{
    double soma = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        soma += valores[i];
    }

    return soma / quantidade;
}

double calcularDesvioPadrao(double valores[], int quantidade, double media)
{
    double soma = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        double diferenca = valores[i] - media;
        soma += diferenca * diferenca;
    }

    return sqrt(soma / (quantidade - 1));
}

void gerarGraficoSvg(double mediaHeap, double desvioHeap,
                     double mediaQuick, double desvioQuick)
{
    FILE *arquivo = fopen("data/grafico_problema2.svg", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar data/grafico_problema2.svg\n");
        return;
    }

    int largura = 900;
    int altura = 550;

    int margemEsquerda = 110;
    int margemDireita = 60;
    int margemSuperior = 70;
    int margemInferior = 450;

    int alturaGrafico = margemInferior - margemSuperior;
    int larguraGrafico = largura - margemEsquerda - margemDireita;

    double maiorValor = mediaHeap + desvioHeap;

    if (mediaQuick + desvioQuick > maiorValor)
    {
        maiorValor = mediaQuick + desvioQuick;
    }

    maiorValor = maiorValor * 1.25;

    int larguraBarra = 110;
    int xHeap = 260;
    int xQuick = 560;

    int centroHeap = xHeap + larguraBarra / 2;
    int centroQuick = xQuick + larguraBarra / 2;

    double yHeap = margemInferior - (mediaHeap / maiorValor) * alturaGrafico;
    double yQuick = margemInferior - (mediaQuick / maiorValor) * alturaGrafico;

    double hHeap = margemInferior - yHeap;
    double hQuick = margemInferior - yQuick;

    double yHeapErroCima = margemInferior - ((mediaHeap + desvioHeap) / maiorValor) * alturaGrafico;
    double yHeapErroBaixo = margemInferior - ((mediaHeap - desvioHeap) / maiorValor) * alturaGrafico;

    double yQuickErroCima = margemInferior - ((mediaQuick + desvioQuick) / maiorValor) * alturaGrafico;
    double yQuickErroBaixo = margemInferior - ((mediaQuick - desvioQuick) / maiorValor) * alturaGrafico;

    fprintf(arquivo, "<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg'>\n", largura, altura);
    fprintf(arquivo, "<rect width='100%%' height='100%%' fill='white'/>\n");

    fprintf(arquivo, "<text x='450' y='35' text-anchor='middle' font-size='24' font-family='Arial'>");
    fprintf(arquivo, "Tempo medio de execucao - Problema 2");
    fprintf(arquivo, "</text>\n");

    for (int i = 0; i <= 5; i++)
    {
        double valor = (maiorValor / 5.0) * i;
        double y = margemInferior - (valor / maiorValor) * alturaGrafico;

        fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='#dddddd' stroke-width='1'/>\n",
                margemEsquerda, y, margemEsquerda + larguraGrafico, y);

        fprintf(arquivo, "<text x='95' y='%.2f' text-anchor='end' font-size='12' font-family='Arial'>%.4f</text>\n",
                y + 4, valor);
    }

    fprintf(arquivo, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='black' stroke-width='2'/>\n",
            margemEsquerda, margemInferior, margemEsquerda + larguraGrafico, margemInferior);

    fprintf(arquivo, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='black' stroke-width='2'/>\n",
            margemEsquerda, margemSuperior, margemEsquerda, margemInferior);

    fprintf(arquivo, "<text x='35' y='270' text-anchor='middle' font-size='15' font-family='Arial' transform='rotate(-90 35,270)'>");
    fprintf(arquivo, "Tempo medio (s)");
    fprintf(arquivo, "</text>\n");

    fprintf(arquivo, "<rect x='%d' y='%.2f' width='%d' height='%.2f' fill='#4e79a7'/>\n",
            xHeap, yHeap, larguraBarra, hHeap);

    fprintf(arquivo, "<rect x='%d' y='%.2f' width='%d' height='%.2f' fill='#f28e2b'/>\n",
            xQuick, yQuick, larguraBarra, hQuick);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroHeap, yHeapErroCima, centroHeap, yHeapErroBaixo);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroHeap - 18, yHeapErroCima, centroHeap + 18, yHeapErroCima);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroHeap - 18, yHeapErroBaixo, centroHeap + 18, yHeapErroBaixo);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroQuick, yQuickErroCima, centroQuick, yQuickErroBaixo);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroQuick - 18, yQuickErroCima, centroQuick + 18, yQuickErroCima);

    fprintf(arquivo, "<line x1='%d' y1='%.2f' x2='%d' y2='%.2f' stroke='black' stroke-width='2'/>\n",
            centroQuick - 18, yQuickErroBaixo, centroQuick + 18, yQuickErroBaixo);

    fprintf(arquivo, "<text x='%d' y='485' text-anchor='middle' font-size='16' font-family='Arial'>Heap Sort</text>\n",
            centroHeap);

    fprintf(arquivo, "<text x='%d' y='485' text-anchor='middle' font-size='16' font-family='Arial'>Quick Sort</text>\n",
            centroQuick);

    fprintf(arquivo, "<text x='%d' y='%.2f' text-anchor='middle' font-size='13' font-family='Arial'>%.6f s</text>\n",
            centroHeap, yHeap - 12, mediaHeap);

    fprintf(arquivo, "<text x='%d' y='%.2f' text-anchor='middle' font-size='13' font-family='Arial'>%.6f s</text>\n",
            centroQuick, yQuick - 12, mediaQuick);

    fprintf(arquivo, "</svg>\n");

    fclose(arquivo);
}

int main()
{
    FILE *arquivo = fopen("data/problema2.csv", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir data/problema2.csv\n");
        return 1;
    }

    char linha[MAX_LINHA];

    double temposHeap[MAX_EXECUCOES];
    double temposQuick[MAX_EXECUCOES];

    int qtdHeap = 0;
    int qtdQuick = 0;

    fgets(linha, MAX_LINHA, arquivo);

    while (fgets(linha, MAX_LINHA, arquivo) != NULL)
    {
        int problema;
        int n;
        char cenario[100];
        char algoritmo[100];
        double tempo;
        unsigned long long comparacoes;
        unsigned long long trocas;

        int lidos = sscanf(linha, "%d;%99[^;];%99[^;];%d;%lf;%llu;%llu",
                           &problema,
                           cenario,
                           algoritmo,
                           &n,
                           &tempo,
                           &comparacoes,
                           &trocas);

        if (lidos == 7 && problema == 2)
        {
            if (strcmp(algoritmo, "Heap Sort") == 0 && qtdHeap < MAX_EXECUCOES)
            {
                temposHeap[qtdHeap] = tempo;
                qtdHeap++;
            }
            else if (strcmp(algoritmo, "Quick Sort") == 0 && qtdQuick < MAX_EXECUCOES)
            {
                temposQuick[qtdQuick] = tempo;
                qtdQuick++;
            }
        }
    }

    fclose(arquivo);

    if (qtdHeap < 2 || qtdQuick < 2)
    {
        printf("Dados insuficientes para calcular media e desvio padrao.\n");
        return 1;
    }

    double mediaHeap = calcularMedia(temposHeap, qtdHeap);
    double mediaQuick = calcularMedia(temposQuick, qtdQuick);

    double desvioHeap = calcularDesvioPadrao(temposHeap, qtdHeap, mediaHeap);
    double desvioQuick = calcularDesvioPadrao(temposQuick, qtdQuick, mediaQuick);

    gerarGraficoSvg(mediaHeap, desvioHeap, mediaQuick, desvioQuick);

    printf("Grafico gerado com sucesso!\n");
    printf("Heap Sort  - Media: %.6f s | Desvio padrao: %.6f s\n", mediaHeap, desvioHeap);
    printf("Quick Sort - Media: %.6f s | Desvio padrao: %.6f s\n", mediaQuick, desvioQuick);
    printf("Arquivo gerado: data/grafico_problema2.svg\n");

    return 0;
}