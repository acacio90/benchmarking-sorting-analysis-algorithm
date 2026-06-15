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

* `src/main.c`: arquivo principal do programa, responsável pela criação dos vetores, execução dos Problemas 1, 2 e 3 e gravação dos resultados.
* `src/ordenacao.c`: contém a implementação dos algoritmos de ordenação.
* `src/ordenacao.h`: contém a estrutura de métricas e as declarações das funções de ordenação.
* `data/`: pasta reservada para armazenar os resultados brutos dos experimentos em formato `.csv` ou `.txt`.

## Como compilar

Para compilar o projeto, execute o comando abaixo na raiz do repositório:

```bash
gcc src/main.c src/ordenacao.c -lm -o programa
```

## Como executar no Windows

Após a compilação, execute o programa com:

```bash
.\programa.exe
```

## Como executar no WSL/Linux

Como o Problema 2 executa o Quick Sort clássico com pivô no último elemento em um vetor já ordenado, aumente o limite da pilha antes de rodar:

```bash
ulimit -s unlimited
./programa
```

## Arquivos gerados

O programa gera automaticamente os seguintes arquivos dentro da pasta `data`:

* `data/resultado.csv`: dados brutos em formato separado por ponto e vírgula.
* `data/resultado_problema1.txt`: resultados do Problema 1 em formato textual.
* `data/resultado_problema2.txt`: resultados do Problema 2 em formato textual.
* `data/resultado_problema3.txt`: resultados do Problema 3 em formato textual.

## Exemplo de saída

Exemplo do arquivo `data/resultado.csv`:

```csv
Problema;Cenario;Algoritmo;N;Tempo_s;Comparacoes;Trocas
1;Aleatorio;Insertion Sort;30000;0.308036;225697282;225667291
```

Exemplo dos arquivos `.txt` por problema:

```txt
Problema: 1
Cenario: Aleatorio
Bubble Sort Melhorado
Resultados:
Tempo: 2.793951 s
Comparacoes: 449885077
Trocas: 225521470
```

## Situação atual do desenvolvimento

O projeto está em fase de execução dos experimentos e organização dos resultados. Até o momento, foram implementados e testados:

* Estrutura de métricas;
* Separação dos algoritmos em arquivo próprio;
* Insertion Sort instrumentado;
* Selection Sort instrumentado;
* Bubble Sort Melhorado instrumentado;
* Shell Sort instrumentado;
* Quick Sort instrumentado;
* Heap Sort instrumentado.

Experimentos já automatizados:

* Problema 1: Insertion Sort, Selection Sort e Bubble Sort Melhorado nos cenários aleatório, ordenado e inverso com `N = 30000`.
* Problema 2: Heap Sort e Quick Sort clássico em vetor ordenado com `N = 5000`, 10 execuções, tempo médio e desvio padrão.
* Problema 3: Insertion Sort e Shell Sort em vetor quase ordenado com `N = 50000`.

Próximas etapas:

* Criar o relatório final com tabelas, gráficos e análise dos resultados.
