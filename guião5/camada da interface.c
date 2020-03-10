//
// Created by sofia on 09/03/20.
//

#include <stdio.h>
#include "camada de dados.h"
void mostrar_tabuleiro(ESTADO estado) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (estado.COORDENADA.coluna == j && estado.COORDENADA.linha == i) printf("*");
            else if (j == 7 && i==0) printf("2");
            else if (j==0 && i==7) printf("1"):
            for (int k = 0; k < 32 ; k++) {
                if ((estado.JOGADAS[k].jogador1.linha == i && estado.JOGADAS[i].jogador1.coluna == j) || (estado.JOGADAS[k].jogador2.linha == i && estado.JOGADAS[k].jogador2.coluna == j))
                    printf("#");
                else printf(".");
            }
        }
        printf("\n");
    }
}




int interpretador(ESTADO *e) {
        char linha[BUF_SIZE];
        char col[2], lin[2];

        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col -'a', *lin -'1'};
            jogar(e, coord);
            mostrar_tabuleiro(e);
        }
    return 1;
}
