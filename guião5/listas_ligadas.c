#include <stdio.h>
#include <string.h>
#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"
#include "listas_ligadas.h"
#define BUF_SIZE 1024


int main() {
  LISTA L = criar_lista(); // Criar uma lista vazia
  char linha[BUF_SIZE];
    
  printf("Insira várias linhas, acabando com CTRL-D:\n");

  // control-D é a tecla CTRL e a tecla D ao mesmo tempo
  // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma cópia da string que foi lida
        // Insere uma cópia da linha lida na cabeça da lista
        L = insere_cabeca(L, strdup(linha));
    }

  printf("\n==============================\n");
  printf(  "=          PERCURSO          =\n");
  printf(  "==============================\n\n");
    // percorre sem remover os elementos da lista
    for(LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        // Vai buscar a cabeça da lista
        // Passa do tipo genérico void * para char *
        char *str = (char *) devolve_cabeca(T);
        printf("%s", str);
    }
    
  printf("\n==============================\n");
  printf(  "=           REMOCAO          =\n");
  printf(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!lista_esta_vazia(L)) {
        char *str = (char *) devolve_cabeca(L);
        L = remove_cabeca(L);
        printf("%s", str);
        free(str);
    }
  return 0;
}
