/*
	Implementação do algoritmo Merge Sort
	@author Thomás Augusto Gouveia Chaves
	@version 20/02/2020
*/

#include "mergesort.h"

int main(int argc, char **argv){

	if(argc != 2){
	    puts("Inicie com: nome_da_instancia (ex. v10.txt).");
	    exit(1);
	}

	ifstream instancia(argv[1], ios::in);
	if(!instancia){
		puts("Erro ao criar arquivo de saída!");
		exit(1);
	}

	int elementos;
	instancia >> elementos;
	vector<int> vetor(elementos);

	for(int i = 0; i < elementos; i++){
		instancia >> vetor[i];
	}
	merge_sort(vetor, 0, elementos-1);

	ofstream resultado("resultado.txt");
	if(!resultado){
		puts("Erro ao criar arquivo de saída!");
		exit(1);
	}
	printf("Elementos ordenados: %d\n", vetor.size());
	for(int i = 0; i < vetor.size(); i++){
		resultado << vetor[i] << " ";
	}
	instancia.close();
	return 0;
}

void intercalacao(vector<int> &v, int inicio, int meio, int fim) 
{ 
    int i, j, k; 
    int p1 = meio - inicio + 1; 
    int p2 =  fim - meio; 
  
    int esquerda[p1], direita[p2]; 
  
    for (i = 0; i < p1; i++) 
        esquerda[i] = v[inicio + i];
    
    for (j = 0; j < p2; j++) 
        direita[j] = v[meio + 1+ j]; 
 
    i = 0;
    j = 0;
    k = inicio;

    while (i < p1 && j < p2){ 
        if (esquerda[i] <= direita[j]){ 
            v[k] = esquerda[i]; 
            i++; 
        } else { 
            v[k] = direita[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < p1){ 
        v[k] = esquerda[i]; 
        i++; 
        k++; 
    } 

    while (j < p2){ 
        v[k] = direita[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(vector<int> &v, int inicio, int fim) 
{ 
    if (inicio < fim){ 
        int meio = inicio+(fim-inicio)/2; 
        merge_sort(v, inicio, meio); 
        merge_sort(v, meio+1, fim); 
        intercalacao(v, inicio, meio, fim); 
    } 
} 
