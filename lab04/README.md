Laboratório 04 - Computação Paralela - 05D11

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
- Logo abaixo, nesse arquivo README.md, haverá o print da execução para o exercício proposto nesse laboratório.
- Observação: todas as execuções foram realizadas no computador do Diego, visto que já conseguiu instalar o Linux dual boot. 

- lab04-ex01.c

![Screenshot](/lab04/printscreen-execucao-lab04.png?raw=true)

- O objetivo do laboratório é aprender a mexer com memória compartilhada.
- Essa técnica de comunicação entre processos (IPC) pode ser feita por meio da função shmget().
- A execução do código se desenrola da seguinte maneira:
1) O processo pai solicita a criação de uma área de memória compartilhada por meio da função shmget()
2) O ID dessa área é obtido por meio dessa função e, em seguida, o processo pai se acopla à zona de memória
3) Essa alocação é feita por meio do método shmat()
4) Em seguida, o processo pai escreve na área de memória compartilhada, colocando no buffer o valor inicial da variável (1)
5) O comando fork() é utilizado para criar um processo filho
6) No filho, a mesma lógica de criação de área -> acoplamento do processo na área acontece
7) Porém, a área de memória compartilhada utilizada é a mesma do processo pai
8) Antes de finalizar, o filho modifica o conteúdo do buffer, somando 2 ao valor (1 + 2 = 3)
9) O processo pai estava aguardando a finalização do processo filho por meio do wait(NULL)
10) Enfim, o pai multiplica o conteúdo do buffer por 4 (3 x 4 = 12)
11) Por fim, há a destruição do segmento dessa área por meio da função shmctl()
