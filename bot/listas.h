/**
@file listas.h
Definição das funções relacionadas com listas ligadas
*/



#ifndef _GUIAO5_LISTAS_H
#define _GUIAO5_LISTAS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_de_dados.h"

/**
\brief  Lista ligada genérica
*/
typedef struct slist
{
    void *valor;
    struct slist *prox;
}Nodo;

/**
\brief  Ponteiro para uma lista
*/
typedef struct slist *LISTA;

/**
\brief Função que  cria uma lista vazia
\return O ponteiro para a lista
*/

LISTA criar_lista();

/**
\brief Função que  insere um valor na cabeça da lista
\return O ponteiro para a o primeiro elemento da lista
*/

LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Função que  devolve a cabeça da lista
*/

void *devolve_cabeca(LISTA L);


/**
\brief Função que devolve a cauda da lista
\return O ponteiro para o primeiro elemento da cauda da lista
*/
LISTA proximo(LISTA L);

/**
\brief Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
\return O ponteiro para o primeiro elemento da cauda da lista
*/

LISTA remove_cabeca(LISTA L);

/**
\brief Função que devolve verdareiro se a lista é vazia
\return 1 se estiver vazia ou 0 caso contrário  
*/

int lista_esta_vazia(LISTA L);

#endif //_GUIAO5_LISTAS_H
