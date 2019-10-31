#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    IMPLEMENTAÇÃO DO ALGORITMO DE ORDENAÇÃO HEAP SORT
    @author Thomás Augusto Gouveia Chaves - CI/UFPB
    @author thomaschaves@cc.ci.ufpb.br
    @version 31/10/2019

    O método utilizado foi receber uma string do usuário
    referente ao nome do arquivo (com o tipo). A partir
    desta entrada serão aplicado os algoritmos necessários
    para a devida ordenação. Após o processamento, gera um
    novo arquivo com os dados processados.
**/

/* PROTÓTIPOS DE FUNÇÕES */
void build_heap(int*);
void heapsort(int*);
void max_heapify(int *, int);
/*   */

/*
   > MAIN <
*/
int main(void){
    /* RECEBE O NOME DO ARQUIVO A SER TRABALHADO */
    char nomearq[16];
    /* RECEBE DO USUÁRIO O NOME DO ARQUIVO DESEJADO*/
    printf("Insira o nome do arquivo que voce deseja trabalhar: ");
    scanf("%s", nomearq);
    puts(" ");
    /* INICIA O ARQUIVO PARA LEITURA*/
    FILE * arq = fopen(nomearq, "r");
    /* SE/SE NÃO ENCONTRAR O ARQUIVO*/
    if(!arq){
      puts("ERRO: Arquivo nao encontrado!");
      exit(1);
    } else puts("STATUS: Arquivo carregado.");
    /* LÊ O PRIMEIRO ELEMENTO DO ARQUIVO, QUE CORRESPONDE AO NÚMERO DE LINHAS*/
    int numlinhas = 0;
    fscanf(arq, "%d", &numlinhas);

    /* ENCERRA SE NÃO HOUVER NENHUM ELEMENTO A SER ORDENADO*/
    if(numlinhas == 0){
      puts("ERRO: Não ha nada a ordenar!");
      exit(1);
    }

    /* CRIA UM VETOR COM O NÚMERO DE LINHAS A SEREM TRABALHADAS +1 (NÚMERO DE ELEMENTOS)*/
    int vetor[numlinhas+1];
    vetor[0] = numlinhas;

    /* VARIÁVEL AUXILIAR DE ACESSO AO VETOR */
    int auxvet = 1;
    printf("STATUS: Vetor criado com espaco para %d valores.\n", numlinhas);

    /* ARMAZENA OS ELEMENTOS DO ARQUIVO NO VETOR A PARTIR DO ÍNDICE 1 */
    int memoria;
    while (!feof (arq)){
        fscanf(arq, "%d", &memoria);
        vetor[auxvet] = memoria;
        auxvet++;
    }

    /* RECEBE DO USUÁRIO A POSIÇÃO NA HEAP A QUAL DESEJA-SE ORDENAR
    int elemento = 0;
    printf("MAX HEAPIFY: Qual posicao de elemento da heap voce deseja ordenar?\n:: ");
    scanf("%d", &elemento);

    if(elemento == 0){
      printf("ERRO: Posição inválida! [1-%d]!", numlinhas);
      exit(1);
    }
    max_heapify(vetor, elemento);
    */

    heapsort(vetor);

    /* ESCREVE O VETOR MODIFICADO EM UM NOVO ARQUIVO */
    arq = fopen(strcat(nomearq, "ORD"), "w");
    for(int i = 0; i < vetor[0]+1; i++)
      fprintf(arq, "%d\n", vetor[i]);
    printf("STATUS: Arquivo %s gerado com sucesso.", strcat(nomearq, "ORD"));
    fclose(arq);
    return 0;
}

/* IMPLEMENTAÇÃO DO HEAP MÁXIMO */
void build_max_heap(int* vetor){
  for(int i = vetor[0]/2; i > 0; i--)
    max_heapify(vetor, i);
}

/* IMPLEMENTAÇÃO DO HEAP SORT */
void heapsort(int* vetor){
  build_max_heap(vetor);
  int aux = vetor[0];
  for(int i = vetor[0]; i > 1; i--){
    /* TROCA DOIS VALORES */
    int mem = vetor[1];
    vetor[1] = vetor[i];
    vetor[i] = mem;
    /* */
    --vetor[0];
    max_heapify(vetor, 1);
  }
  vetor[0] = aux;
}

/* CONSTANTES SIMBÓLICAS */
#define esq(i) (2*i)
#define dir(i) (2*i+1)

/* FUNÇÃO RESPONSÁVEL PELA ORDENAÇÃO */
void max_heapify(int * vetor, int indice){

  /* ARMAZENA OS ELEMENTOS DA ESQUERDA E DIREITA DE UM ÍNDICE */
  int esq = esq(indice);
  int dir = dir(indice);
  int maior;

  //* vetor[0] CORRESPONDE AO NÚMERO DE ELEMENTOS A SEREM MODIFICADOS DA HEAP */
  if((esq <= vetor[0]) && (vetor[esq] > vetor[indice]))
    maior = esq;
  else
    maior = indice;

  if((dir <= vetor[0]) && (vetor[dir] > vetor[maior]))
    maior = dir;

  if(maior != indice){
    /* TROCA O VALOR DOS ELEMENTOS */
    int mem = vetor[indice];
    vetor[indice] = vetor[maior];
    vetor[maior] = mem;
    /* RECURSIVIDADE */
    max_heapify(vetor, maior);
  }
}
