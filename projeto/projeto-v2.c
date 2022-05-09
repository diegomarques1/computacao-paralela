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
  double fim;
  double soma;
};

int thread_count; 

void *SerieTaylor(void* rank);

int main(int argc, char* argv[]) 
{
  struct lista_par* list = malloc (sizeof(struct lista_par));
  list->soma = 0;
  list->inicio = 1;
  long thread;
  pthread_t* thread_handles;

  // caso queira ter a quantidade em tempo de execução:
  // thread_count = strtol(argv[1], NULL, 10); ao invés da linha abaixo
  thread_count = 2;
  list->fim = 1000/thread_count;
  thread_handles = malloc (thread_count*sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++)
    {
      pthread_create(&thread_handles[thread], NULL, SerieTaylor, (void*) list);
    }

  for (thread = 0; thread < thread_count; thread++)
    {
      pthread_join(thread_handles[thread], NULL);
    }

  free(thread_handles);
  printf("ln(1000) = %f\n", list->soma);
  free(list);
  return 0;
}

// Função passada para pthread_create, que calcula a soma de 
// 1/1..1/500 em uma thread e de 1/501..1/1000 na outra

void *SerieTaylor(void* rank)
{
  struct lista_par *lista = (struct lista_par *) rank;
  
  double d;
  for (d = lista->inicio; d <= lista->fim; d++)
  {
    lista->soma += 1/d;
  }
  
  lista->inicio = d;
  lista->fim += 500; // incremento para thread_count = 2;
  
  return NULL;
}
