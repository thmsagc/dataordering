# Introdução aos Heaps(binários)
        Um heap binário é um vetor de elementos que pode ser visto como uma árvore binária praticamente completa (pelo menos até o
    penúltimo nível), onde cada nó da árvore representa um elemento do vetor. Um heap binário H é possui dois atributos chave:
    comprimento[H], representando comprimento total do heap(número de elementos máximo); tamanho_do_heap[H], representando o número de
    elementos no heap. 
        Os nós da árvore que representa um heap binário segue uma estruturação particular deste tipo de objeto (heap) onde, dado um elemento A[i] da árvore A, o "pai" de A[i] é o elemento A[i/2], o "filho esquerdo" de A[i] é A[i*2] e o "filho direito" de A[i] é A[i*2+1].
        Os heaps binários podem ser mínimos ou máximos, possuindo propriedades individuais que os definem entre estes dois tipos. Um heap binário máximo é aquele onde os valores dos "pais" são sempre maiores do que os de seus filhos, sendo a raiz da árvore o nó de maior valor. Um heap binário mínimo é definido de maneira análoga ao máximo, a raiz é o elemento de menor valor, e os "pais" possuem valor menor que os de seus "filhos".
        Os heaps binários possuem sub-rotinas especiais que são utilizadas para a manutenção deste tipo de estrutura. Estas serão definidos mais a frente.
    - MAX_HEAPIFY(A, i)
        Entrada: A é o arranjo a ser processado, e i o nó alvo.
            É uma sub-rotina que garante a propriedade de heap máximo, trocando (se
        necessário) a posição de elementos da árvore.
            Para que esta rotina seja executada corretamente, devemos pressupor que
        os filhos deste nó i sejam ambos heaps máximo.
    - BUILD_MAX_HEAP(A)
        Entrada: A é o arranjo a ser processado.
            Basicamente esta sub-rotina executa o MAX_HEAPIFY de baixo para cima
        em um arranjo, com loop, e tem como saída um heap binário máximo.
        
 # Algoritmo Heapsort
        O algoritmo Heapsort tem como objetivo a ordenação dos elementos de um arranjo A. Ele começa transformando o arranjo A em um heap binário máximo. Em seguida, troca os elementos raiz e final de A (maior e menor valor respectivamente) e, logo após, decrementa o tamanho_do_heap, de modo que o maior valor do heap posteriormente se torne o primeiro elemento do arranjo A. 
        Como pode ser observado o menor valor de A se tornou a raiz do arranjo,quebrando a propriedade de heap máximo. Por este motivo, chama-se a sub-rotina MAX_HEAPIFY na raiz, transformando o arranjo A em um heap binário máximo novamente. Estse procedimentos em loop ordena todos os elementos de um arranjo, do maior para o menor.

# Algoritmo Heapsort
Algoritmos: teoria e prática. TH Cormen, CE Leiserson, RL Rivest, C Stein. Editora Campus 2, 2002.
    

    @version 28/01/2020

#   
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br
