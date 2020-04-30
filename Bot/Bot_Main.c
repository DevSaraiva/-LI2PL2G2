#include <stdio.h>
#include <stdlib.h>
#include "camada_de_dados.h"
#include "camada_da_interface.h"
#include "logica_do_programa.h"
#include "listas.h"
#include "bot.h"

int main(int argc,char *argv[]){
	ESTADO *e;
	if (argc < 2){
		printf("Não foram fornecidos dois ficheiros válidos\n");
		exit(1);
	}
	ler_estado (e,argv[1]);
	joga_euclidiana(e);
	gravar_estado (e,argv[2]);
	return 0;
}
