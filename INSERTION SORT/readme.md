# Implementação do Algoritmo Insertion Sort
    Esta implementação do algoritmo foi realizada utilizando a linguagem C++.

    @version 11/02/2020   
        
 # Algoritmo Insertion Sort
   O Insertion Sort é um algoritmo que, dado um arranjo A, constrói uma reorganização deste atravez da reinsersão dos elementos do arranjo, uma a uma.
   
 # Detalhes de implementação do algoritmo
   O algoritmo recebe como parâmetro um vetor de inteiros desordenado.
   Em loop iniciado em 1(não em 0) e terminado no número de elementos do vetor (vetor.size()), atribui o valor do vetor no índice i a uma váriável(atual), e guarda o índice i-1(anterior). Logo após, em loop, avalia as condicionais: anterior >= 0 e vetor[anterior] > atual. Caso as condicionais retornem verdadeiro, atribui a v[anterior+1](o que seria o atual) v[anterior], e decrementa o valor do índice anterior. Depois, atribui a v[anterior+1] o valor atual.
  Assim, o algoritmo troca os valores do vetor em cada
passagem do primeiro loop no segundo loop (no escopo do primeiro), de modo que os elementos fiquem ordenados. 

 # Detalhes do programa criado
   O programa requere como entrada um arquivo instância, que representa um vetor com n elementos inteiros. Em seguida, aloca os valores do arquivo em um vetor e aplica o algoritmo Insertion Sort.    
   
# Referência
https://pt.wikipedia.org/wiki/Insertion_sort


#   
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br
