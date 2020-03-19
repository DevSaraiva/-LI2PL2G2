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

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (estado->tab[i][j]) printf("*");
            else if (j == 7 && i==0) printf("2");
            else if (j==0 && i==7) printf("1");
            else printf(".");
            for (int k = 0; k < 32 ; k++) {
                if ((estado->jogadas[k].jogador1.linha == i && estado->jogadas[i].jogador1.coluna == j) || (estado->jogadas[k].jogador2.linha == i && estado->jogadas[k].jogador2.coluna == j))
                    printf("#");
            }
        
        }
        printf("\n");
    }
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

char letra (int x){
     char arr [8] = {'a','b','c','d','e','f','g','h'};
     return arr [(x-1)]; 
}

void prompt (ESTADO *e){
    int n_jogadas =  e->num_jogadas;
    int j_atual = obter_jogador_atual (e);
    COORDENADA a = e -> ultima_jogada;
    int x = a.coluna;
    char col = letra(x);
    int y = a.linha;
    printf ("#%d PL%d %c%d\n", n_jogadas, j_atual,col,y);

}
