// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 04

#include <stdio.h>

int main()
{
  char string1[50], string2[50];
  printf("Digite o primeiro nome: ");
  scanf("%s", string1);
  printf("Digite o segundo nome: ");
  scanf("%s", string2);
  int count1 = 0, count2 = 0;
  while (count1 == count2)
    {
      if (string1[count1] < string2[count2])
      {
        count1 = -1;
      }
      else if (string1[count1] > string2[count2])
      {
        count2 = -1;
      }
      else
      {
        count1++;
        count2++;
      }
      
    }
  printf("Ordem alfabética: \n");
  if (count1 == -1)
  {
    printf("%s\n%s\n", string1, string2);
  }
  else if (count2 == -1) printf("%s\n%s\n", string2, string1);
  return 0;
}