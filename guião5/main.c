#include <stdio.h>
#include "camada de dados.h"
#include "camada da interface.h"
#include "logica do programa.h"

int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro (e);
    return 0;
}
