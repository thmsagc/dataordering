/*
	 ALGORITMOS DE ORDENAÇÃO
PROBLEMA DO CAMINHO MÍNIMO (DIJKSTRA)

	@author Thomás Augusto Gouveia Chaves
	@author 20180002671
*/


#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "fila_de_prioridade.h"
#include <vector>

using namespace std;


struct grafo{
	vector<vector<int>> matriz;
    int num_vertices;
};
typedef struct grafo Grafo;

void dijkstra(Grafo grafo, int u);
void gerar_resultado(int u, vector<int> d);
vector<int> initialize_single_source(int tamanho, vector<int> &p, int u);
void relax(pair<int, int> u, int v, Grafo grafo, vector<pair<int, int>> &h, vector<int> &d, vector<int> &p);


#endif
