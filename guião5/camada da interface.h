/**
@file camda\ da\ interface.h
Definição das funções relacionadas com interface
*/





#ifndef _GUIAO5_CAMADA_DA_INTERFACE_H
#define _GUIAO5_CAMADA_DA_INTERFACE_H
#include "camada de dados.h"
#include "logica do programa.h"
#include "camada da interface.h"


void mostrar_tabuleiro(ESTADO *estado);
int interpretador(ESTADO *e);
char letra (int x);
void prompt (ESTADO *e);
#endif //_GUIAO5_CAMADA_DA_INTERFACE_H
