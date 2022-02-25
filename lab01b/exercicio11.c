// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 11

#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **matriz, int m, int n)
{
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        {
          printf("%i ", matriz[i][j]);
        }
      printf("%c", '\n');
    }
}

void somaL1L2(int **matriz, int n)
{
  int coluna = 0;
  while (coluna < n)
    {
      matriz[1][coluna] = matriz[1][coluna] + matriz[0][coluna];
      coluna++;
    }
}

void multiplicaL1L2(int **matriz, int n)
{
  int coluna = 0;
  while (coluna < n)
    {
      matriz[1][coluna] = matriz[1][coluna] * matriz[0][coluna];
      coluna++;
    }
}

int main()
{
  int m, n, **matriz;
  printf("Digite o número de linhas da matriz: ");
  scanf("%i", &m);
  while (m < 0 || m < 2)
    {
      printf("Por favor, digite um número de linhas >= 2: ");
      scanf("%i", &m);
    }
  printf("Digite o número de colunas da matriz: ");
  scanf("%i", &n);
  while (n <= 0)
    {
      printf("Por favor, digite um número positivo de colunas: ");
      scanf("%i", &n);
    }
  // alocação dinâmica
  matriz = (int**) malloc (m * sizeof(int*));
  for (int col = 0; col < m; col++)
    {
      matriz[col] = (int*) malloc(sizeof(int));
    }
  
  // preenchimento da matriz
  for (int linha = 0; linha < m; linha++)
    {
      for (int coluna = 0; coluna < n; coluna++)
        {
          printf("A[%i][%i]: ", linha + 1, coluna + 1);
          scanf("%i", &matriz[linha][coluna]);
        }
    }
  
  printf("Matriz normal: \n");
  imprimeMatriz(matriz, m, n);

  printf("Matriz com L2 = L1 + L2: \n");
  somaL1L2(matriz, n);
  imprimeMatriz(matriz, m, n);

  printf("Matriz com L2 = L1 * L2: \n");
  multiplicaL1L2(matriz, n);
  imprimeMatriz(matriz, m, n);
  
  // desalocar a memória
  for (int col = 0; col < n; col++)
  {
    free(matriz[col]);
  }
  free(matriz);
  return 0;
}
