//
// Created by saraiva on 10/03/20.
//


#include <stdlib.h>
#include "camada de dados.h"

void limpa_tabuleiro (ESTADO *e){

    int i, j;
    for ( j = 0; j < 8; j++)
        for( i = 0; i < 8; i++){
            e -> tab[i][j] = VAZIO;
        }


    e -> tab[3][4] = BRANCA;
}

void limpa_jogadas (ESTADO *e){
    int i;
    for (i = 0; i < 32; i++){
        e -> jogadas[i].jogador1.coluna = -1;
        e -> jogadas[i].jogador1.linha = -1;
        e -> jogadas[i].jogador2.coluna = -1;
        e -> jogadas[i].jogador2.linha = -1;
    }
}


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    limpa_tabuleiro(e);
    limpa_jogadas(e);
    e -> ultima_jogada.linha = 0;
    e -> ultima_jogada.coluna = 0;
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;

    return e;
}