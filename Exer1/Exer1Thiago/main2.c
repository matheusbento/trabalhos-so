#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


void salvar(int num, int estado){
    FILE *arq;
    int result;
    arq = fopen("criticalregion.txt", "wt");
    result = fprintf(arq, "%d\n", num);
    result = fprintf(arq, "%d\n", estado);
        if (result == EOF){
            printf("ERROR ");
        }
    fclose(arq);
}
int main()
{
    char *result1; // VARIAVEL PARA PEGAR A PRIMEIRA LINHA DO ARQUIVO
    char *result2;// VARIAVEL PARA PEGAR A SEGUNDA LINHA DO ARQUIVO
    int turn = 0; // VARIAVEL TURN PARA INDICAR O USO DA REGIAO CRITICA
    FILE *arq; // VARIAVEL ARQUIVO
    char linha[100];
    char linha2[100];
    int tenta=0; // TENTATIVAS DO WHILE
    int id = fork(); // CRIA UM PROCESSO FILHO
    while(tenta<10){
    arq = fopen("criticalregion.txt", "rt"); // ABRE O ARQUIVO CRITICALREGION.TXT

    if (arq == NULL){
        printf("Problema de leitura de arquivo!. \n");
    }
    result1 = fgets(linha, 100, arq); // PEGA A PRIMEIRA LINHA DO ARQUIVO
    result2 = fgets(linha2, 100, arq); // PEGA A SEGUNDA
    fclose(arq);
    turn=atoi(result2); // ATRIBUI O TURN COM O VALOR DA LINHA 2, SENDO 0 OU 1
    if (id!=0){ // VERIFICA SE CRIOU O PROCESSO FILHO
 //       printf("Processo Filho: \n");
        if (turn==0){ // VERIFICA SE TA SENDO USADO A REGIAO CRITICA
                salvar(1, TRUE);
                printf("        Filho -> Entrou na Regiao Critica\n");
                salvar(1, FALSE);
                printf("        Filho -> Saiu na Regiao Critica\n");
        }else{ // SE NAO ELE NAO TENTA ACESSAR
            printf("        Filho -> TENTOU ACESSAR REGIAO CRITICA *****************************\n");
        }
    }else{
 //       printf("Processo PAI: \n");
        if (turn==0){ // VERIFICA SE TA SENDO USADO
        //printf("ENTRO2\n");
            salvar(10, TRUE);
            printf("        Pai -> Entrou na regiao critica\n");
            salvar(10, FALSE);
            printf("        Pai -> Saiu na Regiao Critica\n");
        }else{
            printf("        Pai -> TENTOU ACESSAR REGIAO CRITICA *****************************\n");
        }
    }
    tenta++;
    }
    return 0;
}
