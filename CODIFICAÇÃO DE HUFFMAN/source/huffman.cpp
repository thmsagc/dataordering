#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include "arvore.h"

using namespace std;

unordered_map<char, string> codigosbit;
void codigoMapeamento(No* no);
void codificar(string dir, Arvore* arvore);
void decodificar(string dir, Arvore* arvore);

int main(){
    puts("Insira o local do arquivo:");
    cin.ignore();
	string dir;
	getline(cin, dir);

	ifstream arq(dir, ios::in);

    puts("\nEscolha uma opção:\n  1- Codificar\n  2- Decodificar\n::");
    cin.ignore();
	int escolha;
	scanf("%d", &escolha);

    Arvore* arvore;

    /* Lê o arquivo e constroi a árvore de huffman */
    arvore = ler_arquivo(dir, escolha);
    codigoMapeamento(arvore->arvore_raiz);
    if(escolha == 1)
        codificar(dir, arvore);

    else if(escolha == 2)
        decodificar(dir, arvore);

    else
    	exit(1);
}


void codigoMapeamento(No* no){
    if(no){
        codigoMapeamento(no->filho_esquerdo);
        if(no->filho_esquerdo == nullptr && no->filho_direito == nullptr){
            codigosbit.insert(make_pair(no->caractere, no->codigo_de_bit));
        }
        codigoMapeamento(no->filho_direito);
    }
}

void codificar(string dir, Arvore* arvore){
	/* Lê o arquivo de entrada */
    ifstream arq(dir, ios::in);
    if(!arq){
    	puts("Erro ao abrir arquivo de entrada!");
    	exit(1);
    }

    /* Cria o arquivo de saída */
    ofstream arq_resultado("Codificado", ios::out | ios::binary);
    if(!arq_resultado){
    	puts("Erro ao criar arquivo de saída!");
    	exit(1);
    }


    unsigned char crctr, memoria;
    int bit = 0;   

    for(int i = 0; i < arvore->frequencia_o.size(); i++){
        int j = arvore->frequencia_o[i];
        arq_resultado.write((char*)&j,sizeof(j));
    }
   
    while(arq >> noskipws >> crctr){
        string s = codigosbit[crctr];
        for(char& crctr : s){
            int i = crctr - '0';    
            if(i == 1)
                memoria |= (1<<bit);
            bit++;
            if(bit == 8){
                arq_resultado.put(memoria);
                bit = 0;
                memoria = 0;
            }          
        }
    }
    if(bit != 0)
        arq_resultado.put(memoria);
}

void decodificar(string dir, Arvore* arvore){
	/* Lê o arquivo de entrada */
    ifstream arq(dir, ios::in | ios::binary);
    if(!arq){
    	puts("Erro ao abrir arquivo de entrada!");
    	exit(1);
    }
 

    int j;
    for(int i = 0; i < arvore->frequencia_o.size(); i++){        
        arq.read(reinterpret_cast<char*>(&j), sizeof(j));        
    }
  	/* Cria o arquivo de saída */
    ofstream arq_resultado("Decodificado");
    if(!arq_resultado){
    	puts("Erro ao criar arquivo de saída!");
    	exit(1);
    }
    
    char c;
    while(arq.get(c)){
        for(int i = 0; i <= 7; i++){
            if(arvore->arvore_raiz->filho_esquerdo == nullptr){      
                arq_resultado << arvore->arvore_raiz->caractere;                
                arvore->frequencia_geral--;              
            }

            if(arvore->frequencia_geral == 0) break;           
            if((1 << i) & c)          
                arvore->arvore_raiz = arvore->arvore_raiz->filho_direito;
            else           
                arvore->arvore_raiz = arvore->arvore_raiz->filho_esquerdo;
        }
    }
}