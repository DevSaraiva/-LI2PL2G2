
/**
@file logica\ do\ programa.c
Módulo que contém toda a lógica do jogo
*/



#include <stdio.h>
#include "camada de dados.h"


/**
\brief Função que altera o estado do jogo através das coordenadas fornecidas
*/


int jogar (ESTADO *estado, COORDENADA c){
    
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int jog = estado -> jogador_atual;

        // Muda de jogador
        if ( jog == 1) jog = 2;
        else jog = 1;
        

        printf("jogar %d %d\n", c.coluna, c.linha);
        estado -> tab [c.coluna] [c.linha] = BRANCA;
        
        // Aumenta número de jogadas
        if (jog == 2) estado -> num_jogadas++;
        
       
        
        return 0;
  

}

