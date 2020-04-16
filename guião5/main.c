/**
@file main.c
Aglomeração de todas as camadas
*/



#include <stdio.h>
#include <string.h>
#include "camada_de_dados.h"
#include "camada_da_interface.h"
#include "logica_do_programa.h"




/**
\brief Função principal que aglomera todos os módulos
*/


int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
   
    
    int num_jog = 0;

    while (num_jog <= 31){
    interpretador(e);
    num_jog = e -> num_jogadas;
    }

    return 0;
}
