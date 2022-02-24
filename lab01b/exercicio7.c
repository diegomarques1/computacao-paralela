// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 07

#include <stdio.h>

struct Pessoa
{
  char nome[20];
  int idade;
  float peso;
  float altura;
};

void print(struct Pessoa p)
{
  printf("\nNome: %s", p.nome);
  printf("\nIdade: %d anos", p.idade);
  printf("\nPeso: %.2fKg", p.peso);
  printf("\nAltura: %.2fm", p.altura);
}

int main() 
{
  int n = 3, i = 0;
  struct Pessoa pVet[n], p1, p2, p3;
  printf("\nDigite o nome da pessoa %d: ", i + 1);
  scanf("%s", p1.nome);
  // Dados aleatórios
  p1.idade = 20;
  p1.peso = 68.5;
  p1.altura = 1.74;
  pVet[i++] = p1;
  
  printf("\nDigite o nome da pessoa %d: ", i + 1);
  scanf("%s", p2.nome);
  // Dados aleatórios
  p2.idade = 49;
  p2.peso = 75.2;
  p2.altura = 1.91;
  pVet[i++] = p2;
  
  printf("\nDigite o nome da pessoa %d: ", i + 1);
  scanf("%s", p3.nome);
  // Dados aleatórios
  p3.idade = 32;
  p3.peso = 52.3;
  p3.altura = 1.59;
  pVet[i++] = p3;

  printf("\n- Informações disponíveis: \n");
  int temp = 0;
  while (i != 0)
    {
      print(pVet[temp]);
      temp++;
      i--;
      printf("%c", '\n');
    }
  return 0;
}
