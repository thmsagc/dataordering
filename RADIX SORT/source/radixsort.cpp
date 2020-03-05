/*
	Atividade de Ordenação de Dados
	IMPLEMENTAÇÃO DO ALGORITMO RADIX SORT
	@author Thomás Augusto Gouveia Chaves
	@version 05/03/2020
*/

#include "radixsort.h"

int main(int argc, char **argv){

	if(argc != 2){
	    puts("Inicie com: nome_da_instancia (ex. nome_do_executavel v10.txt).");
	    return 0;
	}

	ifstream instancia(argv[1], ios::in);
	if(!instancia){
		puts("Erro ao criar arquivo de saída!");
		return 0;
	}

	int elementos;
	instancia >> elementos;
	vector<int> vetor(elementos);
	puts("Vetor de entrada:");
	for(int i = 0; i < elementos; i++){
		instancia >> vetor[i];
		cout << vetor[i] << " ";
	}

	radix_sort(vetor);

	ofstream resultado("resultado.txt");
	if(!resultado){
		puts("Erro ao criar arquivo de saída!");
		return 0;
	}
	printf("\nElementos ordenados: %d\n", vetor.size());
	puts("Vetor ordenado:");
	for(int i = 0; i < vetor.size(); i++){
		resultado << vetor[i] << " ";
		cout << vetor[i] << " ";
	}
	instancia.close();
	return 0;
}

void counting_sort(vector<int> &v, int base){

    vector<int> counter(10, 0);
	vector<int> result(v.size());

	for(int i = 0; i < v.size(); i++)
		counter[(v[i]/base)%10]++;

	for(int i = 1; i < v.size(); i++)
		counter[i] = counter[i-1]+counter[i];

    for(int i = 0; i < v.size(); i++)
		result[counter[(v[i]/base)%10]-- - 1] = v[i];
	v = result;
}

int numero_maior(vector<int> &v){
	int maior = 0;
	for(int i = 0; i < v.size(); i++)
		if(v[i] > maior)
			maior = v[i];
	return maior;
}

void radix_sort(vector<int> &v){
    int maior = numero_maior(v); 

    for (int base = 1; maior/base > 0; base *= 10) 
        counting_sort(v, base); 
} 
