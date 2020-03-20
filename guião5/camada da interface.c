/**
@file camada\ da\ interdace
Funções que controem a interface do jogo
*/


#include <stdio.h>
#include <string.h>
#include "camada de dados.h"
#include "logica do programa.h"
#include "camada da interface.h"
#define BUF_SIZE 1024



/**
\brief  Função que desenha o tabuleiro no estado atual
*/


void mostrar_tabuleiro(ESTADO *estado) {

  int i, j;
    
    for (i = 7; i >= 0; i--){
        putchar('\n');
        printf ("%d ",i + 1);
        
        for(j = 0; j < 8; j++){
            
            if (i == 7 && j == 7) putchar('2');
            else if(i == 0 && j == 0) putchar ('1');
            else {
                    switch (estado -> tab [i][j])
                    {
                    case VAZIO:
                        putchar('.');
                        break;
                    
                    case BRANCA:
                        putchar('*');
                        break;
                    
                    case PRETA:
                        putchar('#');
                    
                    
                    }
        }
        }
    }
    putchar('\n');
    printf("  abcdefgh");
    putchar ('\n');

prompt (estado);
}

/**
\brief  Função auxiliar da função gravar_estado
*/


void escreve_tabuleuiro(ESTADO *e,FILE *save){
    int i, j;

     for (i = 7; i >= 0; i--){
        fprintf(save,"\n");
        fprintf (save,"%d ",i + 1);
        
        for(j = 0; j < 8; j++){
            
            if (i == 7 && j == 7) fprintf(save,"1");
            else if(i == 0 && j == 0) fprintf(save,"2");
            else {    
                    switch (e -> tab [i][j])
                    {
                    case VAZIO:
                        fprintf(save,".");
                        break;
                    
                    case BRANCA:
                        fprintf(save,"*");
                        break;
                    
                    case PRETA:
                        fprintf(save,"#");
                    
                    }
        }
        }
    }
    fprintf(save,"\n");
    fprintf(save,"  abcdefgh");
    fprintf(save,"\n");




}


/**
\brief  Função auxiliar da função interpretador que escreve um estado em um ficheiro
*/

void gravar_estado (ESTADO *e, char filename[]){
    
    FILE *save;
    
    
    // abre o ficheiro
    save = fopen(filename,"w");
    
    // escreve no ficheiro o tabuleiro
    
   escreve_tabuleuiro(e,save);

    // fecha o arquivo
    fclose(save);
}
    

/**
\brief  Função que lê o estado de um ficheiro
*/

void ler_estado (char filename[]) {

    FILE *save;
    char str[12];
    
    save = fopen(filename,"r");

    if(save == NULL) {
        printf ("Save inexistente");
    }else{
        
        while(!feof(save)){
       
        if (fgets(str,20,save) != NULL) printf("%s",str);

    }
    }
}

/**
\brief  Função que tranforma comandos dos jogador em ações no estado do jogo
*/

int interpretador(ESTADO *e) {
        char linha[BUF_SIZE];
        char col[2], lin[2];
        char quit;
        char filename[BUF_SIZE];
        
        
        
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
    
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            jogar(e, coord);
            int j_atual = obter_jogador_atual (e);
            if (casa_vencedora (e,coord)) {printf("O vencedor é o PL%d\n",j_atual-1);e -> num_jogadas = 32;}
            else mostrar_tabuleiro(e);
            
            
        }
    
        if(strlen(linha) == 2 && sscanf(linha,"%[Q]", &quit) == 1){
            printf(" \n O jogo Terminou \n");
            e -> num_jogadas = 32;
            
        }

        if (sscanf(linha,"gr %s", filename) == 1) gravar_estado (e,filename);
    
    
        if (sscanf(linha, "ler %s", filename) == 1) ler_estado(filename);
    
    
    
    
    return 1;
}


/**
\brief  Função auxiliar da função void que tranforma um número na sua letra logicamente correspondente
*/

char letra (int x){
     char arr [8] = {'a','b','c','d','e','f','g','h'};
     return arr [x]; 
}


/**
\brief  Função que fornece informação sobre o estado do jogo aos jogadores
*/

void prompt (ESTADO *e){
    int n_jogadas = obter_numero_de_jogadas (e);
    int j_atual = obter_jogador_atual (e);
    COORDENADA a = obter_ultima_jogada (e);
    int x = a.coluna;
    char col = letra(x);
    int y = a.linha;
    putchar ('\n');
    printf ("#%d PL%d %c%d\n", n_jogadas, j_atual,col,y+1);

}
