#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "camada de dados.h"



int verifica_jogada (ESTADO *estado, COORDENADA c){
    int c_ult = estado -> ultima_jogada.coluna;
    int l_ult = estado -> ultima_jogada.linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    
    if (abs(c_coluna - c_ult) <= 1 && abs (l_ult - c_linha) <= 1 && obter_estado_casa(estado,c)) return 1;
    else return 0;
}




int jogar(ESTADO *estado, COORDENADA c){
    if ((verifica_jogada (estado,c))){
        estado -> tab [c.coluna] [c.linha] = BRANCA;
        return 1;
    }
    else return 0;
}
