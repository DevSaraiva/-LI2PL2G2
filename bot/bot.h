/**
@file bot.h
Definição das funções relacionadas com listas ligadas
*/



#ifndef _BOT_H
#define _BOT_H

#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"

/**
\brief  Função que cria uma lista com todas as jogadas possiveis
*/

LISTA jogada_possivel (ESTADO *e,COORDENADA c);


/**
\brief  Estrutura que possiblita a implementação do MinMax
*/

typedef struct MinMaxTREE {
    COORDENADA coord;
    int valor;
    struct MinMaxTREE  *nodo1;
    struct MinMaxTREE  *nodo2;
    struct MinMaxTREE  *nodo3;
    struct MinMaxTREE  *nodo4;
    struct MinMaxTREE  *nodo5;
    struct MinMaxTREE  *nodo6;
    struct MinMaxTREE  *nodo7;
    struct MinMaxTREE  *nodo8;
} TREEMinMax;

/**
\brief  Função que dadas 1 coordenada calcula a distância euclidiana entre essa e posição onde termina o jogo considerando o jogador atuak
*/

double calcula_dist(COORDENADA * C, int jog);


/**
\brief  Função que aplica a heuristica do vizinho mais proximo e joga automáticamente
*/
COORDENADA joga_euclidiana (ESTADO *e);

/**
\brief  Função que aplica a heuristica aleatoria e joga automáticamente
*/
COORDENADA joga_aleatorio (ESTADO *e);
/**
\brief  Função que aplica a heuristica aleatoria e joga automáticamente
*/
double atribui_valor (ESTADO *e, int jog_max, COORDENADA c);
/**
\brief  Função que aplica a heuristica aleatoria e joga automáticamente
*/
TREEMinMax create_tree (int depth, ESTADO *e, COORDENADA c);
/**
\brief  Função que aplica a heuristica aleatoria e joga automáticamente
*/
void joga_MinMax(ESTADO *e);
/**
\brief  Função que verifica se c torna a jogada presa
*/
int verifica_jogada_flood (ESTADO *e,COORDENADA  c);
/**
\brief  Função que aplica a heuristica flood
*/
COORDENADA joga_flood (ESTADO *e);

#endif //_GUIAO5_BOT_H
