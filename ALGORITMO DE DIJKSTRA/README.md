# Implementação do Algoritmo de Dijkstra
    Esta implementação do algoritmo foi realizada em conjunto 
    com uma fila de prioridade mínima, utilizando a linguagem C++.

    @version 14/11/2019

# O Algoritmo de Dijkstra
        O Algoritmo de Dijkstra consiste em uma solução para o
    problema do caminho mínimo entre vértices de um grafo ponderado
    de única origem.
        É importante frisar que o este algoritmo não é o mais
     eficiente (pelo menos em tempo de execução) existente, sendo
     inferior ao de Algoritmo de Bellman-Ford, por exemplo.
    
    
# Detalhes de implementação do algoritmo
        O algoritmo de mantém dois elementos essenciais para a sua
    execução: um conjunto S, representando os vértices aos quais os
    pesos finais de caminho (distância) desde a origem já foram
    descobertos; uma fila de prioridade mínima Q de vértices, onde 
    os valores das chaves são a distância do vértice q até a origem.
    
        O algoritmo inicia da seguinte forma: dado um grafo g[V,E], 
    para cada vértice v pertencente a V[G], a distância de v até a 
    origem é igual a +infinito, e o conjunto de predecessores associados
    π[v] é nulo. Em seguida, atribui o valor de distância da origem u
    até ela mesma igual a zero (função initialize_single_source).
    
        Definição: relaxar uma aresta (u,v) se resume em analisar uma
    possível melhoria de caminho mais curto de u até v e, caso melhorado,
    atualizar d[v] e π[v](função relax).
    
        Após inicializar os vértices do grafo G, o algoritmo inicia o
    S como nulo e Q com os vértices de G. Em seguida, em um laço de
    repetição que executa enquanto Q não for nula, atribui a uma variável
    u o menor valor da fila (função heap_extract_min), adiciona u a S e
    relaxa as arestas entre u e cada vértice v adjacente a u (função dijkstra).

# Detalhes do programa criado
        O código recebe como entrada uma matriz triangular superior. Em
    seguida, espelha esta matriz de modo a se tornar uma matriz quadrada
    ([i,j]=[j,i]) de modo que esta matriz possa representar um grafo ponderado.
        Após isso, o programa executa as instruções que encontram o caminho
    mínimo de um vértice a até a origem. E, em seguida, gera um arquivo com
    os resultados encontrados.
    
# Referências
- Algoritmos: teoria e prática. TH Cormen, CE Leiserson, RL Rivest, C Stein. Editora Campus 2, 2002.

#   
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br
