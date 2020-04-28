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

    int jog_min;
    if (jog_max == 1) jog_min = 2;
    else jog_min = 1;

    int jogador_atual = obter_jogador_atual(e);
    









}




TREEMinMax create_tree (int depth, ESTADO *e, COORDENADA c){

    TREEMinMax tree;
    tree.coord = c;
    
    //Coordenadas possiveis onde é possivel jogar dado determinada coordenada e respetivas copias do estado para que seja possivel analisar a situação do jogo
    
    //CODIGO A MELHORAR
    COORDENADA c1;
    c1.linha = c.linha - 1;
    c1.coluna = c.coluna + 1 ;
    ESTADO * copia1;
    copia1 = malloc(sizeof(ESTADO));
    copia1 = e;
    jogar(copia1,c1);   
    
    COORDENADA c2;
    c2.linha = c.linha ;
    c2.coluna = c.coluna + 1;
    ESTADO * copia2;
    copia2 = malloc(sizeof(ESTADO));
    copia2 = e;
    jogar(copia2,c2);  
    
    COORDENADA c3;
    c3.linha = c.linha + 1;
    c3.coluna = c.coluna + 1;
    ESTADO * copia3;
    copia3 = malloc(sizeof(ESTADO));
    copia3 = e;
    jogar(copia3,c3);  
    
    COORDENADA c4;
    c4.linha = c.linha + 1;
    c4.coluna = c.coluna;
    ESTADO * copia4;
    copia4 = malloc(sizeof(ESTADO));
    copia4 = e;
    jogar(copia4,c4);  
    
    COORDENADA c5;
    c5.linha = c.linha + 1;
    c5.coluna = c.coluna - 1;
    ESTADO * copia5;
    copia5 = malloc(sizeof(ESTADO));
    copia5 = e;
    jogar(copia5,c);  
    
    COORDENADA c6;
    c6.linha = c.linha;
    c6.coluna = c.coluna - 1;
    ESTADO * copia6;
    copia6 = malloc(sizeof(ESTADO));
    copia6 = e;
    jogar(copia6,c6);  
    
    COORDENADA c7;
    c7.linha = c.linha - 1;
    c7.coluna = c.coluna - 1;
    ESTADO * copia7;
    copia7 = malloc(sizeof(ESTADO));
    copia7 = e;
    jogar(copia7,c7);  
    
    COORDENADA c8;
    c8.linha = c.linha - 1;
    c8.coluna = c.coluna;
    ESTADO * copia8;
    copia8 = malloc(sizeof(ESTADO));
    copia8 = e;
    jogar(copia8,c8);  
    
    
    
    if (depth != 0){
    if (jogada_e_valida(e,c1)){
    tree.nodo1 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia1, c1);}
    
    if (jogada_e_valida(e,c2)){
    tree.nodo2 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia2, c2);}
    
    if (jogada_e_valida(e,c3)){
    tree.nodo3 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia3, c3);}
    
    if (jogada_e_valida(e,c4)){
    tree.nodo4 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia4, c4);}
    
    if (jogada_e_valida(e,c5)){
    tree.nodo5 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia5, c5);}
    
    if (jogada_e_valida(e,c6)){
    tree.nodo6 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia6, c6);}
    
    if (jogada_e_valida(e,c7)){
    tree.nodo7 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia7, c7);}
    
    if (jogada_e_valida(e,c8)){
    tree.nodo8 = malloc(sizeof(TREEMinMax));
    create_tree(depth - 1, copia8, c8);}
    
    }else{
        tree.valor = 1;
    }



return tree;
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
