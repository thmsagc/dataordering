/*
    Atividade de Ordenação de Dados

    Implementação do Algoritmo Counting Sort
    @author Thomás Augusto Gouveia Chaves
    @version 04/03/2020
*/
#include "countingsort.h"

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

	for(int i = 0; i < elementos; i++){
		instancia >> vetor[i];
		cout << vetor[i] << " ";
	}

	vetor = counting_sort(vetor);

	ofstream resultado("resultado.txt");
	if(!resultado){
		puts("Erro ao criar arquivo de saída!");
		return 0;
	}
	printf("\nElementos ordenados: %d\n", vetor.size());
	for(int i = 0; i < vetor.size(); i++){
		resultado << vetor[i] << " ";
		cout << vetor[i] << " ";
	}
	instancia.close();
	return 0;
}

vector<int> counting_sort(vector<int> &v){
    int maior = 0;

	for(int i = 0; i < v.size(); i++)
		if(v[i] > maior)
            maior = v[i];

    vector<int> counter(v.size()+1, 0);
	vector<int> result(v.size());

	for(int i = 0; i < v.size(); i++)
		counter[v[i]]++;

	for(int i = 1; i < v.size(); i++)
		counter[i] = counter[i-1]+counter[i];

    for(int i = 0; i < v.size(); i++)
		result[counter[v[i]]-- - 1] = v[i];

    return result;
}





















