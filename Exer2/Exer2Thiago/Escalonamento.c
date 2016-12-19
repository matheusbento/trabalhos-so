#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include<time.h>
#define quanti 10
typedef struct processo Processo;
void* imprimir(void *id);

struct processo {
    int ID;
    int pesoPrioridade;
    pthread_t thread;
};
Processo lista[10];
Processo gerarThread(int id){
    Processo aux;
    aux.ID = id;
    aux.pesoPrioridade = rand() %5; // GERA UM NUMERO DE 0 A 5
    return aux;
}
void iniciarThread(Processo aux){
    pthread_create(&aux.thread, NULL,imprimir,(&aux));
    pthread_join(aux.thread, NULL);
}
void ordernarProcesso(){
    for (int i=0;i<quanti;i++){
        for (int j=0;j<quanti-1;j++){
            if (lista[j].pesoPrioridade < lista[j+1].pesoPrioridade){
                Processo aux;
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }

        }

    }

}

void* imprimir(void *pros){

    Processo *p = (Processo *)(pros);
    printf(" + Executou a thread %d \n", p->ID);
}

int main () {
    srand((unsigned)time(NULL));
    for (int i=0;i<10;i++){
        lista[i] = gerarThread(i); // CRIA UMA LISTA DE THREADS
    }
    printf("\n- Lista de Execução conforme suas respectivas Prioridades - \n");
    for (int i=0;i<10;i++){
      ordernarProcesso(); // ORDENA A LISTA DE THREADS DE ACORDO COM SUAS PRIORIDADES
      iniciarThread(lista[i]); // INICIA A EXECUÇÃO DAS THREADS

    }
    printf("---------------------\n");
    printf("- Lista de Threads com suas respectivas prioridades \n");
    printf("---------------------\n");
    printf("- ID  | PRIORIDADE");
    for (int i=0;i<10;i++){
    printf("\n");
        printf(" + %d  |      ", lista[i].ID);
        printf("  %d ", lista[i].pesoPrioridade);

    }
    printf("\n");


}
