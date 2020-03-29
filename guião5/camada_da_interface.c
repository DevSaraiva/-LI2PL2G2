
#include <stdio.h>
#include <string.h>
#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"
#define BUF_SIZE 1024





void mostrar_tabuleiro(ESTADO *estado) {

  int i, j;
    
    for (i = 7; i >= 0; i--){
        putchar('\n');
        printf ("%d ",i + 1);
        
        for(j = 0; j < 8; j++){
            
            if (i == 7 && j == 7) putchar('2');
            else if(i == 0 && j == 0) printf ("1 ");
            else {
                    switch (estado -> tab [i][j])
                    {
                    case VAZIO:
                        printf(". ");
                        break;
                    
                    case BRANCA:
                        printf("* ");
                        break;
                    
                    case PRETA:
                        printf("# ");
                    
                    
                    }
        }
        }
    }
    putchar('\n');
    printf("  a b c d e f g h");
    putchar ('\n');

    prompt (estado);
}




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
    fprintf(save,"\n\n");

}

void escreve_movimentos(ESTADO *e, FILE *save){
    int temp = 0;
    //Percorre a lista de movimentos e imprime-a no terminal
    for (int i = 0; i < 32; i++) {
        if (e->jogadas[i].jogador1.coluna!=-1 && e->jogadas[i].jogador1.linha!=-1){
            fprintf(save,"%d : %c%d",i+1,letra(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha+1);
        }

        if (e->jogadas[i].jogador2.coluna!=-1 && e->jogadas[i].jogador2.linha!=-1){
            fprintf(save," %c%d \n",letra(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha+1);
            temp++;
        }
    }

    if ((obter_jogador_atual(e)==2)) fprintf(save,"%d : %c%d",e->num_jogadas+1,letra(e->ultima_jogada.coluna),e->ultima_jogada.linha+1);
}



void gravar_estado (ESTADO *e, char filename[]){
    
    FILE *save;
    
    
    // abre o ficheiro
    save = fopen(filename,"w");
    
    // escreve no ficheiro o tabuleiro
    
   escreve_tabuleuiro(e,save);

    // escreve no fichiro a lista dos movimentos
   escreve_movimentos(e,save);

    // fecha o arquivo
    fclose(save);

    mostrar_tabuleiro(e);
}
    



void ler_estado (ESTADO *e,char filename[]) {

    FILE *save;
    char str[12];
    
    save = fopen(filename,"r");

    if(save == NULL) {
        printf ("Save inexistente");
    } else {
        
        while(!feof(save)) {

       //Lê as primeiras 10 linhas correspondentes ao tabuleiro
        for (int i = 10;i>=0;i--){
               fgets(str,20,save);
               for (int j = 0; j <= 10; j++)
               {
                   switch (str[j])
                   {
                   case '.':
                        set_estado_casa(e,i-2,j-2,VAZIO);
                        break;
                   case '*':
                        set_estado_casa(e,i-2,j-2,BRANCA);
                        break;
                   case '#':
                        set_estado_casa(e,i-2,j-2,PRETA);
                        break;
                   }
               }
        }

        //Lê a lista de movimentos (Cada linha da lista possui 9 caracteres)
        int indice = 0;
        while (fgets(str,20,save)!=NULL){
            COORDENADA j1 = {str[4]-97,str[5]-49};
            //Verifica se o jogador 2 já jogou naúltima jogada
            if (str[7]!=' ')
            {   
                COORDENADA j2 = {str[7]-97, str[8]-49};
                JOGADA j = {j1,j2};
                set_jogada_indice(e,j,indice);
                set_jogador_atual(e,1);
                set_numero_de_jogadas(e,indice);
            } else
            {
                set_jogador_atual(e,2);
                set_numero_de_jogadas(e,indice);
                set_ultima_jogada(e,j1);
            }
            // Limpa a string
            for (int i = 0; i < 12; i++)
            {
                str[i]=' ';
            }
            indice++;
        }

    }
    putchar ('\n');
    mostrar_tabuleiro(e);
    }
}

void imprime_movimentos(ESTADO *e){
    int temp = 0;
    //Percorre a lista de movimentos e imprime-a no terminal
    for (int i = 0; i < 32; i++) {
        if (e->jogadas[i].jogador1.coluna!=-1 && e->jogadas[i].jogador1.linha!=-1){
            printf("%d : %c%d",i+1,letra(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha+1);
        }

        if (e->jogadas[i].jogador2.coluna!=-1 && e->jogadas[i].jogador2.linha!=-1){
            printf(" %c%d \n",letra(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha+1);
            temp++;
        }
    }

    // Imprime a ultima jogada caso o jogador 1 tenha jodago e o jogador 2 não
    if ((obter_jogador_atual(e)==2)) printf("%d : %c%d",e->num_jogadas+1,letra(e->ultima_jogada.coluna),e->ultima_jogada.linha+1);

    printf("\n");
    mostrar_tabuleiro(e);
}



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
        
            if (casa_vencedora (e,coord) || jogada_presa (e,coord)) {
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;
            }
            else mostrar_tabuleiro(e);
                              
        }
    
        if(strlen(linha) == 2 && sscanf(linha,"%[Q]", &quit)){
            printf(" \n O jogo Terminou \n");
            set_numero_de_jogadas(e,32);
        }

        if (sscanf(linha,"gr %s", filename)) gravar_estado (e,filename);
    
        if (sscanf(linha, "ler %s", filename)) ler_estado(e,filename);

        if (sscanf(linha, "movs %s", filename)) imprime_movimentos(e);
      
    return 1;
}


char letra (int x){
     char arr [8] = {'a','b','c','d','e','f','g','h'};
     return arr [x]; 
}


void prompt (ESTADO *e){
    int n_jogadas = obter_numero_de_jogadas(e);
    int j_atual = obter_jogador_atual (e);
    COORDENADA a = obter_ultima_jogada (e);
    int x = a.coluna;
    char col = letra(x);
    int y = a.linha;
    putchar ('\n');
    printf ("#%d PL%d %c%d\n", n_jogadas, j_atual,col,y+1);

}
