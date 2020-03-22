
#include <stdio.h>
#include <stdlib.h>
#include "camada_de_dados.h"




void limpa_tabuleiro (ESTADO *e){

    int i, j;
    for ( j = 0; j < 8; j++)
        for( i = 0; i < 8; i++){
            e -> tab[i][j] = VAZIO;
        }


    e -> tab [4][4] = BRANCA;
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



COORDENADA obter_ultima_jogada(ESTADO *e){
    COORDENADA x = e -> ultima_jogada;
    return x;
}







int obter_jogador_atual(ESTADO *estado){
    int x = estado -> jogador_atual;
    return x;
}





CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int coluna = c.coluna;
    int linha = c.linha;
    CASA x = e -> tab[linha][coluna];
    return x;
}



int obter_numero_de_jogadas (ESTADO *e){
    int jog = e -> num_jogadas;
    return jog;
}

/**
\brief Função que limpa todas as variáveis do estado do jogo, tornando-o pronto para começar a jogar
*/


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    e -> ultima_jogada.linha = 4;
    e -> ultima_jogada.coluna = 4;
    limpa_tabuleiro(e);
    limpa_jogadas(e);
    return e;
}
