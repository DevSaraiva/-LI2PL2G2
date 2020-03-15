#include <stdio.h>
#include "camada de dados.h"


int valida_jogada (ESTADO *estado,COORDENADA c){
    int c_ult = estado -> ultima_jogada.coluna;
    int l_ult = estado -> ultima_jogada.linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    CASA x = VAZIO;
    if (((c_coluna - c_ult)*(c_coluna - c_ult) <= 1) && ((l_ult - c_linha)*(l_ult - c_linha) <= 1) && (obter_estado_casa(estado,c)) == x)
        return 1;
    else return 0;
}



int jogar (ESTADO *estado, COORDENADA c){
    if (valida_jogada(estado,c) == 1){
        printf("jogar %d %d\n", c.coluna, c.linha);
        estado -> tab [c.coluna] [c.linha] = BRANCA;
        return 1;
  } 
    else return 0;
}

