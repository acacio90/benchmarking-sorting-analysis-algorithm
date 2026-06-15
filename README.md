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
* Heap Sort.

## Estrutura do projeto

```txt
benchmarking-sorting-analysis-algorithm/
├── src/
│   ├── main.c
│   ├── heap.c
│   ├── heap.h
│   ├── ordenacao.c
│   └── ordenacao.h
├── data/
├── README.md
└── Trabalho Prático_ Benchmarking e Análise Empírica de Algoritmos de Ordenação.pdf
```

## Descrição dos arquivos

* `src/main.c`: arquivo principal do programa, responsável pela criação dos vetores, chamada dos algoritmos e exibição dos resultados.
* `src/heap.c`: contém a implementação do TAD de heap.
* `src/heap.h`: contém a estrutura do TAD de heap e as declarações das funções relacionadas.
* `src/ordenacao.c`: contém a implementação dos algoritmos de ordenação.
* `src/ordenacao.h`: contém a estrutura de métricas e as declarações das funções de ordenação.
* `data/`: pasta reservada para armazenar os resultados brutos dos experimentos em formato `.csv` ou `.txt`.

## Como compilar

Para compilar o projeto, execute o comando abaixo na raiz do repositório:

```bash
gcc src/main.c src/ordenacao.c src/heap.c -o programa
```

## Como executar

Após a compilação, execute o programa com:

```bash
.\programa.exe
```

## Exemplo de saída

```txt
Bubble Sort Melhorado
Resultados:
Tempo: 2.793951 s
Comparacoes: 449885077
Trocas: 225521470
```

## Salvando os resultados em arquivo

Para salvar os resultados em um arquivo de texto ou CSV dentro da pasta `data`, utilize o redirecionamento de saída:

```bash
.\programa.exe > data/resultado.txt
```

Ou, futuramente, quando o programa gerar resultados em formato separado por ponto e vírgula:

```bash
.\programa.exe > data/problema1.csv
```

## Situação atual do desenvolvimento

O projeto está em fase de implementação dos algoritmos exigidos no trabalho. Até o momento, foram implementados e testados:

* Estrutura de métricas;
* Separação dos algoritmos em arquivo próprio;
* Insertion Sort instrumentado;
* Selection Sort instrumentado;
* Bubble Sort Melhorado instrumentado;
* Heap Sort implementado usando o TAD de heap.

Próximas etapas:

* Automatizar a execução dos algoritmos nos três cenários do Problema 1:

  * vetor aleatório;
  * vetor ordenado;
  * vetor inverso.
* Gerar arquivo com os dados brutos dos testes;
* Implementar Shellsort;
* Implementar Quicksort clássico;
* Criar o relatório final com tabelas, gráficos e análise dos resultados.
