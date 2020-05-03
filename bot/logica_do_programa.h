/**
@file logica_do_programa.h
Definição das funções da componente lógica do jogo
*/




#ifndef _GUIAO5_LOGICA_DO_PROGRAMA_H
#define _GUIAO5_LOGICA_DO_PROGRAMA_H
#include "camada_de_dados.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>





/**
\brief  Função que verifica se a casa é valida para jogar
\return 1 se válida, 0 caso contrário
*/
int casa_valida (COORDENADA c);



/**
\brief Função que  verifica se a peca está presa
\return 1 se presa, 0 caso contrário
*/


int jogada_presa (ESTADO *e,COORDENADA c);



/**
\brief Função que verifica se o jogo acabou
\return 1 se o jogo acabou, 0 caso contrário
*/

int casa_vencedora (ESTADO *e,COORDENADA c);

/**
\brief Função que verifica se uma jogada é possivel
\return 1 se a jogada for possível, 0 caso contrário
*/

int jogada_e_valida (ESTADO *estado, COORDENADA c);

/**
\brief Função que altera o estado do jogo através das coordenadas fornecidas
*/

void jogar(ESTADO *estado, COORDENADA c);



#endif //_GUIAO5_LOGICA_DO_PROGRAMA_H
