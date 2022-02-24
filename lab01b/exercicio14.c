// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab01b - Exercício 14

#include <stdio.h>

void insereChar(char Str[100], char c, int pos)
{
  char temp;
  // mover os subsequentes para à esquerda
  for (int i = pos + 1; i < 100; i++) 
    {
      temp = Str[i];
      Str[i] = c;
      c = temp;
    }
}

int main()
{
  char Str[100], carac; // máximo da string = 100
  int index;
  printf("\nDigite uma string sem espaços de até 100 caracteres: ");
  scanf("%s", Str);
  printf("Digite a posição (índice) no qual o caractere deve ser inserido: ");
  scanf("%d", &index);
  printf("Digite o caractere a ser inserido: ");
  scanf("\n%c", &carac);
  insereChar(Str, carac, index);
  printf("String atualizada após a inserção:\n%s\n", Str);
  return 0;
}
