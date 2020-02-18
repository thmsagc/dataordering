/*
	Implementação do algoritmo Merge Sort
	@author Thomás Augusto Gouveia Chaves
	@version 18/02/2020
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

	vetor = merge_sort(vetor);

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


vector<int> merge_sort(vector<int> &v, int inicio, int tamanho){
	if(n < 1)
		return;
	int meio = tam/2;
	merge_sort(v, inicio, meio);
	merge_sort(v, meio+1, tam);
	intercalacao(v, inicio, meio, tam);
}

void intercalacao(vector<int> &v, int inicio, int meio, int fim){
	int i = inicio;
	int j = meio + 1;
	int k = inicio;
	vector<int> aux(v.size());
	aux = v;
	while(i <= meio && j <= fim){
		if(aux[i] < aux[j]){
			v[k] = aux[i];
			i++;
		} else {
			v[k] = aux[j];
			j++;
		}
		k++;
	}
	while(i <= meio){
		v[k] = aux[i];
		i++;
		k++;
	}
	while(j <= fim){
		v[k] = aux[j];
		j++;
		k++;
	}
}

