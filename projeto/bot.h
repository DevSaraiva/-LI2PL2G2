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
    ESTADO * e;
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
\brief  Função que aplica a heuristica do floddfill e joga automáticamente
*/
int verifica_jogada_flood (ESTADO *e,COORDENADA c);
/**
\brief COORDENADA auxiliar para a heuristica floddfill
*/
COORDENADA joga_flood (ESTADO *e);

/**
\brief Função atribui uma classificação a determinado nodo de acordo com a sua posição relativa em relação à casa vitoriosa
*/


int atribui_valor (ESTADO *e, int jog_max, COORDENADA c);

/**
\brief Função preenche o valor de determinado nodo atravês da função atribui valor
*/

void fill_valor ( TREEMinMax * tree, int max_jog);

/**
\brief Função que cria uma arvore com 8 nodos
*/


TREEMinMax * create_tree();

/**
\brief Função que cria uma arvore vazia
*/

TREEMinMax * create_tree_vazia();


/**
\brief Função que cria uma arvore completa com a profundidade desejada
*/

TREEMinMax * create_tree_total (int depth, ESTADO * e, int jog_max, COORDENADA c);


/**
\brief Função verifica se uma arvore está terminada
*/

int is_tree_finished(TREEMinMax * tree);


/**
\brief Função verifica se uma arvore termina nos proximos nodos
*/

int is_last_decision (TREEMinMax * tree);

/**
\brief Função que devolve a coordenada correspondente ao nodo com  determinado valor atribuido 
*/

COORDENADA devolve_coordenada (TREEMinMax * tree, int val);


/**
\brief Função que o calcula qual a arvore que possui o valor mais alto
*/

int  max_nodo (TREEMinMax * tree);



/**
\brief Função que o calcula qual a arvore que possui o valor mais baixo
*/


int  min_nodo (TREEMinMax * tree);


/**
\brief Função que calcula o valor de cada nodo atravês das previsões das jogadas para arvores com profundidade 1
*/


void fill_valor ( TREEMinMax * tree, int max_jog);

/**
\brief Função que aplica fill valor a qualquer arvore
*/

void aplly_fill_valor (int depth, TREEMinMax * tree, int max_jog);




/**
\brief Função que joga automaticamente segundo o algoritmo min_max
*/



COORDENADA joga_MinMax(ESTADO *e);

#endif //_GUIAO5_BOT_H
