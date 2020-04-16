/**
@file camada_da_interface.h
Definição das funções relacionadas com interface
*/





#ifndef _GUIAO5_CAMADA_DA_INTERFACE_H
#define _GUIAO5_CAMADA_DA_INTERFACE_H
#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "listas.h"







/**
\brief  Função que desenha o tabuleiro no estado atual
*/

void mostrar_tabuleiro(ESTADO *estado);

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

void imprime_movimentos(ESTADO* e);

/**
\brief  Função auxiliar da função interpretador que escreve um estado em um ficheiro
*/

void gravar_estado (ESTADO *e, char filename[]);

/**
\brief  Função que lê o estado de um ficheiro
*/

void ler_estado (ESTADO *e,char filename[]);

/**
\brief  Função que tranforma comandos dos jogador em ações no estado do jogo
*/

int interpretador(ESTADO *e);

/**
\brief  Função auxiliar da função void que tranforma um número na sua letra logicamente correspondente
*/

char letra (int x);

/**
\brief  Função que fornece informação sobre o estado do jogo aos jogadores
*/

void prompt (ESTADO *e);

/**
\brief  Função que executa o comando pos
*/

ESTADO escreve_pos (ESTADO *e,int n);

/**
\brief  Função que apaga a ultima jogada
*/
void apaga_ultima_jogada (ESTADO *e);


#endif //_GUIAO5_CAMADA_DA_INTERFACE_H
