Laboratório 03 - Computação Paralela - 05D11

Para executar e compilar os arquivos .c existentes nesse diretório, temos diversos processos possíveis.
Porém, no curso, a ideia é compilar os arquivos por meio do GCC e em um sistema Linux.

### - Compilando no terminal - Linux

- Para esse método, é preciso ter instalado o Git e o GCC no seu computador (comando -> sudo apt install ..., sendo ... git ou gcc).
- Caso queira, clonar o repositório atual do github em um certo diretório de sua máquina.
- Se esse for o caso, é possível usar o comando git clone https://github.com/diegomarques1/computacao-paralela.
- De qualquer modo, após ter o arquivo baixado (seja pela sincronização ou por outra maneira), abrir o terminal na pasta em que este se encontra.
- Em seguida, utilizar os comandos:

-> gcc nomedoarquivo.c -o nomequalquer

-> ./nomequalquer

- Por fim, é possível executar o programa.
- Logo abaixo, nesse arquivo README.md, estarão prints com a execução do exercício proposto para este laboratório.
- Observação: todas as execuções foram realizadas no computador do Diego, visto que já conseguiu instalar o Linux dual boot. 

- lab03-ex01.c

![Screenshot](/lab03/print-execucao-01-ex03.png?raw=true)

- Execução 01 - Impressão do vetor não-ordenado

![Screenshot](/lab03/print-execucao-02-ex03.png?raw=true)

- Execução 02 - Impressão do vetor ordenado por altura

- A lógica do programa é a seguinte:
- 
-> Utiliza-se a função fopen para abrir o arquivo em questão (entrada.txt);

-> Utilizando um while até o EOF (final do arquivo), cada linha é atribuída a um atributo de uma struct;

-> Essa struct PESSOA armazena o nome, a idade e a altura de cada pessoa descrita no arquivo de entrada;

-> Cada pessoa é armazenada em um vetor e esse vetor é ordenado pela altura por meio da função qsort();

-> A função qsort() ordena o vetor de pessoas 'Povo', que tem 10 elementos, a partir da função cmp();

-> A função cmp foi implementada no programa de acordo com a lógica vista na documentação;

-> Essa função compara ambas as alturas e retorna algum valor inteiro que indica como ordenar a partir do Quicksort;

-> Por fim, o vetor é ordenado e colocado em um outro arquivo chamado saida.txt (se não existir, cria um arquivo com tal nome).

-> O programa também imprime na tela o vetor antes e depois da ordenação.
