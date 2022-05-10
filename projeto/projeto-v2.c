// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Computação Paralela - Projeto - 05D - V2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct com parâmetros a serem informados para as threads

struct lista_par
{
  double inicio;
  double meio;
  double fim;
  double soma;
  long thread;
};

double ln = 1000;
int thread_count;

void *SerieTaylor(void* rank);

int main(int argc, char* argv[]) 
{
  struct lista_par* list = malloc (sizeof(struct lista_par));
  list->soma = 0;
  long thread = 0;
  pthread_t* thread_handles;

  // caso queira ter a quantidade em tempo de execução:
  // int thread_count = strtol(argv[1], NULL, 10); (mudanças serão necessárias)
  thread_count = 2;
  
  thread_handles = malloc (thread_count*sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++)
    {
      list->thread = thread;
      pthread_create(&thread_handles[thread], NULL, SerieTaylor, (void*) list);
    }

  for (thread = 0; thread < thread_count; thread++)
    {
      pthread_join(thread_handles[thread], NULL);
    }

  free(thread_handles);
  printf("ln(%d) = %f\n", (int) ln, list->soma);
  free(list);
  return 0;
}

// Função passada para pthread_create, que calcula a soma de 
// 1/1..1/500 em uma thread e de 1/501..1/1000 na outra.
// A função foi escrita de modo a utilizar apenas 2 threads

void *SerieTaylor(void* rank)
{
  struct lista_par *lista = (struct lista_par *) rank;
  
  if (lista->thread == 0)
  {
    lista->inicio = 1;
    lista->fim = ln/thread_count;
  }
  else if (lista->thread == 1)
  {
    lista->inicio = lista->fim + 1;
    lista->fim = ln;
  }
  
  double d;
  for (d = lista->inicio; d <= lista->fim; d++)
  {
    lista->soma += 1/d;
  }
  
  return NULL;
}
