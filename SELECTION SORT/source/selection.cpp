/*
	Implementação do algoritmo Selection Sort
	@author Thomás Augusto Gouveia Chaves
	@version 11/02/2020
*/

#include "selection.h"

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

	vetor = selection_sort(vetor);

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


vector<int> selection_sort(vector<int> &v){
	for(int i = 0; i < v.size(); i++){
		int menor = i;
		for(int it = i+1; it < v.size(); ++it){
			if(v[it] < v[menor]){
				menor = it;
			}
		}
		swap(v[menor], v[i]);
	}
	return v;
}