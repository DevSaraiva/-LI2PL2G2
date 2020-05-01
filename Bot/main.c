/**
@file main.c
Aglomeração de todas as camadas
*/



#include <stdio.h>
#include <string.h>
#include "camada_de_dados.h"
#include "camada_da_interface.h"
#include "logica_do_programa.h"
#include "listas.h"





/**
\brief Função principal que aglomera todos os módulos
*/


int main(int argc, char *argv[]){
    ESTADO* e = inicializar_estado();
    ler_estado(e,argv[1]);
    joga_aleatorio(e);
    gravar_estado(e,argv[2]);
    return 0;
}
