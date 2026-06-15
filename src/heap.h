#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef struct heap Heap;

/* Cria um heap com capacidade inicial */
Heap *heap_criar(size_t capacidade);

/* Insere um elemento no heap (heap máximo) */
void heap_inserir(Heap *h, int valor);

/* Remove e retorna o maior elemento */
int heap_remover(Heap *h);

/* Retorna o maior elemento sem remover */
int heap_topo(const Heap *h);

/* Retorna o número de elementos */
size_t heap_tamanho(const Heap *h);

/* Mostra o heap por níveis */
void heap_mostrar(const Heap *h);

/* Libera memória */
void heap_destruir(Heap *h);

#endif
