
/**
@file logicadoprograma.c
Módulo que contém toda a lógica do jogo
*/



#include <stdio.h>
#include "camada de dados.h"


/**
\brief Função que altera o estado do jogo através das coordenadas fornecidas
*/

/**
\brief Função que verifica se uma jogada é possivel
*/

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


/**
\brief Função que se o jogo acabou
*/


int casa_vencedora (ESTADO *e,COORDENADA c){
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int jog = e -> jogador_atual;
    if ((jog == 1 && c_coluna == 1 && c_linha == 1) || (jog == 2 && c_coluna == 8 && c_linha == 8)) return 1;
    else return 0;
}

/**
\brief Função que altera o estado do jogo através das coordenadas fornecidas
*/

int jogar (ESTADO *estado, COORDENADA c){
    int c_ult = estado -> ultima_jogada.coluna;
    int l_ult = estado -> ultima_jogada.linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int j_atual = obter_jogador_atual (estado);
    printf("jogar %d %d\n", c.coluna, c.linha);

    if (valida_jogada(estado,c)==1){
        // Atualiza o tabuleiro

        estado -> tab [c.coluna -1] [c.linha-1] = BRANCA;
        estado -> tab [c_ult-1] [l_ult-1] = PRETA;

        // Muda de jogador e guarda a jogada
        
        if (j_atual == 1) estado -> jogador_atual = 2;
        else {
            estado -> jogador_atual = 1;
            COORDENADA j1 = {c_ult,l_ult};
            COORDENADA j2 = {c.coluna, c.linha};
            JOGADA j = {j1,j2};
            int i = 0;
            estado -> jogadas [i] = j;
            i++;
        }

        // Atualiza a última jogada
        estado -> ultima_jogada.coluna = c_ult;
        estado -> ultima_jogada.linha = l_ult;
        
    }    
    else printf("Jogada inválida\n");

    // Aumenta número de jogadas
    if (j_atual == 2) 
        estado -> num_jogadas++;

    if (casa_vencedora (estado,c) == 1) printf("O vecedor é o jogador %d", j_atual-1);
    
}
