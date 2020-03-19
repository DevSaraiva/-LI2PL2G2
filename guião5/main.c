#include <stdio.h>
#include <string.h>
#include "camada de dados.h"
#include "camada da interface.h"
#include "logica do programa.h"


// Função principal que aglomera todos os módulos

int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    prompt (e);
    
    int num_jog = 0;

    while (num_jog < 32){
    interpretador(e);
    num_jog = e -> num_jogadas;
    }
    return 0;
}
