#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void heap_decrease_key(vector<pair<int, int>> &h, int indice, int novo_valor);
pair<int, int> heap_extract_min(vector<pair<int, int>> &h);
pair<int, int> heap_min(vector<pair<int, int>> &h);
void heap_min_heapify(vector<pair<int, int>> &h, int indice, int ultimo);
void heap_min_insert(vector<pair<int,int>> &h, int indice, int valor);

void heap_decrease_key(vector<pair<int, int>> &h, int indice, int novo_valor){
	if(novo_valor < h[indice].second){
		puts("Nada a fazer!");
	}
	h[indice].second = novo_valor;
	int pai = (indice - 1)/2;
	while((indice > 1) && (h[pai].second > h[indice].second))
		swap(h[indice], h[pai]);
		indice = pai;
}

pair<int, int> heap_extract_min(vector<pair<int, int>> &h){
	if(h.size() < 1){
		puts("heap underflow");
		exit(1);
	} else {
		pair<int, int> min = h[0];
		h[0] = h[h.size()-1];
		h.pop_back();
		heap_min_heapify(h, 0, h.size());
		return min;
	}
}

pair<int, int> heap_min(vector<pair<int, int>> &h){
	return h[0];
}

void heap_min_heapify(vector<pair<int, int>> &h, int indice, int ultimo){
	int min = indice;
	int f_esquerdo = indice * 2 + 1;
	int f_direito = indice * 2 + 2;

		if ((f_esquerdo < ultimo) && (h[f_esquerdo].second < h[min].second))
			min = f_esquerdo;
		else
			min = indice;

		if ((f_direito < ultimo) && (h[f_direito].second < h[min].second))
			min = f_direito;

		if(min != indice){
			swap(h[indice], h[min]);
			heap_min_heapify(h, indice, ultimo);
		}

}

void heap_min_insert(vector<pair<int,int>> &h, int indice, int valor){
	pair<int, int> novo;
	novo = {indice, numeric_limits<int>::max()};
	h.push_back(novo);
	heap_decrease_key(h, indice, valor);
}
