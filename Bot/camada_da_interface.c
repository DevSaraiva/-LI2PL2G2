#include "camada_de_dados.h"
#include "camada_da_interface.h"
#include "logica_do_programa.h"
#include "listas.h"
#include "bot.h"

#define BUF_SIZE 1024

char letra (int x){
     char arr [8] = {'a','b','c','d','e','f','g','h'};
     return arr [x]; 
}

void escreve_tabuleuiro(ESTADO *e,FILE *save){
    int i, j;

     for (i = 7; i >= 0; i--){
   
        for(j = 0; j < 8; j++){
            
            if (i == 7 && j == 7) fprintf(save,"2");
            else if(i == 0 && j == 0) fprintf(save,"1");
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
        fprintf(save,"\n");
        
    }

    fprintf(save,"\n"); 
}

void escreve_movimentos(ESTADO *e, FILE *save){
    
    int temp = 0;
    int num_jogadas = obter_numero_de_jogadas (e);
    
    //Percorre a lista de movimentos e imprime-a no ficheiro
    
    for (int i = 0; i < num_jogadas; i++) {
        
        int ncoluna1 = e->jogadas[i].jogador1.coluna;
        int nlinha1 = e->jogadas[i].jogador1.linha + 1;
        int ncoluna2 = e->jogadas[i].jogador2.coluna;
        int nlinha2 = e->jogadas[i].jogador2.linha + 1;
        
        if (e->jogadas[i].jogador1.coluna != -1 && e->jogadas[i].jogador1.linha != -1){
            fprintf(save, "%02d: %c%d",i + 1,letra(ncoluna1),nlinha1);
        }

        if (e->jogadas[i].jogador2.coluna !=-1 && e->jogadas[i].jogador2.linha != -1){
            fprintf(save, " %c%d\n",letra(ncoluna2),nlinha2);
            temp++;
        }
    }


    // Imprime a ultima jogada caso o jogador 1 tenha jodago e o jogador 2 não
    
    if (obter_jogador_atual(e) == 2)  fprintf(save, "%02d: %c%d", num_jogadas + 1, letra(e->ultima_jogada.coluna),e->ultima_jogada.linha + 1);
}


void gravar_estado (ESTADO *e, char filename[]){
    FILE *save;
    // abre o ficheiro
    save = fopen(filename,"w");
    // escreve no ficheiro o tabuleiro
   escreve_tabuleuiro(e,save);
    // escreve no ficheiro a lista dos movimentos
   escreve_movimentos(e,save);
    // fecha o arquivo
    fclose(save);
}
    



void ler_estado (ESTADO *e,char filename[]) {
    inicializar_estado();
    FILE *save;
    char str[BUF_SIZE];
    save = fopen(filename,"r");
    if(save == NULL) {
        printf ("Save inexistente ");
    } else {
        
        while(!feof(save)) {

       //Lê as primeiras 10 linhas correspondentes ao tabuleiro
        for (int i = 7; i >= -1; i--){
		if (fgets(str,BUF_SIZE,save)==NULL) return;
               for (int j = 0; j <= 7; j++)
               {
                   switch (str[j])
                   {
                   case '.':
                        set_estado_casa(e,i,j,VAZIO);
                        break;
                   case '*':
                        set_estado_casa(e,i,j,BRANCA);
                        break;
                   case '#':
                        set_estado_casa(e,i,j,PRETA);
                        break;
                   }
               }
        }

        //Lê a lista de movimentos (Cada linha da lista possui 9 caracteres)
        int indice = 0;
        while (fgets(str,20,save) != NULL){

            COORDENADA c1 = {str[4]-97,str[5]-49};
            //Verifica se o jogador 2 já jogou na última jogada
            
            
            if (strlen(str) > 7)
            {   
                COORDENADA c2 = {str[7]-97, str[8]-49};
                JOGADA j = {c1,c2};
                set_jogada_indice(e,j,indice);
                set_jogador_atual(e,1);
                set_numero_de_jogadas(e,indice + 1);
                set_ultima_jogada(e,c2);
           
            } else
            {
               
                set_jogador_atual(e,2);
                set_ultima_jogada(e,c1);

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
    }
}

