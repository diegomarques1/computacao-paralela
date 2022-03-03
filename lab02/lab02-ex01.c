// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Laboratório 02 - Ex. 01

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// pensamos em utilizar uma função para atualizar o valor de i 
// nos processos filhos, mas não foi necessário
// int fatorial(int i, int j) 
// {
//   i = i * j;
//   return i;
// }

int main(void)
{
  pid_t childpid = 0;
  int i, num, j;
  printf ("Enter the number: ");
  scanf ("%d", &num);
  j = num;
  for (i = 1; j > 1; j = j - 1)
  {
    i = i * j;
    if (childpid = fork()) // criação de 'num' filhos por meio do fork()
    {
      break;
    }
  }
  // único processo com childpid = 0 é o último, com o cálculo completo do fatorial
  if (childpid != 0) return 1; 
  else
  {
    wait(NULL); // chamada wait para esperar o processamento dos filhos
    printf("The factorial of %d is %d\n",num,i);
  }
}
