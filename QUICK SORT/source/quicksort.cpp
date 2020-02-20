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
	if(inicio == fim) return;
	int meio = ordena(v, inicio, fim);
	quick(v, inicio, meio-1);
	quick(v, meio+1, fim);
}

void ordena(vector<int> &v, int inicio, int fim){
	int pivor = fim;
	bool marcou = false;
	int marcado = 0;

	for(int i = 0; i < (fim-1); i++){
		if(v[i] > v[pivor] && marcou == false){
			marcou = true;
			marcado = i;

		} else if(v[i] < v[pivor] && marcou == true){
			swap(v[marcado] , v[i]);
			marcado++;
		}
	}
	swap(marcado, pivor);
}
