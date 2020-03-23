

#include <stdio.h>
#include "camada_de_dados.h"
#include <math.h>
#include <stdlib.h>


int casa_vencedora (ESTADO *e,COORDENADA c){
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int jog = obter_jogador_atual(e);
    if ((c_coluna == 0 && c_linha == 0) || (c_coluna == 7 && c_linha == 7)) return 1;
    else return 0;
}




int jogada_e_valida (ESTADO *estado,COORDENADA c){
    int c_ult = obter_ultima_jogada(estado).coluna;
    int l_ult = obter_ultima_jogada(estado).linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    CASA x = VAZIO;
    int dif_coluna = abs(c_coluna - c_ult);
    int dif_linha = abs(l_ult - c_linha);
    if (dif_coluna <= 1 &&  dif_linha <= 1 && ((obter_estado_casa(estado,c)) == x)) 
        return 1;
    else return 0;
}




int jogar (ESTADO *estado, COORDENADA c){
    int c_ult = obter_ultima_jogada(estado).coluna;
    int l_ult = obter_ultima_jogada(estado).linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int j_atual = obter_jogador_atual (estado);
    printf("jogar %d %d\n", c.coluna, c.linha);
   
    if (jogada_e_valida(estado,c)){
        // Atualiza o tabuleiro
        
        estado -> tab [c.linha] [c.coluna] = BRANCA;
        estado -> tab [l_ult] [c_ult] = PRETA;
        
        // Muda de jogador e guarda a jogadass
        
        if ((j_atual == 1) && c_coluna != 0 && c_linha != 0) estado -> jogador_atual = 2;
        if ((j_atual == 2) && c_coluna != 7 && c_linha != 7) {
            estado -> jogador_atual = 1;
            COORDENADA j1 = {c_ult,l_ult};
            COORDENADA j2 = {c.coluna, c.linha};
            JOGADA j = {j1,j2};
            int i = 0;
            estado -> jogadas [i] = j;
            i++;
        }

        // Atualiza a última jogada
        estado -> ultima_jogada.coluna = c.coluna;
        estado -> ultima_jogada.linha = c.linha;
        
    }    
    else printf("Jogada inválida %d %d %d %d\n",c.linha,c.coluna,l_ult,c_ult);
 
    // Aumenta número de jogadas
    if (j_atual == 2) 
        estado -> num_jogadas++;

   
    
}


