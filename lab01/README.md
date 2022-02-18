Laboratório 01 - Computação Paralela - 05D11

A aplicação desse laboratório é simples. Portanto, utilizar qualquer compilador online pode servir.
De qualquer modo, para executar e compilar o código 'lab01.c', existem diversos processos possíveis.

### 1 - Usando o site 'ideone': https://ideone.com/

Esse site não precisa de licença nem de conta, e é um compilador online com diversas linguagens disponíveis.

Orientações:

- Tentar, antes de tudo, entrar no link a seguir: https://ideone.com/FNY4yP
- Caso consiga, é possível enxergar uma tela contendo tanto o código em C quanto o output para tal:

![image](https://user-images.githubusercontent.com/64621051/154623028-7a12b2d8-a792-4182-9047-e12c5550ffc7.png)

- Nesse caso, não é preciso rodar a aplicação, pois a execução foi automática e seu output já está sendo mostrado. 
- Mesmo assim, caso deseje rodar ou fazer alterações, clicar em 'fork' para ter o código disponibilizado.
- Para rodar a aplicação, basta clicar em 'run'.

Caso não consiga acessar o link, é possível realizar o processo manualmente:

1) Abrir o site pelo link https://ideone.com/;
2) Escolher a linguagem C para o programa;
3) Copiar o código contido no arquivo 'lab01.c' no diretório lab01 e colar no espaço disponível; (como abaixo)

![image](https://user-images.githubusercontent.com/64621051/154622608-3750a186-2756-4fb7-91e1-462e6d039d08.png)

4) Clicar em 'run' para executar o código;
5) Assim, é possível observar o output, como foi mostrado na primeira imagem.

### 2 - Compilando no terminal - Linux

- Para esse método, é preciso ter instalado o Git e o GCC no seu computador (comando -> sudo apt install ..., sendo ... git ou gcc).
- Caso queira, clonar o repositório atual do github em um certo diretório de sua máquina.
- Se esse for o caso, utilizar o comando 'git remote add origin' ou 'git remote add github' + o link para o repositório atual.
- De qualquer modo, após ter o arquivo baixado (seja pela sincronização ou por outra maneira), abrir o terminal na pasta em que este se encontra.
- Em seguida, utilizar os comandos: 
-> gcc nomedoarquivo.c -o nomedoarquivo
-> ./nomedoarquivo

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/lab01/Execu%C3%A7%C3%A3o%20-%20Lab01a.png)
