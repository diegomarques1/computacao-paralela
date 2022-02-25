// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 10

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

void multiplicaLinha(int **matriz, int col, int num)
{
  for (int x = 0; x < col; x++)
  {
    matriz[0][x] = matriz[0][x]*num;
  }
  printf("Linha 1 resultante: ");
  for (int x = 0; x < col; x++)
    {
     printf("%d ", matriz[0][x]);
    }
}

void multiplicaColuna(int **matriz, int row, int num)
{
  for (int y = 0; y < row; y++)
  {
    matriz[y][0] = matriz[y][0]*num;
  }
  printf("Coluna 1 resultante: ");
  for (int y = 0; y < row; y++)
  {
    printf("%d ", matriz[y][0]);
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
      printf("A[%i][%i]: ", m+1, n+1);
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
  multiplicaLinha(matriz, j, num);
  printf("\nLinha atualizada na matriz original!\n");
  imprimeMatriz(matriz, i, j);
  
  printf("\nDigite o número a multiplicar a coluna 1 da matriz: ");
  scanf("%d", &num);
  multiplicaColuna(matriz, i, num);
  printf("\nColuna atualizada na matriz original!\n");
  imprimeMatriz(matriz, i, j);
  
  for (int col = 0; col < n; col++)
  {
    free(matriz[col]);
  }
  free(matriz);
  return 0;
}
