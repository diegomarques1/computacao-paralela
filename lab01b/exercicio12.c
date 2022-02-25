// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 12

#include <stdio.h>

int posicaoCaractere(char str[], char c, int index)
{
  for (int i = 0; i < 50; i++)
  {
    if (str[i] == c)
    {
      index = i;
      break;
    }
  }
  return index;
}

int main()
{
  char str[50], carac; // máximo da string = 100
  int index = -1;
  printf("Deseja saber a posição da primeira ocorrência de qual caractere?\n");
  scanf("%c", &carac);
  printf("\nDigite uma string sem espaços de até 50 caracteres: ");
  scanf("%s", str);
  index = posicaoCaractere(str, carac, index);

  if (index == -1) printf("\nCaractere não encontrado na string.");
  else printf("\nCaractere encontrado! Índice da primeira ocorrência do caractere '%c': %d\n", carac, index);
  
  return 0;
}
