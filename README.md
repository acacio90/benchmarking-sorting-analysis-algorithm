# Benchmarking e Análise Empírica de Algoritmos de Ordenação

Este repositório contém o desenvolvimento do trabalho prático da disciplina de Estrutura de Dados, com foco na implementação, instrumentação e comparação empírica de algoritmos clássicos de ordenação em linguagem C.

O objetivo do projeto é medir e comparar o desempenho dos algoritmos considerando:

* Tempo de execução;
* Número de comparações;
* Número de trocas ou movimentações realizadas no vetor.

## Algoritmos implementados

Até o momento, foram implementados os seguintes algoritmos:

* Insertion Sort;
* Selection Sort;
* Bubble Sort Melhorado;
* Shell Sort;
* Quick Sort;
* Heap Sort.

## Estrutura do projeto

```txt
benchmarking-sorting-analysis-algorithm/
├── src/
│   ├── main.c
│   ├── ordenacao.c
│   └── ordenacao.h
├── data/
├── README.md
└── Trabalho Prático_ Benchmarking e Análise Empírica de Algoritmos de Ordenação.pdf
```

## Descrição dos arquivos

* `src/main.c`: arquivo principal do programa, responsável pela criação dos vetores, chamada dos algoritmos e exibição dos resultados.
* `src/ordenacao.c`: contém a implementação dos algoritmos de ordenação.
* `src/ordenacao.h`: contém a estrutura de métricas e as declarações das funções de ordenação.
* `data/`: pasta reservada para armazenar os resultados brutos dos experimentos em formato `.csv` ou `.txt`.

## Como compilar

Para compilar o projeto, execute o comando abaixo na raiz do repositório:

```bash
gcc src/main.c src/ordenacao.c -o programa
```

## Como executar

Após a compilação, execute o programa com:

```bash
.\programa.exe
```

O programa gera automaticamente dois arquivos dentro da pasta `data`:

* `data/resultado.csv`: dados brutos em formato separado por ponto e vírgula.
* `data/resultado.txt`: resultados em formato textual para leitura direta.

## Exemplo de saída

Exemplo do arquivo `data/resultado.csv`:

```csv
Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas
1;Aleatorio;Insertion Sort;30000;0.308036;225697282;225667291
```

Exemplo do arquivo `data/resultado.txt`:

```txt
Cenario: Aleatorio
Bubble Sort Melhorado
Resultados:
Tempo: 2.793951 s
Comparacoes: 449885077
Trocas: 225521470
```

## Situação atual do desenvolvimento

O projeto está em fase de implementação dos algoritmos exigidos no trabalho. Até o momento, foram implementados e testados:

* Estrutura de métricas;
* Separação dos algoritmos em arquivo próprio;
* Insertion Sort instrumentado;
* Selection Sort instrumentado;
* Bubble Sort Melhorado instrumentado;
* Shell Sort instrumentado;
* Quick Sort instrumentado;
* Heap Sort instrumentado.

Próximas etapas:

* Automatizar a execução dos algoritmos dos Problemas 2 e 3;
* Gerar arquivo com os dados brutos dos testes dos Problemas 2 e 3;
* Criar o relatório final com tabelas, gráficos e análise dos resultados.
