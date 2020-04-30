/**
@file camada_da_interface.h
Definição das funções relacionadas com interface
*/





#ifndef _GUIAO5_CAMADA_DA_INTERFACE_H
#define _GUIAO5_CAMADA_DA_INTERFACE_H

#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "listas.h"
#include "bot.h"



/**
\brief  Função auxiliar da função gravar_estado
*/

void escreve_tabuleuiro(ESTADO *e,FILE *save);

/**
 \brief Função auxiliar da função gravar estado
 */

void escreve_movimentos(ESTADO* e,FILE *save);

/**
\brief  Função auxiliar da função interpretador que escreve um estado em um ficheiro
*/

void gravar_estado (ESTADO *e, char filename[]);

/**
\brief  Função que lê o estado de um ficheiro
*/

void ler_estado (ESTADO *e,char filename[]);


#endif //_GUIAO5_CAMADA_DA_INTERFACE_H
