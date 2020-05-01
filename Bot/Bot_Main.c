#include <stdio.h>
#include <stdlib.h>
#include "camada_de_dados.h"
#include "camada_da_interface.h"
#include "logica_do_programa.h"
#include "listas.h"
#include "bot.h"

int main(int argc,char *argv[]){
	ESTADO *e = inicializar_estado();
	if (argc <= 2){
		printf("Não foram fornecidos dois ficheiros válidos\n");
		exit(1);
	}
	char *fich1 = argv[1];
	printf ("fich1\n");
	char *fich2 = argv[2];
	printf ("fich2\n");
	ler_estado (e,fich1);
	printf("Lido com sucesso\n");
	COORDENADA coord = obter_ultima_jogada(e);
	if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;
        }else {
	joga_euclidiana(e);
	printf("jogado com sucesso\n");
	gravar_estado (e,fich2);
	printf("gravado com sucesso\n");
	}
	return 0;
}
