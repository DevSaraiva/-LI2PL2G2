/**
@file camadadedados.c
Definição das funções que manipulam o estado
*/


#include <stdio.h>
#include <stdlib.h>
#include "camada de dados.h"


/**
\brief Função que coloca todas as casas do tabuleiro como vazias exepto a casa inicial
*/

void limpa_tabuleiro (ESTADO *e){

    int i, j;
    for ( j = 0; j < 8; j++)
        for( i = 0; i < 8; i++){
            e -> tab[i][j] = VAZIO;
        }


    e -> tab[4][4] = BRANCA;
}

/**
\brief Função que atribui jogadas inválidas a todas as jogadas não efetuadas presentes na lista de jogadas
*/


void limpa_jogadas (ESTADO *e){
    int i;
    for (i = 0; i < 32; i++){
        e -> jogadas[i].jogador1.coluna = -1;
        e -> jogadas[i].jogador1.linha = -1;
        e -> jogadas[i].jogador2.coluna = -1;
        e -> jogadas[i].jogador2.linha = -1;
    }
}

/**
\brief Função que retorna o jogador que possui a vez de jogar
*/


int obter_jogador_atual(ESTADO *estado){
    int x = estado -> jogador_atual;
    return x;
}


/**
\brief Função que obtém o estado de determinada casa localizada na coordenada passada
*/


CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int coluna = c.coluna - 1;
    int linha = c.linha - 1;
    CASA x = e -> tab[coluna][linha];
    return x;
}

/**
\brief Função que devolve número de jogadas efetuadas até o momento
*/


int obter_numero_de_jogadas (ESTADO e){
    int jog = e.num_jogadas;
    return jog;
}

/**
\brief Função que limpa todas as variáveis do estado do jogo, tornando-o pronto para começar a jogar
*/


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    e -> ultima_jogada.linha = 5;
    e -> ultima_jogada.coluna = 4;
    limpa_tabuleiro(e);
    limpa_jogadas(e);
    return e;
}
