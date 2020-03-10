#include <stdio.h>
#include "camada de dados.h"

int jogar(ESTADO *estado, COORDENADA c){
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}
