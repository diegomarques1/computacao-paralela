// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 05

#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **matriz, int m, int n)
{
  printf("\nMatriz: \n");
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        {
          printf("%i ", matriz[i][j]);
        }
      printf("%c", '\n');
    }
}

int main() 
{
  int i, j, **matriz;
  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &i);
  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &j);
  matriz = (int**) malloc (i * sizeof(int*));
  for (int col = 0; col < i; col++)
    {
      matriz[col] = (int*) malloc(sizeof(int));
    }
  int m = 0, n = 0;
  while (m < i)
  {
    while (n < j)
    {
      printf("Digite o valor para A[%i][%i]: ", m+1, n+1);
      scanf("%i", &matriz[m][n]);
      n++;
    }
    n = 0;
    m++;
  }
  imprimeMatriz(matriz, i, j);
  int num;
  printf("\nDigite o número a multiplicar a linha 1 da matriz: ");
  scanf("%d", &num);
  // Multiplicar a linha 1 por um número
  for (int x = 0; x < j; x++)
    {
      matriz[0][x] = matriz[0][x]*num;
    }
  printf("Linha 1 resultante: ");
  for (int x = 0; x < j; x++)
    {
     printf("%d ", matriz[0][x]);
    }
  printf("\nLinha atualizada na matriz original!\n");
  imprimeMatriz(matriz, i, j);
  printf("\nDigite o número a multiplicar a coluna 1 da matriz: ");
  scanf("%d", &num);
  // Multiplicar a coluna 1 por um número
  for (int y = 0; y < i; y++)
    {
      matriz[y][0] = matriz[y][0]*num;
    }
  printf("Coluna 1 resultante: ");
  for (int y = 0; y < i; y++)
  {
    printf("%d ", matriz[y][0]);
  }
  printf("\nColuna atualizada na matriz original!\n");
  imprimeMatriz(matriz, i, j);
  for (int col = 0; col < n; col++)
  {
    free(matriz[col]);
  }
  free(matriz);
  return 0;
}
