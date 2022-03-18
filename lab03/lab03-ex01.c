// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab03 - Structs e arquivos

// Fontes extras consultadas
// https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
// https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/
// https://www.delftstack.com/pt/howto/c/feof-stdin-in-c/
// https://www.youtube.com/watch?v=HtvfgqO0IM4

#include <stdio.h>
#include <stdlib.h>

struct PESSOA
{
  char nome[20];
  int idade;
  float altura;
};

// implementação da função cmp para referência ao qsort
// ordem crescente de altura
int cmp (const void * a, const void * b)
{
  if ((*(struct PESSOA*)a).altura == (*(struct PESSOA*)b).altura)
    return 0; // são iguais
  else
    if ((*(struct PESSOA*)a).altura < (*(struct PESSOA*)b).altura) return -1; // antes
    else return 1; // depois
}

int main()
{
  char nome_arq[50];
  struct PESSOA Povo[10], P; // arquivo inicial deve ter 10 nomes
  FILE *Arq; 
  int i = 0, count = 10;
  
  printf("Digite o nome do arquivo .txt de entrada: "); // 'entrada.txt' ou qualquer alteração feita
  scanf("%s", nome_arq);
  Arq = fopen(nome_arq, "r"); // abre o arquivo para leitura (r)
  if (Arq == NULL) // tratamento de erro
  {
    printf("Erro na abertura do arquivo");
    return 0;
  }
  while (!feof(Arq)) // enquanto não chegar ao final do arquivo
  {
    fscanf(Arq, "%s", P.nome);
    fscanf(Arq, "%d", &P.idade);
    fscanf(Arq, "%f", &P.altura);    
    Povo[i++] = P;
  }

  fclose(Arq); // fecha o arquivo
  i = 0;

  printf("Imprimindo o vetor de pessoas não-ordenado: \n\n");
  for (i = 0; i < count; i++)
    {
      printf("Nome: %s\n", Povo[i].nome);
      printf("Idade: %d\n", Povo[i].idade);
      printf("Altura: %.2f\n\n", Povo[i].altura);
    }
  
  // ordena o vetor em função da altura crescentemente
  qsort(Povo, count, sizeof(struct PESSOA), cmp); 

  printf("Imprimindo o vetor de pessoas ordenado pela altura: \n\n");
  for (i = 0; i < count; i++)
    {
      printf("Nome: %s\n", Povo[i].nome);
      printf("Idade: %d\n", Povo[i].idade);
      printf("Altura: %.2f\n\n", Povo[i].altura);
    }
  
  // gerar novo arquivo com os dados ordenados

  Arq = fopen("saida.txt", "w"); // abre ou cria arquivo saida.txt
  for (i = 0; i < count; i++)
    {
      fprintf(Arq, "Nome: %s\nIdade: %d\nAltura: %.2f\n\n", Povo[i].nome, Povo[i].idade, Povo[i].altura);
    }
  fclose(Arq); // fecha o arquivo
  
  return 0;

}
