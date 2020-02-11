#include "insertion.h"

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

	vetor = insertion_sort(vetor);

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


vector<int> insertion_sort(vector<int> &v){
	int atual, anterior;
	for(int i = 1; i < v.size(); i++){
		atual = v[i];
		anterior = i-1;
		while((anterior >= 0) && (v[anterior] > atual)){
			v[anterior+1] = v[anterior];
			anterior--;
		}
		v[anterior+1] = atual;
	}
	return v;
}