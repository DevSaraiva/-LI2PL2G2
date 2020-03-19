/**
@file camada\ da\ interdace
Funções que controem a interface do jogo
*/


#include <stdio.h>
#include <string.h>
#include "camada de dados.h"
#include "logica do programa.h"
#include "camada da interface.h"
#define BUF_SIZE 1024

/**
\brief  Função que desenha o tabuleiro no estado atual
*/


void mostrar_tabuleiro(ESTADO *estado) {

  int i, j;
    
    
    
    
    for (i = 7; i >= 0; i--){
        putchar('\n');
        printf ("%d ",i + 1);
        
        for(j = 0; j < 8; j++){
            switch (estado -> tab [i][j])
            {
            case VAZIO:
                putchar('.');
                break;
            
            case BRANCA:
                putchar('*');
                break;
            
            case PRETA:
                putchar('#');
            
            
            }
        }
    }
    putchar('\n');
    printf("  abcdefgh");
    putchar ('\n');


}

/**
\brief  Função que tranforma comandos dos jogador em ações no estado do jogo
*/


int interpretador(ESTADO *e) {
        char linha[BUF_SIZE];
        char col[2], lin[2];
        
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
    
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            jogar(e, coord);
            mostrar_tabuleiro(e);
        }
    return 1;
}


/**
\brief  Função auxiliar da função void que tranforma um número na sua letra logicamente correspondente
*/

char letra (int x){
     char arr [8] = {'a','b','c','d','e','f','g','h'};
     return arr [(x-1)]; 
}


/**
\brief  Função que fornece informação sobre o estado do jogo aos jogadores
*/

void prompt (ESTADO *e){
    int n_jogadas =  e->num_jogadas;
    int j_atual = obter_jogador_atual (e);
    COORDENADA a = e -> ultima_jogada;
    int x = a.coluna;
    char col = letra(x);
    int y = a.linha;
    putchar ('\n');
    printf ("#%d PL%d %c%d\n", n_jogadas, j_atual,col,y);

}
