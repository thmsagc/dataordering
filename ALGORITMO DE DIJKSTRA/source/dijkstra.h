#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;
#define infinito numeric_limits<int>::max()

class Grafo{
private:
	void ler_arquivo(string dir);
	vector<vector<int>> matriz_de_adjacencias;
	int num_vertices;

public:
	Grafo(string dir){
		ler_arquivo(dir);
	}

	~Grafo(){

	}

	vector<vector<int>> getMatriz(){
		return matriz_de_adjacencias;
	}

	int getNumVertices(){
		return num_vertices;
	}

	void setMatriz(vector<vector<int>> m){
		matriz_de_adjacencias = m;
	}

	void setNumVertices(int n){
		num_vertices = n;
	}
};

void Grafo::ler_arquivo(string dir){
	ifstream instancia(dir, ios::in);

	if(!instancia){
		puts("Erro ao abrir instância numérica!");
		exit(1);
	}

	int vertices;
	instancia >> vertices;

	vector<vector<int>> matriz(vertices, vector<int>(vertices));

	for(int i = 0; i < vertices; i++)
		for(int j = i; j < vertices; j++){
			if(i == j)
				matriz[i][j] = 0;
			else
				instancia >> matriz[i][j];

			matriz[j][i] = matriz[i][j];
		}

	setMatriz(matriz);
	setNumVertices(vertices);
	
	instancia.close();
}


vector<int> initialize_single_source(int vertices, int v_origem, vector<int> &p);
void dijkstra(Grafo g, vector<int> &d, vector<int> &p);
void relax(pair<int, int> noAtual, int vizinho, Grafo data, vector<pair<int, int>> &heap, vector<int> &dist, vector<int> &p);

void fp_decreaseKey(vector<pair<int, int>> &fp, int valor, int i);
pair<int, int> fp_extractMin(vector<pair<int, int>> &fp);
void fp_minHeapify(vector<pair<int, int>> &fp, int no, int fim);
void fp_minInsert(vector<pair<int, int>> &fp, int i, int valor);


#endif