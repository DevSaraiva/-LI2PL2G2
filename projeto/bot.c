#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "camada_de_dados.h"
#include "bot.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"




LISTA jogada_possivel (ESTADO *e,COORDENADA c){

    LISTA l = criar_lista();
    COORDENADA *ap;
    ap = malloc(sizeof(COORDENADA));
    int c_ult = c.coluna;
    int l_ult = c.linha;
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
        ap = malloc(sizeof(COORDENADA));
        * ap = ar[i];
        if (casa_valida (ar[i]) && obter_estado_casa(e,ar [i]) == VAZIO){
            l = insere_cabeca(l,ap);} 
    }

return l;
}            



double calcula_dist(COORDENADA * c, int jog){
    
    COORDENADA game_over;
    if (jog == 1) { 
        game_over.coluna = 0;
        game_over.linha = 0;
    }else{
         game_over.coluna = 7;
         game_over.linha = 7;}
    int x1 = game_over.linha;
    int x2 = c ->linha;
    int y1 = game_over.coluna;
    int y2 = c ->coluna;
    int x = x1 - x2;
    int y = y1 - y2;
    double dist;

    dist = sqrt(pow(x,2)+pow(y,2));
    
return dist;
}





int atribui_valor (ESTADO *e, int jog_max, COORDENADA c){
    
    COORDENADA * coord;
    coord = malloc(sizeof(COORDENADA));
    coord = &c;
    int valor;
    int jog_min;
    if (jog_max == 1) jog_min = 2;
    else jog_min = 1;

    int jog_atual = obter_jogador_atual(e);

    if(jogada_presa(e,c)){
        if(jog_atual == jog_max) valor = -1000;
        else valor = 1000; 
    
    }else{
    
        int dist_fav = calcula_dist(coord, jog_max);
        int dis_desf = calcula_dist(coord,jog_min);
        valor = dis_desf - dist_fav;
        }

    
return valor;

}



TREEMinMax * create_tree(){

    TREEMinMax * tree = malloc(sizeof(TREEMinMax));
    tree -> e = malloc(sizeof(ESTADO));
    tree -> nodo1 = malloc(sizeof(TREEMinMax));
    tree -> nodo2 = malloc(sizeof(TREEMinMax));
    tree -> nodo3 = malloc(sizeof(TREEMinMax));
    tree -> nodo4 = malloc(sizeof(TREEMinMax));
    tree -> nodo5 = malloc(sizeof(TREEMinMax));
    tree -> nodo6 = malloc(sizeof(TREEMinMax));
    tree -> nodo7 = malloc(sizeof(TREEMinMax));
    tree -> nodo8 = malloc(sizeof(TREEMinMax));
    
return tree;

}

TREEMinMax * create_tree_vazia(){

    TREEMinMax * tree = malloc(sizeof(TREEMinMax));
    tree -> e = malloc(sizeof(ESTADO));
    tree -> nodo1 = NULL;
    tree -> nodo2 = NULL;
    tree -> nodo3 = NULL;
    tree -> nodo4 = NULL;
    tree -> nodo5 = NULL;
    tree -> nodo6 = NULL;
    tree -> nodo7 = NULL;
    tree -> nodo8 = NULL;

return tree;

}



TREEMinMax * create_tree_total (int depth, ESTADO * e, int jog_max, COORDENADA c){

        TREEMinMax * tree;
    if(depth == 0){
         
         tree = create_tree_vazia();
         tree -> e = e;
         tree -> coord = c;
         tree -> valor = atribui_valor(e,jog_max,c);
    
    }else{

    tree =  create_tree();
    tree -> e = e;
    tree -> coord = c;
    
    // coordenadas possiveis
    int c_ult = c.coluna;
    int l_ult = c.linha;
    COORDENADA c1 = {c_ult+1,l_ult};
    COORDENADA c2 = {c_ult-1,l_ult};
    COORDENADA c3 = {c_ult,l_ult+1};
    COORDENADA c4 = {c_ult,l_ult-1};
    COORDENADA c5 = {c_ult+1,l_ult+1};
    COORDENADA c6 = {c_ult+1,l_ult-1};
    COORDENADA c7 = {c_ult-1,l_ult+1};
    COORDENADA c8 = {c_ult-1,l_ult-1};
    
    ESTADO * copia1 = malloc(sizeof(ESTADO));
    *copia1 = *e;
    ESTADO * copia2 = malloc(sizeof(ESTADO));
    *copia2 = *e;
    ESTADO * copia3 = malloc(sizeof(ESTADO));
    *copia3 = *e;
    ESTADO * copia4 = malloc(sizeof(ESTADO));
    *copia4 = *e;
    ESTADO * copia5 = malloc(sizeof(ESTADO));
    *copia5 = *e;
    ESTADO * copia6 = malloc(sizeof(ESTADO));
    *copia6 = *e;
    ESTADO * copia7 = malloc(sizeof(ESTADO));
    *copia7 = *e;
    ESTADO * copia8 = malloc(sizeof(ESTADO));
    *copia8 = *e;
    
    

    if(jogada_e_valida(copia1,c1)){
    jogar(copia1,c1);
    *tree -> nodo1 = *create_tree_total(depth - 1, copia1, jog_max, c1);
    }else tree -> nodo1 = NULL;

    if(jogada_e_valida(copia2,c2)){
    jogar(copia2,c2);
    *tree -> nodo2 = *create_tree_total(depth - 1, copia2, jog_max, c2);
    }else tree -> nodo2 = NULL;

    if(jogada_e_valida(copia3,c3)){
    jogar(copia3,c3);
    *tree -> nodo3 = *create_tree_total(depth - 1, copia3, jog_max, c3);
    }else tree -> nodo3 = NULL;

    if(jogada_e_valida(copia4,c4)){
    jogar(copia4,c4);
    *tree -> nodo4 = *create_tree_total(depth - 1, copia4, jog_max, c4);
    }else tree -> nodo4 = NULL;

    if(jogada_e_valida(copia5,c5)){
    jogar(copia5,c5);
    *tree -> nodo5 = *create_tree_total(depth - 1, copia5, jog_max, c5);
    }else tree -> nodo5 = NULL;

    if(jogada_e_valida(copia6,c6)){
    jogar(copia6,c6);
    *tree -> nodo6 = *create_tree_total(depth - 1, copia6, jog_max, c6);
    }else tree -> nodo6 = NULL;

    if(jogada_e_valida(copia7,c7)){
    jogar(copia7,c7);
    *tree -> nodo7 = *create_tree_total(depth - 1, copia7, jog_max, c7);
    }else tree -> nodo7 = NULL;

    if(jogada_e_valida(copia8,c8)){
    jogar(copia8,c8);
    *tree -> nodo8 = *create_tree_total(depth - 1, copia8, jog_max, c8);
    }else tree -> nodo8 = NULL;

    
    }
    

return tree;
}

int is_tree_finished(TREEMinMax * tree){
    
    if (tree-> nodo1 == NULL && tree -> nodo2 == NULL && tree -> nodo3 == NULL && tree-> nodo4 == NULL && tree -> nodo5 == NULL && tree -> nodo6 == NULL
     && tree -> nodo7 == NULL && tree -> nodo8 == NULL) return 1;
    else return 0; 
}

int is_last_decision (TREEMinMax * tree){

    if(is_tree_finished(tree -> nodo1) && is_tree_finished(tree -> nodo2) && is_tree_finished(tree -> nodo3) && is_tree_finished(tree -> nodo4) &&
     is_tree_finished(tree -> nodo5) && is_tree_finished(tree -> nodo6) && is_tree_finished(tree -> nodo7) && is_tree_finished(tree -> nodo8)) return 1;
    else return 0;

}

COORDENADA devolve_coordenada (TREEMinMax * tree, int val){

    COORDENADA c;
    if( tree -> nodo1 != NULL && tree -> nodo1 -> valor == val) c = tree -> nodo1 -> coord;
    if( tree -> nodo2 != NULL && tree -> nodo2 -> valor == val) c = tree -> nodo2 -> coord;
    if( tree -> nodo3 != NULL && tree -> nodo3 -> valor == val) c = tree -> nodo3 -> coord;
    if( tree -> nodo4 != NULL && tree -> nodo4 -> valor == val) c = tree -> nodo4 -> coord;
    if( tree -> nodo5 != NULL && tree -> nodo5 -> valor == val) c = tree -> nodo5 -> coord;
    if( tree -> nodo6 != NULL && tree -> nodo6 -> valor == val) c = tree -> nodo6 -> coord;
    if( tree -> nodo7 != NULL && tree -> nodo7 -> valor == val) c = tree -> nodo7 -> coord;
    if( tree -> nodo8 != NULL && tree -> nodo8 -> valor == val) c = tree -> nodo8 -> coord;

return c;
}


int  max_nodo (TREEMinMax * tree){

   
    
    int vnodo1;
    int vnodo2;
    int vnodo3;
    int vnodo4;
    int vnodo5;
    int vnodo6;
    int vnodo7;
    int vnodo8;
    int max;
    
    if (tree-> nodo1 != NULL) vnodo1 = tree -> nodo1 -> valor;
    else vnodo1 = -1000;

    if (tree-> nodo2 != NULL) vnodo2 = tree -> nodo2 -> valor;
    else vnodo2 = -1000;

    if (tree-> nodo3 != NULL) vnodo3 = tree -> nodo3 -> valor;
    else vnodo3 = -1000;

    if (tree-> nodo4 != NULL) vnodo4 = tree -> nodo4 -> valor;
    else vnodo4 = -1000;

    if (tree-> nodo5 != NULL) vnodo5 = tree -> nodo5 -> valor;
    else vnodo5 = -1000;

    if (tree-> nodo6 != NULL) vnodo6 = tree -> nodo6 -> valor;
    else vnodo6 = -1000;

    if (tree-> nodo7 != NULL) vnodo7 = tree -> nodo7 -> valor;
    else vnodo7= -1000;

    if (tree-> nodo8 != NULL) vnodo8 = tree -> nodo8 -> valor;
    else vnodo8 = -1000;
    
    max = vnodo1;

    if (vnodo2 > max) max = vnodo2;
    if (vnodo3 > max) max = vnodo3;
    if (vnodo4 > max) max = vnodo4;
    if (vnodo5 > max) max = vnodo5;
    if (vnodo6 > max) max = vnodo6;
    if (vnodo7 > max) max = vnodo7;
    if (vnodo8 > max) max = vnodo8;
    
     //printf("\n MAX: %d\n",max);

return max;
}


int min_nodo (TREEMinMax * tree){

    
    int vnodo1;
    int vnodo2;
    int vnodo3;
    int vnodo4;
    int vnodo5;
    int vnodo6;
    int vnodo7;
    int vnodo8;
    int min;
    
    if (tree-> nodo1 != NULL) vnodo1 = tree -> nodo1 -> valor;
    else vnodo1 = 1000;

    if (tree-> nodo2 != NULL) vnodo2 = tree -> nodo2 -> valor;
    else vnodo2 = 1000;

    if (tree-> nodo3 != NULL) vnodo3 = tree -> nodo3 -> valor;
    else vnodo3 = 1000;

    if (tree-> nodo4 != NULL) vnodo4 = tree -> nodo4 -> valor;
    else vnodo4 = 1000;

    if (tree-> nodo5 != NULL) vnodo5 = tree -> nodo5 -> valor;
    else vnodo5 = 1000;

    if (tree-> nodo6 != NULL) vnodo6 = tree -> nodo6 -> valor;
    else vnodo6 = 1000;

    if (tree-> nodo7 != NULL) vnodo7 = tree -> nodo7 -> valor;
    else vnodo7= 1000;

    if (tree-> nodo8 != NULL) vnodo8 = tree -> nodo8 -> valor;
    else vnodo8 = 1000;
    
    min = vnodo1;

    if (vnodo2 < min) min = vnodo2;
    if (vnodo3 < min) min = vnodo3;
    if (vnodo4 < min) min = vnodo4;
    if (vnodo5 < min) min = vnodo5;
    if (vnodo6 < min) min = vnodo6;
    if (vnodo7 < min) min = vnodo7;
    if (vnodo8 < min) min = vnodo8;
    
    //printf("\nMIN: %d\n",min);

return min;
}



void fill_valor ( TREEMinMax * tree, int max_jog){

    int jog = obter_jogador_atual(tree -> e);
    int valor;
    
        if (jog == max_jog) valor = max_nodo(tree);
        else valor = min_nodo(tree);

        tree -> valor = valor;
        
        free(tree -> nodo1);
        tree -> nodo1 = NULL;
        free(tree -> nodo2);
        tree -> nodo2 = NULL;
        free(tree -> nodo3);
        tree -> nodo3 = NULL;
        free(tree -> nodo4);
        tree -> nodo4 = NULL;
        free(tree -> nodo5);
        tree -> nodo5 = NULL;
        free(tree -> nodo6);
        tree -> nodo6 = NULL;
        free(tree -> nodo7);
        tree -> nodo7 = NULL;
        free(tree -> nodo8);
        tree -> nodo8 = NULL;

         
}


void aplly_fill_valor (int depth, TREEMinMax * tree, int max_jog){

    
    if (depth == 1){
       
        
       fill_valor(tree, max_jog);
      
      
    } else {

        if(tree -> nodo1 != NULL) aplly_fill_valor(depth - 1, tree -> nodo1, max_jog);
        if(tree -> nodo2 != NULL) aplly_fill_valor(depth - 1, tree -> nodo2, max_jog);
        if(tree -> nodo3 != NULL) aplly_fill_valor(depth - 1, tree -> nodo3, max_jog);
        if(tree -> nodo4 != NULL) aplly_fill_valor(depth - 1, tree -> nodo4, max_jog);
        if(tree -> nodo5 != NULL) aplly_fill_valor(depth - 1, tree -> nodo5, max_jog);
        if(tree -> nodo6 != NULL) aplly_fill_valor(depth - 1, tree -> nodo6, max_jog);
        if(tree -> nodo7 != NULL) aplly_fill_valor(depth - 1, tree -> nodo7, max_jog);
        if(tree -> nodo8 != NULL) aplly_fill_valor(depth - 1, tree -> nodo8, max_jog);

    }
}



COORDENADA joga_MinMax(ESTADO *e){
    
    COORDENADA ultima_jog = obter_ultima_jogada(e);
    COORDENADA jogada;
    int max_jog = obter_jogador_atual(e);
    int valor;
    int depth = 5;
    int i ;
    TREEMinMax * tree = malloc(sizeof(TREEMinMax));
    tree = create_tree_total(depth , e, max_jog,ultima_jog);
    

    for(i = depth; i != 1; i--){
    
    
        aplly_fill_valor(depth, tree, max_jog);
    
    }
    
    valor = max_nodo(tree);
    jogada = devolve_coordenada(tree, valor);

    jogar(e,jogada);

return jogada;    
       
}



COORDENADA joga_euclidiana (ESTADO *e){
    
    LISTA l;
    l = malloc(sizeof(Nodo));
    COORDENADA c = obter_ultima_jogada(e);
    l = jogada_possivel(e,c);
    COORDENADA * best_play;
    COORDENADA * best_play_temp;
    best_play_temp = malloc(sizeof(COORDENADA));
    best_play = malloc(sizeof(COORDENADA));
    best_play = l -> valor;
    l = l -> prox;
    int jog = obter_jogador_atual(e);
    double dist = calcula_dist(best_play,jog);
    double dist_temp;

    while(l -> prox != NULL){
        
        best_play_temp = l -> valor;
        dist_temp = calcula_dist(best_play_temp,jog);

        if (dist_temp < dist){
            best_play = best_play_temp;
            dist = dist_temp;
        }

        l = l -> prox;
    }

    jogar(e,*best_play);

    return *best_play;
}

COORDENADA joga_aleatorio (ESTADO *e) {
	LISTA l;
	COORDENADA c = obter_ultima_jogada(e);
	//Obtem a lista com todas as jogadas possíveis
	l = jogada_possivel (e,c);
	//Guardar o apontador para a lista l
	LISTA temp = l;
	int count = 0;
	//Contar os elementos da lista
	while (l->prox != NULL){
	    l = l->prox;
	    count ++;
	}
	srand(time(NULL));
	//Gerar um número entre 0 e o comprimento da lista
    	int jogada = rand() % (count);
	int indice = 0;
	//Buscar o valor aleatória à lista
	while (indice < jogada){
	    temp = temp -> prox;
	    indice ++;
	}
	//Jogar a coordenada escolhida
	COORDENADA *coord = temp -> valor;
    	jogar(e,*coord);
    
    return *coord; 
}


int verifica_jogada_flood (ESTADO *e,COORDENADA  c){
    int r = 1;
    int c_ult = c.coluna;
    int l_ult = c.linha;
    COORDENADA x1 = {c_ult+1,l_ult};
    COORDENADA x2 = {c_ult-1,l_ult};
    COORDENADA y1 = {c_ult,l_ult+1};
    COORDENADA y2 = {c_ult,l_ult-1};
    COORDENADA z1 = {c_ult+1,l_ult+1};
    COORDENADA z2 = {c_ult+1,l_ult-1};
    COORDENADA z3 = {c_ult-1,l_ult+1};
    COORDENADA z4 = {c_ult-1,l_ult-1};
    COORDENADA ar [8] = {x1, x2, y1, y2, z1,z2,z3,z4};

    for (int i = 0; i < 8; i++){
        if (casa_valida (ar[i]) && obter_estado_casa(e,ar [i]) == VAZIO)
            r = 0;
    }
    return r;
}            



COORDENADA joga_flood (ESTADO *e){
    LISTA l;
	COORDENADA c = obter_ultima_jogada(e);
	l = jogada_possivel (e,c);
    COORDENADA * possivel_jogada;
    COORDENADA *prox_jogada;
    COORDENADA p;
    int r = 0;

    while (l ->prox != NULL){
        possivel_jogada = l -> valor;
    
        if (verifica_jogada_flood (e,*possivel_jogada)){
            prox_jogada = possivel_jogada;
            r = 1;
        }   
        l = l -> prox;
    }
    if (r == 0) {
        p = joga_euclidiana(e);
        return p;
    }
    else {
        jogar(e, *prox_jogada);
        return *prox_jogada;
    }
}
