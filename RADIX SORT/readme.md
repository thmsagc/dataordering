# Implementação do Algoritmo Radix Sort
    Esta implementação do algoritmo foi realizada utilizando a linguagem C++.

    @version 05/03/2020

# Algoritmo Radix Sort
   O Radix Sort é um algoritmo que, dado um arranjo A, reorganiza-o aplicando um algoritmo de sort (qualquer) em cada classe dos números (unidade, dezena, etc). 

# Detalhes de implementação do algoritmo
   O algoritmo recebe como parâmetro um vetor de inteiros desordenado e verifica qual o maior elemento do arranjo. Após isso, aplica um algoritmo de sort (foi escolhido o Counting Sort) em cada uma das classes dos números, através de uma operação que capte cada o resto da divisão de cada elemento por sua base.
 
# Detalhes do programa criado
   O programa requere como entrada um arquivo instância, que representa um vetor com n elementos inteiros. Em seguida, aloca os valores do arquivo em um vetor e aplica o algoritmo Radix Sort sobre ele.

# PSEUDO-CÓDIGO

COUNTING_SORT(VETOR, BASE)

      VETOR COUNTER(10]) INICIADO COM 0  
      
      VETOR RESULT(TAMANHO[VETOR])    
     
      PARA CADA i (INICIADO EM 0) ← ATÉ TAMANHO[VETOR] 
         
         COUNTER[VETOR[i]] += 1   
         
      PARA CADA i (INICIADO EM 1) ← ATÉ TAMANHO[VETOR] 
      
         COUNTER[i] = COUNTER[i-1] + COUNTER[i] 
      PARA CADA i (INICIADO EM 0) ← ATÉ TAMANHO[VETOR] 
      
         RESULT[COUNT[VETOR[i]]--] = VETOR[i] 
RADIX_SORT(VETOR) 

      MAIOR → VETOR->MAIOR 
      
      PARA CADA BASE (INICIADO EM 1) ← ENQUANTO MAIOR/BASE > 0 ← BASE*10 
      
         COUNTING_SORT(VETOR, BASE) 

# Referências
https://www.geeksforgeeks.org/radix-sort/


#
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br






