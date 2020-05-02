#include "camada_de_dados.h"


void limpa_tabuleiro (ESTADO *e){

    int i, j;
    for ( j = 0; j < 8; j++)
        for( i = 0; i < 8; i++){
            e -> tab[i][j] = VAZIO;
        }


    e -> tab [4][4] = BRANCA;
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



COORDENADA obter_ultima_jogada(ESTADO *e){
    COORDENADA x = e -> ultima_jogada;
    return x;
}

void set_ultima_jogada(ESTADO *e,COORDENADA x){
    e -> ultima_jogada = x;
}


int obter_jogador_atual(ESTADO *estado){
    int x = estado -> jogador_atual;
    return x;
}

void set_jogador_atual(ESTADO *e, int x){
    e -> jogador_atual = x;
}


CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int coluna = c.coluna;
    int linha = c.linha;
    CASA x = e -> tab[linha][coluna];
    return x;
}

void set_estado_casa_c(ESTADO *e,COORDENADA c,CASA x){
    int coluna = c.coluna;
    int linha = c.linha;
    e -> tab[linha][coluna] = x;
}

void set_estado_casa(ESTADO *e,int linha,int coluna,CASA x){
    e -> tab[linha][coluna] = x;
}


int obter_numero_de_jogadas (ESTADO *e){
    int jog = e -> num_jogadas;
    return jog;
}

void set_numero_de_jogadas (ESTADO *e,int x){
    e->num_jogadas = x;
}

void set_jogada_indice(ESTADO *e,JOGADA x,int i){
    e->jogadas[i] = x;
}


JOGADA retorna_Jogada (ESTADO *e, int x){
    JOGADA jog = e -> jogadas[x];
    return jog;

}

COORDENADA obter_jogada_por_jog (ESTADO *e,int i,int x){
    if (x == 1){
        int ncoluna1 = e->jogadas[i].jogador1.coluna;
        int nlinha1 = e->jogadas[i].jogador1.linha;
        COORDENADA j1 = {ncoluna1,nlinha1};
        return j1;
    }else{
        int ncoluna = e->jogadas[i].jogador2.coluna;
        int nlinha = e->jogadas[i].jogador2.linha;
        COORDENADA j2 = {ncoluna,nlinha};
        return j2;
    }

}

int obter_comando_pos (ESTADO *e){
    int x =  e -> ultimo_comando_pos;
    return x;
}

void set_comando_pos (ESTADO *e,int x){
    e->ultimo_comando_pos = x;
}


int obter_valor_pos (ESTADO *e) {
    int x = e->valor_pos;
    return x;
}
void set_valor_pos (ESTADO *e,int x){
    e->valor_pos=x;
}

void set_jogada(ESTADO *e,int i,int x){
    e->jogadas[i].jogador1.coluna = x;
    e->jogadas[i].jogador1.linha = x;
    e->jogadas[i].jogador2.coluna = x;
    e->jogadas[i].jogador2.linha = x;
}

void set_jogada_jog(ESTADO *e,int ind,int jog,COORDENADA c){
    if (jog == 1) e->jogadas[ind].jogador1 = c;
    else e->jogadas[ind].jogador2 = c;
}

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    e -> ultima_jogada.linha = 4;
    e -> ultima_jogada.coluna = 4;
    limpa_tabuleiro(e);
    limpa_jogadas(e);
    e -> ultimo_comando_pos = 0;
    e -> valor_pos = 0;
    return e;
}