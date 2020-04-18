/**
@file listas.h
Definição das funções relacionadas com listas ligadas
*/



#ifndef _GUIAO5_COMANDO_JOG_H
#define _GUIAO5_COMANDO_JOG_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_de_dados.h"
#include "logica_do_programa.h"


typedef struct list{
    COORDENADA valor;
    struct list *prox;
}NODO, *Lista;

Lista constroi (COORDENADA x, Lista l);


void jogada_possivel (ESTADO *e,COORDENADA c);




#endif //_GUIAO5_COMANDO_JOG_H