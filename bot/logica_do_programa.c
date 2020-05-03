#include "logica_do_programa.h"

int casa_valida (COORDENADA c){
    int coluna = c.coluna;
    int linha = c.linha;
    if ((linha >= 0)&& (linha < 8) && (coluna >= 0) &&(coluna <8))
    return 1;
    else return 0;   
    
}

int jogada_presa (ESTADO *e,COORDENADA c){
    int r = 0;
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
        if (casa_valida (ar[i]) && obter_estado_casa(e,ar [i]) == VAZIO)
            return r;
    }
    int j_atual = obter_jogador_atual (e);
    if ((j_atual == 1)){
        if((c_ult == 7) && (l_ult == 7)) r = 1;
        else {
            set_jogador_atual (e,2);
            r = 1;
        }
    }
    else {
        if ((c_ult == 0) && (l_ult == 0)) r = 1;
        else {
            set_jogador_atual(e,1);
            r = 1;}
    }
    return r;
}



int casa_vencedora (ESTADO *e,COORDENADA c){
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int pl= obter_jogador_atual(e);
    if ((pl == 1 && c_coluna == 0 && c_linha == 0) || (pl==2 && c_coluna == 7 && c_linha == 7)) return 1;
    else return 0;
}




int jogada_e_valida (ESTADO *estado,COORDENADA c){
    
    if(c.linha > 7 || c.linha < 0 || c.coluna > 7 || c.coluna < 0) return 0;
    int c_ult = obter_ultima_jogada(estado).coluna;
    int l_ult = obter_ultima_jogada(estado).linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    CASA x = VAZIO;
    int dif_coluna = abs(c_coluna - c_ult);
    int dif_linha = abs(l_ult - c_linha);
    int r = 0;
    if (dif_coluna <= 1 &&  dif_linha <= 1 && ((obter_estado_casa(estado,c)) == x)) r=1;
    return r;
}




void jogar (ESTADO *estado, COORDENADA c){
    COORDENADA c_ult = obter_ultima_jogada(estado);
    int j_atual = obter_jogador_atual (estado);
    
    //printf("jogar %d %d\n", c.coluna, c.linha);
   
    if (jogada_e_valida(estado,c)){
        
        // Atualiza o tabuleiro
        set_estado_casa_c(estado,c,BRANCA);
        set_estado_casa_c(estado,c_ult,PRETA);
        
        // Muda de jogador e guarda a jogadas
        if ((j_atual == 1)){
            set_jogador_atual(estado,2);
            int n_js = obter_numero_de_jogadas(estado);
            set_jogada_jog(estado,n_js,1,c);
        }
        if ((j_atual == 2)) {
            set_jogador_atual(estado,1);
            int n_joga = obter_numero_de_jogadas(estado);
            set_jogada_jog(estado,n_joga,2,c);
        }

        // Atualiza a última jogada
        set_ultima_jogada (estado,c);
        
        // Aumenta número de jogadas
        if (j_atual == 2){
        int n_js = obter_numero_de_jogadas(estado); 
        set_numero_de_jogadas (estado,n_js +1);
        }
    }    
    else printf("Jogada inválida\n");
    
}
