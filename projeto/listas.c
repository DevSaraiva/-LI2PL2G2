//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "listas.h"
//#include "camada_de_dados.h"


LISTA criar_lista(){

    LISTA vazia;
    vazia = malloc(sizeof(Nodo));
    vazia -> valor = malloc(sizeof(COORDENADA));
    return vazia;

}

LISTA insere_cabeca(LISTA L, void *v){

    LISTA nova;
    nova = criar_lista();
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

LISTA remove_cabeca(LISTA L){
    LISTA tmp = L;
    if (L != NULL) {
        L = L->prox;
        free (tmp);
    }
    return L;
}



int lista_esta_vazia(LISTA L){

    if (L-> valor == NULL && L-> prox == NULL) return 1;
    else return 0;
}



