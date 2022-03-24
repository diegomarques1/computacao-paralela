// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964
// Lab04 - Exercício 01 - Memória compartilhada

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ADDKEY 123

int main() 
{
	int shmid; /* identificador da memória comum */
	int size = 1024; 
	char *path="./lab04-ex01.c";
	pid_t pid;
	int flag = 0;
	int var_comp = 1;
	int *mem;
	
	// criação da área de memória compartilhada
	if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1) {
		perror("Erro no shmget");
		exit(1);
	}
	
	/* acoplamento do processo pai à zona de memória */
	mem = shmat(shmid, 0, flag);
	 
	/* escrita na zona de memória compartilhada */
	*mem = var_comp;
	printf("Valor incial da variável - no pai: %d\n", *mem);
	
	
	pid = fork();
	if (pid < 0) {
	   printf("* fork error (server) *\n");
	   exit(1);
	}
	else if (pid == 0) { // processo filho
	   
	   // criação da área para o processo filho
	   if (( shmid = shmget(ftok(path,ADDKEY), size, 0)) == -1) {
		perror("Erro no shmget");
		exit(1);
	   }
	   
	   /* acoplamento do processo filho à zona de memória */
	   mem = shmat(shmid, 0, flag);
	   
	   /* escrita na zona de memória compartilhada */
	   *mem = *mem + 2;
	   printf("Valor somado a 2 - no filho: %d\n", *mem);
	   exit(0); // finaliza o processo filho
	}
	
	wait(NULL); // aguarda o processo filho terminar
	*mem = *mem * 4;
	printf("Valor final da variável (multiplicado por 4) - no pai: %d\n", *mem);
	
	// destruição do segmento
	if ((shmctl(shmid, IPC_RMID, NULL)) == -1){ 
	   perror("Erro shmctl()");
	   exit(1); 
	}
	exit(0);
	
}

