#include <stdio.h>
#include "camada de dados.h"
int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
