

/**
@file camada\ de\ dados.h
Definição do estado e das funções que o manipulam
*/






#ifndef _GUIAO5_CAMADA_DE_DADOS_H
#define _GUIAO5_CAMADA_DE_DADOS_H
#include <string.h>
#include <stdio.h>
#define BUF_SIZE 1024


/**
\brief Definção de coordenada
*/

typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
 
 /**
\brief Definição da jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

/**
\brief Definição do estado
*/
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO* inicializar_estado();
void limpa_tabuleiro (ESTADO *e);
void limpa_jogadas (ESTADO *e);
int obter_jogador_atual(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

#endif //_GUIAO5_CAMADA_DE_DADOS_H
