#include <stdlib.h>
#include "camada de dados.h"

void limpa_tabuleiro (ESTADO *e){

    int i, j;
    for ( j = 0; j < 8; j++)
        for( i = 0; i < 8; i++){
            e -> tab[i][j] = VAZIO;
        }


    e -> tab[3][4] = BRANCA;
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

int obter_jogador_atual(ESTADO *estado){
    printf("%d",estado -> jogador_atual);
}



CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int* c = &c.coluna;
    int* l = &c.linha;
    Casa x = tab [c] [l]);
    switch (x){
        case VAZIO : printf("VAZIO\n");
            break;
        case PRETA : printf ("PRETA\n");
            break;
        default: printf ("BRANCA\n");
    }
}


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    limpa_tabuleiro(e);
    limpa_jogadas(e);
    return e;
}
