#include<stdio.h>
#include<unistd.h>
int main(){
	printf("\%d. <- Processo | Meu pai é o \%d. O ID  do meu grupo é \%d. \n", getpid(), getppid(), getpgrp());
}
