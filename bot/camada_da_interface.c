#include "camada_da_interface.h"

#define BUF_SIZE 1024




void mostrar_tabuleiro(ESTADO *estado) {

  int i, j;
    
    for (i = 7; i >= 0; i--){
        putchar('\n');
        printf ("%d ",i + 1);
        
        for(j = 0; j < 8; j++){
            
            if (i == 7 && j == 7) putchar('2');
            else if(i == 0 && j == 0) putchar('1');
            else {
                    switch (estado -> tab [i][j])
                    {
                    case VAZIO:
                        printf(".");
                        break;
                    
                    case BRANCA:
                        printf("*");
                        break;
                    
                    case PRETA:
                        printf("#");
                    
                    
                    }
        }
        }
    }
    putchar('\n');
    printf("  abcdefgh");
    putchar ('\n');

    prompt (estado);
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
    int num_jogadas = obter_numero_de_jogadas (e);
    
    //Percorre a lista de movimentos e imprime-a no ficheiro
    
    for (int i = 0; i < num_jogadas; i++) {
        
<<<<<<< HEAD
        int ncoluna1 = obter_jogada_por_jog(e,i,1).coluna; 
        int nlinha1 =  obter_jogada_por_jog(e,i,1).linha + 1;  
        int ncoluna2 = obter_jogada_por_jog(e,i,2).coluna;
        int nlinha2 = obter_jogada_por_jog(e,i,2).linha + 1;
            
        
        if (ncoluna1 != -1 && nlinha1 != -1){
            fprintf(save, "%02d: %c%d",i + 1,letra(ncoluna1),nlinha1);
        }

        if (ncoluna2 !=-1 && nlinha2 != -1){
=======
        int ncoluna1 = e->jogadas[i].jogador1.coluna;
        int nlinha1 = e->jogadas[i].jogador1.linha + 1;
        int ncoluna2 = e->jogadas[i].jogador2.coluna;
        int nlinha2 = e->jogadas[i].jogador2.linha + 1;
       
        if (e->jogadas[i].jogador2.coluna !=-1 && e->jogadas[i].jogador2.linha != -1){
            fprintf(save, "%02d: %c%d",i + 1,letra(ncoluna1),nlinha1);
>>>>>>> 2f927eca2eb4c07aaf937ccb3a11c65197a2d1c4
            fprintf(save, " %c%d\n",letra(ncoluna2),nlinha2);
        }
    }


    // Imprime a ultima jogada caso o jogador 1 tenha jodago e o jogador 2 não
    
<<<<<<< HEAD
    if (obter_jogador_atual(e) == 2){
        int c_ult = obter_ultima_jogada(e).coluna;
        int l_ult = obter_ultima_jogada(e).linha;
        fprintf(save, "%02d: %c%d", num_jogadas + 1, letra(c_ult),l_ult + 1);
    }
=======
    if (obter_jogador_atual(e) == 2)  fprintf(save, "%02d: %c%d ", num_jogadas + 1, letra(e->ultima_jogada.coluna),e->ultima_jogada.linha + 1);
>>>>>>> 2f927eca2eb4c07aaf937ccb3a11c65197a2d1c4
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

    inicializar_estado(e);

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
                set_jogada_jog (e,indice,1,c1);

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
    int num_jogadas = obter_numero_de_jogadas (e);
    
    //Percorre a lista de movimentos e imprime-a no terminal
    
    for (int i = 0; i < num_jogadas; i++) {
            
            int ncoluna1 = obter_jogada_por_jog(e,i,1).coluna; 
            int nlinha1 =  obter_jogada_por_jog(e,i,1).linha + 1;  
            int ncoluna2 = obter_jogada_por_jog(e,i,2).coluna;
            int nlinha2 = obter_jogada_por_jog(e,i,2).linha + 1;
            
            if (ncoluna1 != -1 && nlinha1 != -1)
                printf("%02d: %c%d",i + 1,letra(ncoluna1),nlinha1);
            

            if (ncoluna2 !=-1 && nlinha2 != -1)
                printf(" %c%d\n",letra(ncoluna2),nlinha2);          
        }
      // Imprime a ultima jogada caso o jogador 1 tenha jodado e o jogador 2 não
        
        if (obter_jogador_atual(e) == 2){
            int c_ult = obter_ultima_jogada(e).coluna;
            int l_ult = obter_ultima_jogada(e).linha;
            printf("%02d: %c%d", num_jogadas + 1, letra(c_ult),l_ult + 1);
        }
    printf("\n");
    mostrar_tabuleiro(e);
}

void apaga_ultima_jogada_completa (ESTADO *e){
    int i = obter_numero_de_jogadas (e);

    COORDENADA j1 = obter_jogada_por_jog (e,i-1,1);
    COORDENADA j2 = obter_jogada_por_jog (e,i-1,2);
    set_estado_casa_c(e,j1,VAZIO);
    set_estado_casa_c(e,j2,VAZIO);
    set_jogada (e,i-1,-1);
    int c = obter_jogada_por_jog(e,i-2,2).coluna;
    int l = obter_jogada_por_jog(e,i-2,2).linha;
    COORDENADA ult = {c,l};
    set_estado_casa (e,l,c,BRANCA);
    set_ultima_jogada (e,ult);
    set_numero_de_jogadas (e,i-1);
}




void apaga_ultima_jogada (ESTADO *e){
    int i = obter_numero_de_jogadas (e);

    if (i == 1) {
        set_jogador_atual(e,1);
        set_numero_de_jogadas(e,0);
        COORDENADA c = {4,4};
        set_ultima_jogada(e,c);
        limpa_tabuleiro(e);
        limpa_jogadas(e);
        set_valor_pos (e,0);
        set_comando_pos(e,0);
    }
    else { 
        if (obter_jogada_por_jog(e,i,1).coluna == -1 && obter_jogada_por_jog(e,i,1).linha == -1)
        apaga_ultima_jogada_completa (e);
        else{
            COORDENADA j = obter_jogada_por_jog (e,i,1); 
            set_estado_casa_c(e,j,VAZIO);
            COORDENADA coord = {-1,-1};
            set_jogada_jog (e,i,1,coord);
            int c = obter_jogada_por_jog(e,i-1,2).coluna;
            int l = obter_jogada_por_jog(e,i-1,2).linha;
            COORDENADA ult = {c,l};
            set_estado_casa (e,l,c,BRANCA);
            set_ultima_jogada (e,ult);
        }
    }
}

ESTADO escreve_pos (ESTADO *e,int n){
    ESTADO *s = inicializar_estado();
    int i;
    
    if (n == 0) mostrar_tabuleiro(s);
    else {
        set_estado_casa(s,4,4,PRETA);
        COORDENADA j1,j2;
        for (i=0;i < n;i++){
        j1 = obter_jogada_por_jog (e,i,1);
        j2 = obter_jogada_por_jog (e,i,2);
        set_estado_casa_c (s,j1,PRETA);
        set_estado_casa_c (s,j2,PRETA);
        }
        set_estado_casa_c (s,j2,BRANCA);
        set_ultima_jogada (s,j2);
        set_numero_de_jogadas (s,i);
        mostrar_tabuleiro(s);
    }
    return *e;
}




int interpretador(ESTADO *e) {
        char linha[BUF_SIZE];
        char col[2], lin[2];
        char quit;
        char filename[BUF_SIZE];
        int n_jog;
        
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
    
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if (obter_comando_pos(e)) {
                int n = obter_valor_pos(e);
                int nt = obter_numero_de_jogadas(e);
                for(int i = 0; n <= nt-i; i++)
                apaga_ultima_jogada (e);
            }
            jogar(e, coord);
           
            if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;
            }
            else mostrar_tabuleiro(e);
            if (obter_comando_pos(e)) set_comando_pos(e,0);                    
        }
    
    
        if(sscanf(linha,"%[Q]", &quit)){
            printf(" \n O jogo Terminou \n");
            set_numero_de_jogadas(e,32);
        }

        if (sscanf(linha,"gr %s", filename)) {gravar_estado (e,filename);
            if (obter_comando_pos (e))
            set_comando_pos(e,0);}
    
        if (sscanf(linha, "ler %s", filename)) {ler_estado(e,filename);
            if (obter_comando_pos(e) )
            set_comando_pos(e,0);}

        if (sscanf(linha, "movs %s", filename)) {imprime_movimentos(e);
            if (obter_comando_pos(e) )
            set_comando_pos(e,0);}
        
        if (sscanf(linha, "pos %d", &n_jog)){ 
            int n = obter_numero_de_jogadas(e);
            int j_atual = obter_jogador_atual (e);
            if (n_jog > n || j_atual == 1) printf("Posição anterior inválida\n");
            else {
                printf("%d\n",n);
                escreve_pos(e,n_jog);
            if (obter_comando_pos(e) == 0) set_comando_pos(e,1);
            set_valor_pos(e,n_jog);}
        }
        if (strcmp(linha, "jog\n")==0) {
            if (obter_comando_pos(e)) {
                int n = obter_valor_pos(e);
                int nt = obter_numero_de_jogadas(e);
                for(int i = 0; n < nt-i; i++)
                apaga_ultima_jogada (e);
            }
            COORDENADA coord = joga_euclidiana(e);
           
            if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;
            }
            else mostrar_tabuleiro(e);
            if (obter_comando_pos(e)) set_comando_pos(e,0);                    
        }
            
        if (strcmp(linha, "jog2\n")==0) {
            if (obter_comando_pos(e)) {
                int n = obter_valor_pos(e);
                int nt = obter_numero_de_jogadas(e);
                for(int i = 0; n < nt-i; i++)
                apaga_ultima_jogada (e);
            }
            COORDENADA coord = joga_aleatorio(e);
           
            if (casa_vencedora (e,coord) || jogada_presa (e,coord)){
                int j_atual = obter_jogador_atual (e);
                printf("O vencedor é o PL%d\n",j_atual);
                e -> num_jogadas = 32;
            }
            else mostrar_tabuleiro(e);
            if (obter_comando_pos(e)) set_comando_pos(e,0);                    
        }
        
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
    printf ("#%d PL%d %c%d\n", n_jogadas+1, j_atual,col,y+1);

}