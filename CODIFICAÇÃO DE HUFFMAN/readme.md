# Implementação do Algoritmo Heap Sort
    Esta implementação do algoritmo foi realizada utilizando a linguagem C++.

    @version 28/01/2020
    
# Introdução a Codificação de Huffman

   A codificação de Huffman é um famoso algoritmo criado para a compressão de dados. É muito importante para esta área da ciência da computação pois forma a base para os sistemas de compressão de dados.
   
   Normalmente um caractere qualquer é armazenado com espaço em memória de um byte. Este método de armazenamento é denominado fixed-length-encoding.
   
   A proposta da codificação de Huffman é utilizar um espaço de memória variável para alocação de caracteres, método denominado variable-length-encoding, explorando a circunstância de que geralmente um caractere x possui uma frequência maior de ocorrência que um outro caractere y.
   
   No fim, um caractere z pode chegar a ser representado com apenas 1 bit, outro k com 2 bits e assim sucessivamente.
   
   O grande desafio da codificação de Huffman está na decodificação, pois o método variable-length-encoding pode gerar ambiguidades nesta etapa do programa, problema este que será contornado com a regra do prefixo.

# Regra do prefixo
   Para introduzir e reforçar o problema da ambiguidade consideramos a cadeia de caracteres "aabacdab" que, utilizando o fixed-length-encoding, naturalmente requisita 8 bytes para ser armazenada. Nota-se que os caracteres a, b, c e d possuem frequência 4, 2, 1 e 1 respectivamente.
   
   Tentando representar a mesma cadeia em um número menor de bits, atribuimos arbitrariamente o código de bit 0 a 'a', o código de 2 bits '11' a 'b' e o código de 3 bits 100 e 011 a 'c' e 'd' respectivamente.
   
   Logo, a cadeia "aabacdab" será codificada para 00110100011011, que pode ser decodificada para:
      0 011 0 100 011 0 11
      0 0 11 0 100 0 11 011
      0 011 0 100 0 11 0 11
      ...
      
   Isto é uma ambiguidade que atrapalha o funcionamento do algoritmo.
   Para contornar este problema, utilizamos a regra do prefixo, que garantirá que resultará em códigos de bit únicos.
   
   A regra do prefixo afirma que nenhum código de bit é prefixo de outro.
   No exemplo acima, que gerou ambiguidade, temos que o código de bit 0 é prefixo do código de bit 011, indo do contra a regra do prefixo.
   
   Reorganizando os códigos de bit dos caracteres como 0 para a, 10 para b, 110 para c e 111 para d, temos um código único 00100100011010, que só pode ser decodificado para a cadeia inicial "aabacdab".

# Detalhes de implementação da Codificação de Huffman
  O algoritmo funciona com base em uma árvore binária onde, inicialmente, cada caractere é representado em uma folha da árvore. Em cada nó é contido o caractere, sua respectiva frequência de ocorrência e os ponteiros para os filhos esquerdo e direito deste nó.
  
  A estrutura da árvore deve ser vista como uma fila de prioridade mínima, na qual o nó com menor frequência recebe maior prioridade na fila.
  
# Codificação
   O algoritmo, após criar um nó para cada caractere e sua respectiva frequência, retira dois nós de prioridade mais alta da fila e, em seguida os coloca como filhos de um novo nó, que terá frequência a soma das frequências dos que foram retirados.
   
  Em seguida, adiciona este novo nó a fila de prioridades.
  
  Este algoritmo é executado em loop de modo que o nó restante seja um nó que será a raiz.
  
  Deste modo, o caminho da raiz para qualquer nó da folha é o código de bits de cada elemento, definido inicialmente.
   
# Decodificação
   A decodificação tem como base o fato de que caminho da raiz para qualquer nó da folha é o código de bits de cada elemento, definido inicialmente.

# Referência
https://en.wikipedia.org/wiki/Huffman_coding

https://en.wikipedia.org/wiki/Variable-length_code


#   
#### Thomás Augusto Gouveia Chaves - CI/UFPB
#### thomaschaves@cc.ci.ufpb.br
