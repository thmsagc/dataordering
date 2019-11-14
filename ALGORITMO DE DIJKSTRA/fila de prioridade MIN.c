/////////////////////////////////////////////////////////////////////////////////////
////////////////////JULIO CESAR BASILIO ALVES////////////////////////////////////////
/////////////////////////20180007631/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//FILA DE PRIORIDADE MINIMA

#include <stdio.h>

//prototipos
void minH(int*, int);
void buildminH(int*);
void heapSort(int*);
void troca(int*,int, int);
void print(int*);
int heapMminimo(int *);
void extractMin(int *);
void diminuiValor(int *, int , int );
void insereValor(int *, int );


////////////////////////////////////////////////////
//////                 MAIN                  ///////
////////////////////////////////////////////////////
int main(void){
    int tam=0;
    int aux=0;
    FILE * arq = fopen("couting.txt","r");//abre para leitura a instancia numerica usada como exemplo
    if(!arq) {
            puts("nao foi possivel trabalhar com o arquivo");
            fclose(arq);
            return 1;
    }
    fscanf(arq, "%d", &tam);//lê primeira linha do arquivo(que representa sua quantidade de elementos), e salva na variavel 'tam'
    int vetor[tam+1];//cria vetor de tamanho correto para armazenar dados(numeros inteiros) do arquivo
    vetor[0]=tam;//armazena o tamanho na primeira posição do vetor
    if(tam){
            while(aux<tam+1){//armazena demais valores no vetor criado
                    fscanf(arq, "%d", &vetor[aux+1]);
                    aux++;
            }
    } else printf("arquivo vazio");
    fclose(arq);
   // print(vetor);//escreve na tela o vetor antes de ser aplicado o heapSort
   // printf("\n");
    heapSort(vetor);
    insereValor(vetor, 2);
    print(vetor);//escreve na tela o vetor depois de ser aplicado o heapSort
    return 0;
}

////////////////////////////////////////
// funcao abaixo toma como verdade que os
// filhos do 'no' sao heaps minimos.
// e 'no' nao eh heap minimo.
// faz, por recorrencia, que o valor em 'no'
// desca a arvore
////////////////////////////////////////
void minH(int *a, int no){
    int menor=0;
    int esquerdo = 2*no;
    int direito  = (2*no)+1;
    if((esquerdo <= a[0])&&(a[esquerdo]>a[no])){
        menor = esquerdo;
    } else {
        menor = no;
    }
    if((direito <= a[0])&&(a[direito]>a[menor])){
        menor = direito;
    }
    if(menor != no){
        troca(a, no, menor);
        minH(a,menor);
    }
}

/////////////////////////////////
// funcao abaixo cria um heap minimo
// a partir de um vetor de inteiro
// qualquer dado
//////////////////////////////////
void buildminH(int * a){
    for(int i = a[0]/2 ; i > 0  ; i--)
        minH(a,i);
}

////////////////////////////////////
// funcao abaixo ordena em ordem
// crescente de valores  um dado
// vetor qualquer de inteiros
/////////////////////////////////////
void heapSort(int* a){
    buildminH(a);
    int aux=a[0];
    for(int i = a[0] ; i>1 ; i--){
            troca(a,i,1);
            --a[0];
            minH(a,1);
    }
    a[0]=aux;
}
//////////////////////////////////
// funcao abaixo troca de posicao
// os valores referentes as posicoes
// 'a' e 'b' do vetor 'vet' informado
//////////////////////////////////
void troca(int *vet, int a, int b){
        int aux = vet[a];
        vet[a] = vet[b];
        vet[b] = aux;


}

//retorna valor maximo da fila
int heapMinimo(int *vet){
    return vet[1];
}

//extrai valor maximo do heap
//diminui o valor [0], que representa seu tamanho
void extractMin(int *vet){
    if(vet[0]<1){
        return;
    }

    //int min = vet[1];
    vet[1] = vet[vet[0]];
    --vet[0];
    minH(vet, 1);
    //return vet;
}

//diminui valor do elemento vet[posi]
void diminuiValor(int *vet, int posi, int valor){
    if(valor > vet[posi]){
        return;
        }
    puts("entrou2");
    vet[posi]=valor;
    while((posi>1)&&(vet[posi/2]>vet[posi])){//[posi/2] se refere ao no' pai
        puts("entrou3");
        troca(vet, posi, posi/2);
        posi=posi/2;
        puts("entrou4");
    }
}

void insereValor(int *vet, int valor){
    ++vet[0];
    vet[vet[0]] = 99999;
    diminuiValor(vet, vet[0], valor);

}

///////////////////////////////////////
// funcao abaixo escreve na tela o
// vetor 'a' informado.
/////////////////////////////////////
void print(int *a){
    int aux=0;
    while(aux<=a[0]){
        printf("linha %d: %d\n",aux,a[aux]);
        aux++;
    }
}



