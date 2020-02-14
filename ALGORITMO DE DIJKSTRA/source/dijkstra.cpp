/*
	IMPLEMENTAÇÂO DO ALGORITMO DE DIJKSTRA
	@author Thomás Augusto Gouveia Chaves
	@version 11/02/2020
*/

#include "dijkstra.h"

int main(int argc, char **argv) {
	if(argc != 3){
	    puts("Inicie com: nome_da_instancia vertice_de_origem (ex. dij10.txt 1).");
	    exit(1);
	}

	string dir = argv[1];
	int s = atoi(argv[2]);

	Grafo g(dir);

	vector<int> p(g.getNumVertices());
	vector<int> d = initialize_single_source(g.getNumVertices(), s, p);

	dijkstra(g, d, p);

    ofstream result("resultado.txt");

    if(!result){
    	puts("Erro ao criar arquivo de saída!");
    	exit(0);
    }

    for(int i = 0; i < d.size(); i++){
    	result << s <<" a " << i << ": "  << d[i] << " ";
    	result << endl;
    }

    result.close();
}

void dijkstra(Grafo g, vector<int> &d, vector<int> &p){
	//vértices que foram visitados
    vector<bool> S(g.getNumVertices());
    //fila de prioridade
    vector<pair<int, int>> fila;
    for(int i = 0; i < g.getNumVertices(); i++)
    	fp_minInsert(fila, i, d[i]);

	//dijkstra
    while(!fila.empty()){
	    pair<int, int> u = fp_extractMin(fila); 		//origem
	    S[u.first] = true; 								//visitados
	    for(int id_dest = 0; id_dest < fila.size(); id_dest++){
			pair<int, int> v = fila[id_dest]; 			//destino
			int w = g.getMatriz()[u.first][v.first]; 	//aresta
	        relax(u, v, w, fila, d, p);
	    }
    }
}

vector<int> initialize_single_source(int vertices, int v_origem, vector<int> &p){
	vector<int> d(vertices);
	for(int i = 0; i < d.size(); i++){
		d[i] = infinito;
		p[i] = -1;
	}
	d[v_origem] = 0;
	return d;
}

void relax(pair<int, int> u, pair<int, int> v, int w, vector<pair<int, int>> &fila, vector<int> &d, vector<int> &p){
    if(v.second > u.second + w){
    	d[v.first] = u.second + w;
    	fp_decreaseKey(fila, (w + u.second), v.first);
    	p[v.first] = u.first;
    }
}

/* FILA DE PRIORIDADE */
void fp_decreaseKey(vector<pair<int, int>> &fp, int chave, int i){
    if(chave < fp[i].second){
        fp[i].second = chave;

        if(fp.size() == 1) return;

        int pai = (i-1)/2;
        while (fp[pai].second > fp[i].second){
            swap(fp[i], fp[pai]);
            i = pai;
            pai = (i-1)/2;
        }
    }
}

pair<int, int> fp_extractMin(vector<pair<int, int>> &fp){
    if(fp.size() < 1){
        puts("heap underflow");
        exit(1);
    }

    pair<int, int> menor = fp[0];
    swap(fp[0], fp[fp.size()-1]);
    fp.pop_back();
    fp_minHeapify(fp, 0, fp.size());
    return menor;
}

void fp_minHeapify(vector<pair<int, int>> &fp, int i, int ultimo){
    int menor = i;
    int fesq = i*2+1;
    int fdir = i*2+2;

    if(fesq < ultimo){
        if(fp[fesq].second < fp[menor].second){
            menor = fesq;
        }
    }
    if(fdir < ultimo){
        if(fp[fdir].second < fp[menor].second){
            menor = fdir;
        }
    }
    if(menor != i){
        swap(fp[i], fp[menor]);
        fp_minHeapify(fp, menor, ultimo);
    }
}

void fp_minInsert(vector<pair<int, int>> &fp, int i, int chave){
    pair<int, int> p = {i, infinito};
    fp.push_back(p);
    fp_decreaseKey(fp, chave, i);
}
