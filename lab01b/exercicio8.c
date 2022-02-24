// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 08

#include <stdio.h>
#include <stdlib.h>

void transpoeMatriz(int **transposta, int **matriz, int m, int n)
  {
  for (int linha = 0; linha < m; linha++)
    {
      for (int coluna = 0; coluna < n; coluna++)
        {
          transposta[coluna][linha] = matriz[linha][coluna];
        }
    }
  }

void preencheMatriz(int **matriz, int m, int n)
{
  for (int linha = 0; linha < m; linha++)
  {
    for (int coluna = 0; coluna < n; coluna++)
      {
        printf("A[%i][%i]: ", linha + 1, coluna + 1);
        scanf("%i", &matriz[linha][coluna]);
      }
  }
}

void imprimeMatriz(int **matriz, int m, int n)
{
  for (int k = 0; k < m; k++)
    {
      for (int l = 0; l < n; l++)
        {
          printf("%i ", matriz[k][l]);
        }
      printf("%c", '\n');
    }
}

int main() 
{
  int m, n, **matriz, **transposta;
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
  transposta = (int**) malloc (n * sizeof(int*));
  for (int col = 0; col < n; col++)
    {
      transposta[col] = (int*) malloc(sizeof(int));
    }
  
  preencheMatriz(matriz, m, n);
  printf("Matriz normal: \n");
  imprimeMatriz(matriz, m, n);
  transpoeMatriz(transposta, matriz, m, n);
  printf("Matriz transposta: \n");
  imprimeMatriz(transposta, n, m);
  
  // desalocar memória
  for (int col = 0; col < n; col++)
  {
    free(matriz[col]);
  }
  free(matriz);
  for (int col = 0; col < m; col++)
    {
      free(transposta[col]);
    }
  free(transposta);
  return 0;
}