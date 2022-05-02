# Projeto - Computação Paralela - 05D11

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

- Para a v1, não é preciso digitar qualquer valor de entrada após ./nomequalquer.
- Por fim, é possível executar o programa.

### - Considerações sobre o projeto

- Linguagem escolhida: C (vide orientações para o compilador GCC).
- Ambiente de execução: máquina do Diego, tendo em vista maior disponibilidade de tempo de execução.
- Neste diretório 'projeto', teremos uma parte reservada para armazenar printscreens de execução.
- Também deixaremos um arquivo .txt com anotações sobre testes realizados: log.txt
- Este arquivo foi feito baseado na utilização da biblioteca time.h no código para cada versão e estará disponível no repositório.
- Além disso, colocaremos as versões atualizadas do código-fonte conforme as semanas forem passando. Como desejamos ter um registro evidente das versões, deixaremos cada versão (v1..vn) no repositório.
- Logo abaixo, neste arquivo README.md, estarão registradas decisões tomadas durante o projeto, com prints evidenciando testes realizados, melhorias, hipótestes, etc.
- O arquivo README.md será atualizado a partir das novas versões do projeto. Na teoria, espera-se que haverão atualizações a cada semana - de acordo com as atividades de laboratório.

02/05/2022: v1

-> Construção da versão 1 (v1) + grafo de dependências (DAG).

### Código - v1

- Inicialmente, ficamos em dúvida entre fazer uma função recursiva ou uma função iterativa para resolver o problema da soma infinitesimal.
- Ao pesquisar sobre na Internet, vimos respostas bem contrapostas. Enfim, entendemos que a velocidade entre recursão e iteração depende do caso e do problema a ser resolvido, obviamente.
- Logo, fizemos ambas as funções e testamos alguns valores de entrada. Segue abaixo um print de ambas as funções pensadas:

![Screenshot](?raw=true)

- Testamos com algumas entradas e, para o valor 1000000, a versão recursiva deu erro de segmentação, enquanto a versão iterativa conseguiu ser executada. Seguem prints de exemplos abaixo:

-> Teste com 100 e 10000, respectivamente:

![Screenshot](?raw=true)

-> Teste com 2 e 50000, respectivamente:

![Screenshot](?raw=true)

-> Teste com 1000000 (erro para versão recursiva):

![Screenshot](?raw=true)

- Sendo assim, decidimos criar a versão inicial (v1) a partir da função iterativa. 
- Também é importante ter em mente que a v1 não tem qualquer aplicação de paralelismo por nossa parte, sendo um programa serial para resolver o problema inicialmente.
- Neste diretório, o arquivo da versão 1 pode ser consultado: projeto-v1.c
- Segue abaixo print com a execução do que foi solicitado na atividade: ln(10)

![Screenshot](?raw=true)

### Grafo de dependências - DAG

- Por ser um programa serial, acreditamos que o grafo é bem direto, sem qualquer paralelismo e com dependência entre os resultados das iterações.
- Por exemplo: para calcular ln(10), precisamos ter calculado ln(9), que também precisa de ln(8), e assim por diante - considerando que ln(10) é uma soma infinitesimal.
- Segue abaixo o DAG construído:

![Screenshot](?raw=true)

