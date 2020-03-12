#include <stdio.h>
#include "camada de dados.h"
#include <math.h>


int verifica_jogada (ESTADO *estado, COORDENADA c){
    int c_ult = estado -> ultima_jogada.coluna;
    int l_ult = estado -> ultima_jogada.linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    if (((sqrt ((c_ult - c_coluna)^2 + (l_ult - c_linha)^2)) == 1) && (obter_estado_casa(estado, c) == 'VAZIO')) return 1;
    else return 0;
}




int jogar(ESTADO *estado, COORDENADA c){
    if ((verifica_jogada (estado,c)) == 1){
        estado -> tab [c.coluna] [c.linha] = BRANCA;
        return 1;
    }
    else return 0;
}
