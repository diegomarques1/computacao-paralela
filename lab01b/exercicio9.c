// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 09

#include <stdio.h>
#include <stdlib.h>

#define modulo(x) (x > 0) ? x : -x;

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

void trocaModulo(int **matriz, int m, int n)
{
  for (int linha = 0; linha < m; linha++)
  {
    for (int coluna = 0; coluna < n; coluna++)
    {
      matriz[linha][coluna] = modulo(matriz[linha][coluna]);
    }
  }
}

int main()
{
  int m, n, **matriz;
  printf("Digite o número de linhas da matriz: ");
  scanf("%i", &m);
  printf("Digite o número de colunas da matriz: ");
  scanf("%i", &n);
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
  trocaModulo(matriz, m, n);
  printf("Matriz alterada: \n");
  imprimeMatriz(matriz, m, n);
  
  // desalocar a memória
  for (int col = 0; col < n; col++)
  {
    free(matriz[col]);
  }
  free(matriz);
  return 0;
}
