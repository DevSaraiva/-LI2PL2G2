

/**
@file camada_de_dados.h
Definição do estado e das funções que o manipulam
*/






#ifndef _GUIAO5_CAMADA_DE_DADOS_H
#define _GUIAO5_CAMADA_DE_DADOS_H
#include <string.h>
#include <stdio.h>
#include "listas.h"
/**
\brief Tamanho do buffer
*/

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

/**
\brief Definição do tipo JOGADa como sendo um array de 32 jogadas
*/

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
    int ultimo_comando_pos;
    int valor_pos;
} ESTADO;

/**
\brief  função que inicializa um estado
\return O ponteiro para o estado
*/
ESTADO* inicializar_estado();

/**
\brief Função que coloca todas as casas do tabuleiro como vazias exepto a casa inicial
*/

void limpa_tabuleiro (ESTADO *e);

/**
\brief Função que atribui jogadas inválidas a todas as jogadas não efetuadas presentes na lista de jogadas
*/


void limpa_jogadas (ESTADO *e);

/**
\brief Função que retorna a ultima jogada efetuada
\return A última coordenada jogada
*/

COORDENADA obter_ultima_jogada(ESTADO *e);

/**
\brief Função que define a ultima jogada efetuada
*/

void set_ultima_jogada(ESTADO *e,COORDENADA x);

/**
\brief Função que devolve número de jogadas efetuadas até o momento
\return Número de jogadas efetuadas
*/

int obter_numero_de_jogadas (ESTADO *e);


/**
\brief Função que define número de jogadas efetuadas até o momento
*/

void set_numero_de_jogadas (ESTADO *e,int x);

/**
\brief Função que retorna o jogador que possui a vez de jogar
\return Número do jogador atual (1 ou 2)
*/

int obter_jogador_atual(ESTADO *estado);

/**
\brief Função que define o jogador que possui a vez de jogar
*/
void set_jogador_atual(ESTADO *e,int x);

/**
\brief Função que obtém o estado de determinada casa localizada na coordenada passada
\return O estado da casa
*/

CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Função que define o estado de determinada casa localizada na coordenada passada
*/
void set_estado_casa_c(ESTADO *e,COORDENADA c,CASA x);


/**
\brief Função que define determinada jogada da lista de jogadas do estado
*/


void set_jogada_indice(ESTADO *e,JOGADA x,int i);


/**
\brief Função que retorna uma jogada de determinada posição na lista de jogadas
\return A jogada selecionada
*/

JOGADA retorna_Jogada (ESTADO *e, int x);

/**
\brief  Obtem as jogadas de um dado jogador
\return Coordenada da jogada de um determinado jogador
*/
COORDENADA obter_jogada_por_j (ESTADO *e,int i,int x);
/**
\brief  Função que diz se o comando pos está ativo
\return O último comando pos usado
*/
int obter_comando_pos (ESTADO *e);
/**
\brief  Função que diz qual o valor do comando pos
\return O valor do último comando pos usado
*/
int obter_valor_pos (ESTADO *e);
/**
\brief  Função define um comando pos
*/
void set_comando_pos (ESTADO *e,int x);
/**
\brief  Função define o valor do comando pos
*/
void set_valor_pos (ESTADO *e,int x);
/**
\brief  Define o estado da casa
*/
void set_estado_casa(ESTADO *e,int linha,int coluna,CASA x);
/**
\brief  Define uma jogada daso um índice
*/
void set_jogada(ESTADO *e,int i,int x);
#endif //_GUIAO5_CAMADA_DE_DADOS_H
