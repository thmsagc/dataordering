/*
	 ALGORITMOS DE ORDENAÇÃO
PROBLEMA DO CAMINHO MÍNIMO (DIJKSTRA)

	@author Thomás Augusto Gouveia Chaves
	@author 20180002671
*/

#include "dijkstra.h"


#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>


int main(){

    puts("Insira o local do arquivo:");
    cin.ignore();
	string dir;
	getline(cin, dir);

	ifstream arq(dir, ios::in);

    if (!arq){
        puts("Erro ao abrir o arquivo!");
        exit(1);
    }

    Grafo grafo;

    int vertices;
    arq >> vertices;
    vector<vector<int>> mat(vertices, vector<int>(vertices));

    for(int row = 0; row < vertices; row++){
        for(int col = row; col < vertices; col++){
            if(row == col)
                mat[row][col] = 0;
            else
                arq >> mat[row][col];

            mat[col][row] = mat[row][col];
        }
    }

    grafo.matriz = mat;
    grafo.num_vertices = vertices;

    puts("Insira o indice desejado do grafo:");
    cin.ignore();
	int u;
	scanf("%d", &u);

	dijkstra(grafo, u);
}

void dijkstra(Grafo grafo, int u) {
	/* Inicilização do grafo */
	vector<int> pi(grafo.num_vertices);
	vector<int> d = initialize_single_source(grafo.num_vertices, pi, u);
	vector<bool> s(grafo.num_vertices);
	/**/

	/* Criação e inicialização da fila de prioridade mínima */
	vector<pair<int, int>> fila_pri_min;

	for(int i = 0; i < grafo.num_vertices; i++)
		heap_min_insert(fila_pri_min, i, d[i]);
	/**/

	/* Dijkstra */
	while (!fila_pri_min.empty()) {
		pair<int, int> u = heap_extract_min(fila_pri_min);
		s[u.first] = true;
		for(int i = 0; i < fila_pri_min.size(); i++){
			relax(u, i, grafo, fila_pri_min, d, pi);
		}
	}
	/**/
	gerar_resultado(u, d);
}

void gerar_resultado(int u, vector<int> d){
	ofstream arq("result.txt");

	if(!arq){
		puts("Erro ao criar o arquivo de saída!");
		exit(1);
	}

	for(int i = 0; i < d.size(); i++) {
		arq << u <<"→" << i << ": "  << d[i] << " ";
		arq << endl;
	}

	arq.close();
}

vector<int> initialize_single_source(int tamanho, vector<int> &pi, int u){
	
	vector<int> d(tamanho);

	for(int i = 0; i < d.size(); i++){
	    d[i] = numeric_limits<int>::max(); 	  //Inicializa o vértice com valor infinito
	    pi[i] = -1;							  //Predecessores inicialmente com valor -1
	}

	d[u] = 0;						  	  	  //Valor do índice inicialmente igual a 0
	return d;							  	  //Vetor de distâncias inicializado
}

void relax(pair<int, int> u, int v, Grafo grafo, vector<pair<int, int>> &fila_pri_min, vector<int> &d, vector<int> &p){
	int inc_aresta = grafo.matriz[u.first][fila_pri_min[v].first];
	int w = u.second + inc_aresta;

	if(fila_pri_min[v].second > w){
	    d[fila_pri_min[v].first] = w;
	    heap_decrease_key(fila_pri_min, w, v);
	    p[v] = u.first;
	}
}


