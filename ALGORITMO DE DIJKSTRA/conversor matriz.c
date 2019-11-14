#include <stdio.h>

int main(void){
    int tam;
    FILE * arq = fopen("dij10.txt","r");//abre para leitura a instancia numerica usada como exemplo
    if(!arq) {
            puts("nao foi possivel trabalhar com o arquivo");
            fclose(arq);
            return 1;
    }
    fscanf(arq, "%d", &tam);//lê primeira linha do arquivo(que representa sua quantidade de elementos), e salva na variavel 'tam'
    int vetor[tam][tam];//cria vetor de tamanho correto para armazenar dados(numeros inteiros) do arquivo

    if(tam){
            for(int i = 0; i<tam;++i){
                for(int j = i; j<tam;++j){
                        if(i==j){
                            vetor[i][i]=0;
                        }else{
                           fscanf(arq, "%d", &vetor[i][j]) ;
                           vetor[j][i]=vetor[i][j];
                        }
                }
            }
    } else printf("arquivo vazio");
    fclose(arq);
    for(int i = 0; i<tam;++i){
                for(int j = 0; j<tam;++j){
                    printf("%d ", vetor[i][j]);
                }
                puts("");
            }
}
