#include "listas.h"

LISTA criar_lista(){

    LISTA vazia;
    vazia = malloc(sizeof(Nodo));
    
    return vazia;

}

LISTA insere_cabeca(LISTA L, void *v){


    LISTA nova;
    nova = malloc(sizeof(Nodo));
    nova -> valor = v;
    nova -> prox = L;

return nova;
}

void *devolve_cabeca(LISTA L){

    void *r ;
    r = L -> valor;

return r;
}


LISTA proximo(LISTA L){

    LISTA nova;
    nova = L -> prox;
    free(L);

return nova;
}

int lista_esta_vazia(LISTA L){

    if (L-> valor == NULL && L-> prox == NULL) return 1;
    else return 0;
}


