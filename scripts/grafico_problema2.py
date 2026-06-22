import csv
import math
import os
import matplotlib.pyplot as plt

ARQUIVO_ENTRADA = "data/problema2.csv"
ARQUIVO_SAIDA = "data/grafico_problema2.png"


def carregar_tempos(caminho):
    tempos = {}

    with open(caminho, mode="r", encoding="utf-8") as arquivo:
        leitor = csv.DictReader(arquivo, delimiter=";")

        if leitor.fieldnames is None:
            print("Erro: o arquivo CSV está vazio.")
            return None

        print("Colunas encontradas no CSV:", leitor.fieldnames)

        colunas_obrigatorias = ["Algoritmo", "Tempo_s"]

        for coluna in colunas_obrigatorias:
            if coluna not in leitor.fieldnames:
                print(f"Erro: coluna obrigatória não encontrada: {coluna}")
                print("Cabeçalho esperado:")
                print("Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas")
                return None

        for linha in leitor:
            algoritmo = linha["Algoritmo"]
            tempo = float(linha["Tempo_s"].replace(",", "."))

            if algoritmo not in tempos:
                tempos[algoritmo] = []

            tempos[algoritmo].append(tempo)

    return tempos


def calcular_media(valores):
    return sum(valores) / len(valores)


def calcular_desvio_padrao(valores):
    media = calcular_media(valores)

    if len(valores) <= 1:
        return 0.0

    soma = sum((valor - media) ** 2 for valor in valores)
    variancia = soma / (len(valores) - 1)

    return math.sqrt(variancia)


def gerar_grafico(tempos):
    algoritmos = []
    medias = []
    desvios = []

    ordem = ["Heap Sort", "Quick Sort"]

    for algoritmo in ordem:
        if algoritmo in tempos:
            valores = tempos[algoritmo]
            algoritmos.append(algoritmo)
            medias.append(calcular_media(valores))
            desvios.append(calcular_desvio_padrao(valores))

    if len(algoritmos) < 2:
        print("Erro: o CSV precisa conter dados de Heap Sort e Quick Sort.")
        return

    plt.figure(figsize=(8, 6))

    barras = plt.bar(algoritmos, medias, yerr=desvios, capsize=8)

    plt.title("Problema 2 - Tempo médio de execução")
    plt.xlabel("Algoritmo")
    plt.ylabel("Tempo médio (segundos)")
    plt.grid(axis="y", linestyle="--", alpha=0.5)

    for barra, media in zip(barras, medias):
        altura = barra.get_height()
        plt.text(
            barra.get_x() + barra.get_width() / 2,
            altura,
            f"{media:.6f}s",
            ha="center",
            va="bottom"
        )

    plt.tight_layout()

    os.makedirs("data", exist_ok=True)
    plt.savefig(ARQUIVO_SAIDA, dpi=300)
    plt.close()

    print(f"Gráfico gerado com sucesso: {ARQUIVO_SAIDA}")


def main():
    if not os.path.exists(ARQUIVO_ENTRADA):
        print(f"Arquivo não encontrado: {ARQUIVO_ENTRADA}")
        print("Primeiro compile e execute o programa em C para gerar data/problema2.csv.")
        return

    tempos = carregar_tempos(ARQUIVO_ENTRADA)

    if tempos is None:
        return

    gerar_grafico(tempos)


if __name__ == "__main__":
    main()