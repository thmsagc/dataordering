#include "quicksort.h"

int main(int argc, char **argv){
	if(!argc == 2){
		puts("Execute informando o nome da instância.\nEx: quicksort v10.txt");
	}

	string inst = argv[1];
	ifstream arq(inst, ios::in);
	int num_elementos;
	arq >> num_elementos;
	vector<int> result(num_elementos);
	for(int i = 0; i < result.size(); i++)
		arq >> vetor[i];
	quick(result);
	return 0;	
}

void quick(vector<int> &v, int inicio, int fim){
	int i, f, indice, aux;
	i = inicio;
	f = fim-1;
	indice = v[(inicio + fim)/2];

	while(i <= f){
		while(v[i] < indice && i < fim)
			i++;

		while(v[f] > indice && f > inicio)
			f--;

		if(i <= f){
			aux = v[i];
			v[i] = v[f];
			v[f] = aux;
			i++;
			f--;
		}
	}
	if(f > inicio)
		quicksort(v, inicio, f+1);
	if(i < fim)
		quicksort(v, i, fim);
}
