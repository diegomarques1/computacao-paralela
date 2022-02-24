// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 03

#include <stdio.h>

void preencheVetor(int tamanho, int vet[])
{
  for (int i = 0; i < tamanho; i++)
    {
      vet[i] = i + 1;
    }
}

void imprimeVetor(int esq, int dir, int vet[])
{
  for (int i = esq; i < dir; i++)
    {
      printf("%d ", vet[i]);
    }
  printf("%c", '\n');
}

void imprimeEspaco(int esq)
{
  if (esq != 0)
  {
    for (int i = 0; i < esq; i++)
    {
      printf("  ");
    }
  }
}

void piramide(int tamanho, int vet[])
{
  int esq = 0, dir = tamanho;
  for (int i = 0; i < tamanho; i++)
    {
      imprimeEspaco(esq);
      imprimeVetor(esq, dir, vet);
      esq++;
      dir--;
    }
}

int main()
{
  int tam;
  printf("Digite o número máximo (ímpar): ");
  scanf("%i", &tam);
  while ((tam % 2) != 1)
    {
      printf("Número par -> inválido. Por favor, digite um número máximo ímpar: ");
      scanf("%i", &tam);
    }
  int vet[tam];
  preencheVetor(tam, vet);
  piramide(tam, vet);
  return 0;
}
