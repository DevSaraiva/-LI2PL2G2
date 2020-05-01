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
    ESTADO *e = inicializar_estado();
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    mostrar_tabuleiro(e);
    ler_estado(e,filename1);
    COORDENADA coord = joga_euclidiana(e);
    if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;}
    gravar_estado (e,filename2);



    return 0;
}
