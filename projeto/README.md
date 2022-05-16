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
- Para a v2, o primeiro comando é gcc nomedoarquivo.c -o nomequalquer -lpthread
- Para a v2, não é preciso digitar qualquer valor de entrada após ./nomequalquer.
- Por fim, é possível executar o programa.

### - Considerações sobre o projeto

- Linguagem escolhida: C (vide orientações para o compilador GCC).
- Ambiente de execução: máquina do Diego, tendo em vista maior disponibilidade de tempo de execução.
- Neste diretório 'projeto', teremos uma parte reservada para armazenar printscreens de execução.
- Também deixaremos um arquivo .txt com anotações sobre testes realizados: log.txt
- Este arquivo foi feito baseado na utilização da biblioteca time.h no código para cada versão e estará disponível no repositório.
- Além disso, colocaremos as versões atualizadas do código-fonte conforme as semanas forem passando. Como desejamos ter um registro evidente das versões, deixaremos cada versão (v1..vn) no repositório.
- Logo abaixo, neste arquivo README.md, estarão registradas decisões tomadas durante o projeto, com prints evidenciando testes realizados, melhorias, hipóteses, etc.
- O arquivo README.md será atualizado a partir das novas versões do projeto. Na teoria, espera-se que haverão atualizações a cada semana - de acordo com as atividades de laboratório.

## 02/05/2022 - Versão 1

-> Construção da versão 1 (v1) + grafo de dependências (DAG).

### Código - v1

- Inicialmente, ficamos em dúvida entre fazer uma função recursiva ou uma função iterativa para resolver o problema da soma infinitesimal.
- Ao pesquisar sobre na Internet, vimos respostas bem contrapostas. Enfim, entendemos que a velocidade entre recursão e iteração depende do caso e do problema a ser resolvido, obviamente.
- Logo, fizemos ambas as funções e testamos alguns valores de entrada. Segue abaixo um print de ambas as funções pensadas:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v1/print-ideia-inicial.png?raw=true)

- Testamos com algumas entradas e, para o valor 1000000, a versão recursiva deu erro de segmentação, enquanto a versão iterativa conseguiu ser executada. Seguem prints de exemplos abaixo:

-> Teste com 100 e 10000, respectivamente:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v1/print-teste-01.png?raw=true)

-> Teste com 2 e 50000, respectivamente:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v1/print-teste-02.png?raw=true)

-> Teste com 1000000 (erro para versão recursiva):

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v1/print-teste-03.png?raw=true)

- Sendo assim, decidimos criar a versão inicial (v1) a partir da função iterativa. 
- Também é importante ter em mente que a v1 não tem qualquer aplicação de paralelismo por nossa parte, sendo um programa serial para resolver o problema inicialmente.
- Neste diretório, o arquivo da versão 1 pode ser consultado: projeto-v1.c
- A lógica implementada foi utilizar um laço para somar continuamente cada 1/i, de i = 1 até i = t.
- Segue abaixo print com a execução do que foi solicitado na atividade: ln(10)

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v1/print-execucao-ln10-v1.png?raw=true)

- Nesse caso, com a versão atual, o resultado obtido foi 2.928968.

### Grafo de dependências - DAG

- Por ser um programa serial, acreditamos que o grafo é bem direto, sem qualquer paralelismo e com dependência entre os resultados das iterações.
- Por exemplo: para calcular ln(10), precisamos ter calculado ln(9), que também precisa de ln(8), e assim por diante - considerando que ln(10) é uma soma infinitesimal.
- Segue abaixo o DAG construído:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/dag-grafo-v1.png?raw=true)

## 09/05/2022 - Versão 2

-> Construção da versão 2 para ln(1000) utilizando pthreads + comparação de speedup entre versão serial e paralela + atualização do log.txt

### Código - v2

- A primeira ideia foi criar uma thread para cada parte da soma. Ou seja, uma thread faria 1/1 e armazenaria, outra faria 1/2, outra faria 1/3, e por aí vai.
- Essa metodologia se mostrou inviável, com tempos maiores e maiores de execução, além de falha de segmentação com valor razoavelmente baixo.
- Logo, analogamente ao que foi visto em aula no laboratório 02 (dois pipes), pensamos em uma solução que utilizava duas threads.
- Ao testar soluções com menos threads, o tempo de execução diminuiu, então achamos que a interpretação é minimamente coerente.
- Definimos o número de threads dentro do arquivo - ao invés de utilizar o strtol e pegar o valor da linha de comando.
- Isso foi feito para garantir o funcionamento do programa. Por exemplo, se o usuário desejasse criar 7 threads, é provável que seria somado algum(ns) valor a mais ou a menos, porque 1000/7 não é um número inteiro.


- Outro ponto relevante é que, a partir desta versão, estaremos utilizando o comando 'time' do próprio Linux para medir tempo de execução.
- Motivo: biblioteca time.h, clock() -> chamadas bloqueantes, fazendo com que atividades em paralelo sejam forçadas a seguir um modelo serial.
- Um último fator a se mencionar é que, pelas threads serem chamadas não-bloqueantes, elas podem executar sem esperar o término das anteriores. 
- Dito isso, algumas situações foram comuns no desenvolvimento da v2, como essa, em uma das tentativas iniciais:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v2/print-thread-impacto.png?raw=true)

- Após a realização de alguns testes, foi possível perceber que, em alguns casos, principalmente para valores grandes, as threads acabavam sendo iniciadas praticamente ao mesmo tempo.
- Em outras palavras, de acordo com a nossa implementação inicial para essa v2, uma thread começava o cálculo de 1..500, e a outra começava ao mesmo tempo.
- Quando isso acontecia, as atualizações das variáveis de início e fim não eram computadas a tempo.
- Ou seja, o começo de ambas as threads era o mesmo, ou então o final, ou uma mistura de combinações que faziam o valor variar.
- Para resolver esse problema, como a v2 foi proposta por nós com a utilização de 2 threads, fizemos um if para diferenciar ambas as threads, e garantir a inicialização correta.
- Isso também foi importante para evitar a limitação do início de uma thread a partir do fim da outra (ficaria serial).


- Por fim, o arquivo log.txt foi atualizado com a nova medição de tempo de execução, tanto para v1 quanto v2.
- Abaixo, segue print comprovando a execução para ln(1000):

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v2/print-execucao-final-v2.png?raw=true)

- Outros exemplos, mudando manualmente o valor de ln dentro do código:

![Screenshot](https://github.com/diegomarques1/computacao-paralela/blob/main/projeto/prints/v2/print-exemplos-execucao-v2.png?raw=true)

- Observação: os resultados de ln() testados deram iguais ao da v1 (com mesma precisão). O tempo de execução também foi extremamente similar.

### Speedup - V2 - Atualizado em 16/05/2022

- No geral, considerando ln(x), o tempo de execução foi um pouco mais rápido para menores valores de x para a v1, e um pouco mais rápido para a v2 em valores maiores de x.
- Tendo isso em vista, os tempos foram extremamente parecidos entre as versões (v1 e v2).
- Qualquer teste realizado pode ser consultado no arquivo log.txt. Eles dão um comparativo interessante em relação ao tempo de execução.
- Cálculo de speedup considerando a lei de Amdahl, utilizada quando o tamanho do problema é fixo:

Sp = Ts/Tp (tempo serial / tempo paralelo)

- Comando utilizado: 'time' do próprio Linux. O resultado pode diferir um pouco em relação ao log da v1 em log.txt por conta disso.

-> Para ln(1000), temos:

Tempo serial ≃ 0,001s
Tempo paralelo ≃ 0,001s

Sp = 0,001/0,001 ≃ 1 
Speedup = 1 (sem ganho de speedup para valores pequenos)

-> Para ln(1000000000), temos:

Tempo serial ≃ 4,483s
Tempo paralelo ≃ 4,416s

Sp = 4,483/4,416 ≃ 1,0152
Speedup ≃ 1,0152

## 16/05/2022 - Versão 3
