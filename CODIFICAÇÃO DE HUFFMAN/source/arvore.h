#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

/* Estrutura dos nós da árvore*/
struct No{
    unsigned char caractere;            //caractere
    int frequencia_o;                   //frequência de ocorrência do caractere
    string codigo_de_bit;               //caminho da raiz até o nó
    No *filho_esquerdo, *filho_direito; //ponteiros dos filhos
};
typedef struct No No;

struct noC{
    bool operator()(No* um, No* dois){
        return um->frequencia_o > dois->frequencia_o;
    }
};
typedef struct noC noC;

typedef priority_queue<No*, vector<No*>, noC> Fila;

/* Estrutura da árvore */
struct arvore{
    vector<int> frequencia_o;      //vetor de frequências
    Fila heap_minimo;              //fila de prioridade
    No *arvore_raiz;               //raiz da árvore
    int frequencia_geral = 0;      //frequência total
};
typedef struct arvore Arvore;

void atualiza_codigos_de_bit(No* no, string codigo);
void construir_arvore(Arvore* arvore, Fila heap_minimo);
Arvore* ler_arquivo(string nome_arquivo, int escolha);

Arvore* ler_arquivo(string nome_arquivo, int escolha){
    ifstream arquivo(nome_arquivo, ios::in);

    vector<int> frequencia(256, 0);
    unsigned char c;
    //inicia frequencia para codificar
    if(escolha == 1){
        while(arquivo >> noskipws >> c){
            unsigned int x = int(c);
            frequencia[x]++;
        }
    //inicia frequencia para decodificar
    } else {
        int frequencia_geral = 0;
        for(unsigned int i = 0; i < frequencia.size(); i++){
            int x = 0;
            arquivo.read(reinterpret_cast<char*>(&x), sizeof(x));
            frequencia[i] = x;
            frequencia_geral+= x;
        }        
    }

    //cria fila de prioridade
    Fila heap;
    for (unsigned int i = 0; i < frequencia.size(); i++){
        if(frequencia[i] > 0){
            unsigned char caract = i;    
            No* no = new No;
            no->caractere = caract;
            no->frequencia_o = frequencia[i];
            no->filho_esquerdo = 0;
            no->filho_direito = 0;
            heap.push(no);
        }
    }

    //cria a árvore de huffman
    Arvore* arvore;
    arvore->frequencia_o = frequencia;
    arvore->heap_minimo = heap;
    construir_arvore(arvore, arvore->heap_minimo);
    atualiza_codigos_de_bit(arvore->arvore_raiz, "");

    //retorna o nó
    return arvore;
}

void construir_arvore(Arvore* arvore, Fila heap_minimo){
    while(heap_minimo.size() != 1){
        /* Retira os elementos do Heap em ordem de prioridade e os armazena */
        No* f_esquerda = heap_minimo.top();
        heap_minimo.pop();
        No* f_direita = heap_minimo.top();
        heap_minimo.pop();

        int soma_das_frequencias = f_esquerda->frequencia_o + f_direita->frequencia_o;

        /* Novo nó que será pai dos elementos retirados */
        No* novo = new No;
        novo->filho_esquerdo = f_esquerda;
        novo->filho_direito = f_direita;
        novo->caractere = '\0';
        novo->frequencia_o = soma_das_frequencias;
        /* Adiciona o novo nó no heap */
        heap_minimo.push(novo);
    }
    /* Nova raiz da árvore de huffman */
    arvore->arvore_raiz = heap_minimo.top();
}

void atualiza_codigos_de_bit(No* no, string codigo){
    if (no->filho_esquerdo == nullptr && no->filho_direito == nullptr)
        no->codigo_de_bit = codigo;     
    else {
        atualiza_codigos_de_bit(no->filho_esquerdo, codigo + '0');
        atualiza_codigos_de_bit(no->filho_direito, codigo + '1');
    }
}