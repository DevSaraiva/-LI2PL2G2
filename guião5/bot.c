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



void joga_euclidiana (ESTADO *e){
    
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
mostrar_tabuleiro(e);

}

void joga_aleatorio (ESTADO *e) {
	srand(time (NULL));
	//número aleatório entre 1 e 8 (oito casas envolventes á peça)
	int jogada = rand() % 8 + 1;
	COORDENADA c = obter_ultima_jogada(e);
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
    if (casa_valida (ar[jogada]) && obter_estado_casa(e,ar [jogada]) == VAZIO){
   		jogar(e,ar[jogada]);
   	} else joga_aleatorio (e); 
	mostrar_tabuleiro(e);
}



