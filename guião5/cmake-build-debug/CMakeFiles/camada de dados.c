//
// Created by sofia on 09/03/20.
//
#include <stdio.h>

typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;// Falta a resto da inicialização.
    return e;
}

int obter_jogador_atual(ESTADO *estado){}

int obter_numero_de_jogadas(ESTADO *estado){}

int obter_estado_casa(ESTADO *e, COORDENADA c){}

