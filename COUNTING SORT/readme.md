# Implementação do Algoritmo Counting Sort
    Esta implementação do algoritmo foi realizada utilizando a linguagem C++.

    @version 04/03/2020

# Algoritmo Counting Sort
   O Counting Sort é um algoritmo que, dado um arranjo A, reorganiza-o através de uma contagem de repetição dos elementos do arranjo e modificando suas posições.

# Detalhes de implementação do algoritmo
   O algoritmo recebe como parâmetro um vetor de inteiros desordenado e aplica a função counting_sort. Primeiro, na função, declara-se uma variável para alocar o maior elemento do vetor de entrada. Em seguida, cria-se dois vetores, um vetor denominado contador, com a quantidade de elementos do vetor de entrada+1 iniciados em 0, e um vetor resultado, com a mesma quantidade de elementos do vetor de entrada. Em seguida, em laço, conta quantas vezes os elementos aparecem no vetor de entrada, utilizando os elementos deste como índice do vetor contador a ser incrementado. Após isso, também em laço, soma os elementos do vetor dois a dois, aplicando cada resultado no segundo elemento da soma (Ex. soma o valor do índice 0 com o 1 e atribui ao índice 1 o resultado). Por fim, também em laço, atribui ao índice (vetor contador[vetor de entrada]-1) do vetor resultado o valor do índice do vetor de entrada.
 
# Detalhes do programa criado
   O programa requere como entrada um arquivo instância, que representa um vetor com n elementos inteiros. Em seguida, aloca os valores do arquivo em um vetor e aplica o algoritmo Counting Sort sobre ele.

# PSEUDO-CÓDIGO

   MAIOR → 0

   PARA CADA i ← ATÉ TAMANHO[VETOR]
      SE VETOR[i] > MAIOR
         MAIOR = VETOR[i]

   VETOR COUNTER(TAMANHO[VETOR+1]) INICIADO COM 0
   VETOR RESULT(TAMANHO[VETOR])

   PARA CADA i (INICIADO EM 0) ← ATÉ TAMANHO[VETOR]
      COUNTER[VETOR[i]] += 1

   PARA CADA i (INICIADO EM 1) ← ATÉ TAMANHO[VETOR]
      COUNTER[i] = COUNTER[i-1] + COUNTER[i]

      PARA CADA i (INICIADO EM 0) ← ATÉ TAMANHO[VETOR]
   RESULT[COUNT[VETOR[i]]--] = VETOR[i]

# Referências
https://pt.wikipedia.org/wiki/Counting_sort
https://www.youtube.com/watch?v=_q0OOXo4l7E


#
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br






