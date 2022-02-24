// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 13

#include <stdio.h>

void removeChar(char Str[100], int pos)
{
  Str[pos] = ' '; // retirar o caractere
  for (int i = pos; i < 100; i++) // mover os subsequentes para à esquerda
    {
      Str[i] = Str[i + 1];
    }
}

int main()
{
  char Str[100]; // máximo da string = 100
  int index;
  printf("\nDigite uma string sem espaços de até 100 caracteres: ");
  scanf("%s", Str);
  printf("Digite a posição (índice) do caractere a ser removido: ");
  scanf("%d", &index);
  removeChar(Str, index);
  printf("String atualizada após a remoção:\n%s\n", Str);
  return 0;
}
