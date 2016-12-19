#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int id;
	id = fork();
	if (id!=0){
	printf("Eu sou o pai e espero  pelo meu filho %d. \n", id);
	wait(0);
	printf("Meu filho acabou de terminar .... vou termina tambem!\n");
	}else{
	printf("Eu sou o filho %d e espero 10 segundos .\n", getpid());
	sleep(10);
	printf("Ja esperei e vou embora... \n");
	}
}
