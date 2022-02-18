// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA:
// Lab01b - Exercício 01

#include <stdio.h>

int main() 
{
  int tam;
  printf("Digite o tamanho da matriz quadrada: ");
  scanf("%i", &tam);
  int m = 0, n = 0;
  int mQuadrada[tam][tam],menor = mQuadrada[m][n], linhaMenor = m;
  while (m < tam)
  {
    while (n < tam)
    {
      printf("Digite o valor para A[%i][%i]: ", m+1, n+1);
      scanf("%i", &mQuadrada[m][n]);
      n++;
    }
    n = 0;
    m++;
  }
  m = 0, n = 0;
  while (m < tam)
    {
      while (n < tam)
        {
          if (mQuadrada[m][n] < menor)
          {
            menor = mQuadrada[m][n];
            linhaMenor = m;
          }
          n++;
        }
      n = 0;
      m++;
    }
  printf("A linha que contém o menor número da matriz é: %i", linhaMenor + 1);
  return 0;
}