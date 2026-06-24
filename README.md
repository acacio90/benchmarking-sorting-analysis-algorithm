# Benchmarking e Análise Empírica de Algoritmos de Ordenação

Este repositório contém o desenvolvimento do trabalho prático da disciplina de Estrutura de Dados, com foco na implementação, instrumentação e comparação empírica de algoritmos clássicos de ordenação em linguagem C.

O objetivo do projeto é medir e comparar o desempenho dos algoritmos considerando:

* Tempo de execução;
* Número de comparações;
* Número de trocas ou movimentações realizadas no vetor.

## Algoritmos implementados

Foram implementados os seguintes algoritmos:

* Insertion Sort;
* Selection Sort;
* Bubble Sort Melhorado;
* Shell Sort;
* Quick Sort clássico;
* Heap Sort.

## Estrutura do projeto

```txt
benchmarking-sorting-analysis-algorithm/
├── src/
│   ├── main.c
│   ├── ordenacao.c
│   └── ordenacao.h
├── data/
│   ├── resultados_gabriel/
│   │   ├── problema1.csv
│   │   ├── problema2.csv
│   │   ├── problema3.csv
│   │   ├── resultado_problema1.txt
│   │   ├── resultado_problema2.txt
│   │   ├── resultado_problema3.txt
│   │   └── grafico_problema2.png
│   └── resultados_pedro/
│       ├── problema1.csv
│       ├── problema2.csv
│       ├── problema3.csv
│       ├── resultado_problema1.txt
│       ├── resultado_problema2.txt
│       ├── resultado_problema3.txt
│       └── grafico_problema2.png
├── scripts/
│   └── grafico_problema2.py
├── .gitignore
├── README.md
├── Relatório_ED.pdf
└── Trabalho Prático_ Benchmarking e Análise Empírica de Algoritmos de Ordenação.pdf
```

## Descrição dos arquivos

* `src/main.c`: arquivo principal do programa, responsável por gerar os vetores, executar os Problemas 1, 2 e 3 e gravar os resultados.
* `src/ordenacao.c`: contém a implementação dos algoritmos de ordenação.
* `src/ordenacao.h`: contém a estrutura `Metricas` e as declarações das funções de ordenação.
* `data/resultados_gabriel/`: resultados gerados no ambiente de Gabriel Pereira do Carmo (Windows/WSL, Intel Core i3-1005G1).
* `data/resultados_pedro/`: resultados gerados no ambiente de Pedro Acácio Rodrigues (WSL/Ubuntu, Intel Core i7-14700).
* Cada subpasta contém: `problema1.csv`, `problema2.csv`, `problema3.csv`, arquivos `.txt` com os resultados por problema e `grafico_problema2.png`.
* `scripts/grafico_problema2.py`: script em Python que lê o arquivo `problema2.csv` de uma das subpastas e gera o gráfico de barras.
* `.gitignore`: arquivo utilizado para ignorar executáveis e arquivos temporários.
* `Relatório_ED.pdf`: relatório final de execução do projeto.
* `Trabalho Prático_ Benchmarking e Análise Empírica de Algoritmos de Ordenação.pdf`: enunciado original do trabalho prático.

## Como compilar

Para compilar o projeto, execute o comando abaixo na raiz do repositório:

```bash
gcc src/main.c src/ordenacao.c -lm -o programa
```

No Windows, caso o compilador aceite sem `-lm`, também pode ser utilizado:

```bash
gcc src/main.c src/ordenacao.c -o programa
```

## Como executar no Windows

Após a compilação, execute:

```bash
.\programa.exe
```

A execução gera automaticamente os arquivos de resultado dentro da pasta `data`.

## Como executar no WSL/Linux

Como o Problema 2 executa o Quick Sort clássico com pivô no último elemento em um vetor já ordenado, recomenda-se aumentar o limite da pilha antes de rodar:

```bash
ulimit -s unlimited
./programa
```

## Como gerar o gráfico do Problema 2

O script lê por padrão o arquivo `data/problema2.csv`. Aponte-o para a subpasta desejada antes de executar (`resultados_gabriel` ou `resultados_pedro`), ajustando a variável `ARQUIVO_ENTRADA` em `scripts/grafico_problema2.py`.

Instale a dependência do Python, se necessário:

```bash
pip install matplotlib
# ou, em sistemas gerenciados (Debian/Ubuntu):
sudo apt install python3-matplotlib
```

Em seguida, execute o script a partir da raiz do repositório:

```bash
python3 scripts/grafico_problema2.py
```

O gráfico será salvo na pasta `data/` configurada no script.

## Arquivos gerados

O programa em C gera os arquivos na raiz de `data/`. Para preservar os resultados por ambiente, mova-os manualmente para a subpasta correspondente (`resultados_gabriel/` ou `resultados_pedro/`) após cada execução:

* `problema1.csv`, `problema2.csv`, `problema3.csv`;
* `resultado_problema1.txt`, `resultado_problema2.txt`, `resultado_problema3.txt`.

O script Python gera `grafico_problema2.png` na pasta configurada em `ARQUIVO_SAIDA`.

## Formato dos arquivos CSV

Os arquivos `.csv` seguem o formato separado por ponto e vírgula:

```csv
Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas
1;Aleatorio;Insertion Sort;30000;0.929437;225551463;225521470
```

## Exemplo dos arquivos TXT

```txt
Problema: 1
Cenario: Aleatorio
Insertion Sort
Resultados:
Tempo: 0.929437 s
Comparacoes: 225551463
Trocas: 225521470
```

## Experimentos automatizados

### Problema 1

Executa os algoritmos:

* Insertion Sort;
* Selection Sort;
* Bubble Sort Melhorado.

Cenários utilizados:

* Vetor aleatório;
* Vetor ordenado;
* Vetor inverso.

Tamanho do vetor:

```txt
N = 30000
```

### Problema 2

Executa os algoritmos:

* Heap Sort;
* Quick Sort clássico com pivô no último elemento.

Cenário utilizado:

* Vetor já ordenado em ordem crescente.

Configuração:

```txt
N = 5000
Execuções = 10
```

O programa registra os tempos de cada execução e calcula o tempo médio e o desvio padrão no arquivo `data/resultado_problema2.txt`.

O gráfico solicitado no trabalho é gerado pelo script `scripts/grafico_problema2.py`.

Resumo final obtido no Problema 2 (Pedro — WSL/Ubuntu):

```txt
Heap Sort
Tempo médio de execução: 0.000413 s
Desvio padrão: 0.000033 s

Quick Sort
Tempo médio de execução: 0.010456 s
Desvio padrão: 0.000234 s
```

### Problema 3

Executa os algoritmos:

* Insertion Sort;
* Shell Sort.

Cenário utilizado:

* Vetor quase ordenado.

Tamanho do vetor:

```txt
N = 50000
```

O vetor quase ordenado é criado a partir de um vetor ordenado, realizando trocas entre elementos vizinhos em aproximadamente 0,5% das posições.

## Situação atual do projeto

O projeto já possui:

* Estrutura de métricas implementada;
* Separação dos algoritmos em arquivo próprio;
* Implementação dos seis algoritmos exigidos;
* Execução automatizada dos três problemas;
* Geração dos arquivos CSV;
* Geração dos arquivos TXT;
* Script Python para gerar o gráfico do Problema 2;
* Gráfico do Problema 2 salvo em `data/grafico_problema2.png`;
* Dados finais utilizados na elaboração do relatório.

O relatório de execução final está disponível no arquivo `Relatório_ED.pdf`, elaborado com base nos dados finais gerados pelo projeto.
