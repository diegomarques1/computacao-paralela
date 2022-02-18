// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 02

#include <stdio.h>

int main() 
{
  float N1, N2, N3, ME, MA;
  printf("Digite a nota tirada na N1: ");
  scanf("%f", &N1);
  printf("Digite a nota tirada na N2: ");
  scanf("%f", &N2);
  printf("Digite a nota tirada na N3: ");
  scanf("%f", &N3);
  printf("Digite a média tirada nos exercícios: ");
  scanf("%f", &ME);
  MA = (N1 + N2*2 + N3*3 + ME)/7;
  char nota;
  if (MA >= 9) nota = 'A';
  else if (MA >= 7.5) nota = 'B';
  else if (MA >= 6) nota = 'C';
  else if (MA >= 4) nota = 'D';
  else nota = 'E';
  printf("Nota: %c \n", nota);
}
