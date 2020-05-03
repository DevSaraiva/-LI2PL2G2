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
#include "bot.h"




/**
\brief Função principal que aglomera todos os módulos
*/


int main (int argc, char *argv[]){
    if(argc != 3) printf("Não foi fornecido o número correto de ficheiros");
    ESTADO *e = inicializar_estado();
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    mostrar_tabuleiro(e);
    ler_estado(e,filename1);
    COORDENADA coord = joga_MinMax(e);
    if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é PL%d\n",j_atual);
    }
    gravar_estado (e,filename2);
    
    return 0;
}
