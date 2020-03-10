//
// Created by sofia on 09/03/20.
//

#ifndef GUIÃO5_CAMADA_DE_DADOS_H
#define GUIÃO5_CAMADA_DE_DADOS_H
#include <string.h>
#define BUF_SIZE 1024
// Estruturas de dados (devem ser colocadas no módulo correto da camada dos dados)
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
JOGADAS jogadas;
int num_jogadas;
int jogador_atual;
} ESTADO;
#endif //GUIÃO5_CAMADA_DE_DADOS_H
