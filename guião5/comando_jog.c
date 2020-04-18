#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_de_dados.h"
#include "comando_jog.h"
#include "logica_do_programa.h"


Lista constroi (COORDENADA x, Lista l) {
    Lista r;
    r = malloc (sizeof (NODO));
    r->valor = x;
    r->prox = l;
    return r;
}

void jogada_possivel (ESTADO *e,COORDENADA c){
    Lista L;
    int c_ult = c.coluna;
    int l_ult = c.linha;
    CASA p = PRETA;
    COORDENADA x1 = {c_ult+1,l_ult};
    COORDENADA x2 = {c_ult-1,l_ult};
    COORDENADA y1 = {c_ult,l_ult+1};
    COORDENADA y2 = {c_ult,l_ult-1};
    COORDENADA z1 = {c_ult+1,l_ult+1};
    COORDENADA z2 = {c_ult+1,l_ult-1};
    COORDENADA z3 = {c_ult-1,l_ult+1};
    COORDENADA z4 = {c_ult-1,l_ult-1};
    COORDENADA ar [8] = {x1, x2, y1, y2, z1,z2,z3,z4};

    for (int i = 0; i<8; i++){
        if (casa_valida (ar[i]) && obter_estado_casa(e,ar [i]) == VAZIO)
            constroi (ar[i],L);
            
    }
}            





