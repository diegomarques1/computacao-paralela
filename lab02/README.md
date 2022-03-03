Laboratório 02 - Computação Paralela - 05D11

Para executar e compilar os arquivos em .c existentes nesse diretório, existem diversos processos possíveis.
No curso, o objetivo será compilar por meio do GCC em um Linux.

### - Compilando no terminal - Linux

- Para esse método, é preciso ter instalado o Git e o GCC no seu computador (comando -> sudo apt install ..., sendo ... git ou gcc).
- Caso queira, clonar o repositório atual do github em um certo diretório de sua máquina.
- Se esse for o caso, é possível usar o comando git clone https://github.com/diegomarques1/computacao-paralela.
- De qualquer modo, após ter o arquivo baixado (seja pela sincronização ou por outra maneira), abrir o terminal na pasta em que este se encontra.
- Em seguida, utilizar os comandos:

-> gcc nomedoarquivo.c -o nomequalquer

-> ./nomequalquer

- Por fim, é possível executar o programa.
- Logo abaixo, nesse arquivo README.md, estará um print com alguns exemplos de execução do exercício proposto para o laboratório.
- Observação: todas as execuções foram realizadas no computador do Diego, visto que já conseguiu instalar o Linux dual boot.

- lab02-ex01.c

![Screenshot](/lab02/print-execucao-ex01.png?raw=true)

- Acima, fizemos os testes com os fatoriais de 1 a 6.
- Para esse exercício, nós pensamos em criar um processo para cada iteração do fatorial.
- Cada processo filho é criado no laço por meio do comando fork().
- O fatorial é calculado normalmente, sendo exibido apenas pelo último processo. Isso porque o último processo filho é o único que vai ter childpid = 0, pois os outros pais acabam tendo como childpid o ID do filho criado, enquanto o último processo não teve filho algum por sair do laço for.
- A chamada wait foi utilizada por meio do material para consulta fornecido.
- O fatorial foi calculado em cima do valor de 'i', que é atribuído antes do fork() para que o valor seja atualizado para cada processo filho.
