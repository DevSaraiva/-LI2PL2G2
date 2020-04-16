/**
@file listas.h
Definição das funções relacionadas com listas ligadas
*/



#ifndef _GUIAO5_LISTAS_H
#define _GUIAO5_LISTAS_H

#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct slist
{
    void *valor;
    struct slist *prox;
}Nodo;


typedef struct slist *LISTA;




/**
\brief Função que  cria uma lista vazia
*/

LISTA criar_lista();

/**
\brief Função que  insere um valor na cabeça da lista
*/

LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Função que  devolve a cabeça da lista
*/

void *devolve_cabeca(LISTA L);


/**
\brief Função que devolve a cauda da lista
*/
LISTA proximo(LISTA L);

/**
\brief Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
*/

LISTA remove_cabeca(LISTA L);

/**
\brief Função que devolve verdareiro se a lista é vazia
*/

int lista_esta_vazia(LISTA L);

#endif //_GUIAO5_LISTAS_H
