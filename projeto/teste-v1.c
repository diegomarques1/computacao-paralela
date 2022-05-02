// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Computação Paralela - Projeto - 05D

#include <stdio.h>
#include <time.h>

// A biblioteca time.h foi incluída para
// calcularmos o tempo de execução do programa.
// Referência: http://wurthmann.blogspot.com/2015/04/medir-tempo-de-execucao-em-c.html

// Cálculo da série de Taylor iterativamente.
// A função incrementa o valor de i de 1..t
// para calcular a soma de 1/1 até 1/t

double iSerieTaylor(int t)
{
  double soma = 0;
  for (double i = 1; i <= t; i++)
    {
      soma += 1/i;
    }
  return soma;
}

int main() 
{
  clock_t tempo;
  tempo = clock();
  double soma = iSerieTaylor(10); // substituir o 10 pelo valor a ser testado
  printf("Soma = %f\n", soma);
  tempo = clock() - tempo;
  printf("Tempo de execução: %lfms\n", ((double)tempo)/((CLOCKS_PER_SEC/1000)));
  return 0;
}
