#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int n=10000;
    int i,j,k;
    float soma=0;

    ///MATRIZ
    float **matriz=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
        matriz[i]=(float*)malloc(n*sizeof(float));

    ///MATRIZ EM VETOR
    float *matrizVetor=malloc(n*n*sizeof(float));


    ///GERA MATRIZ ALEATORIA
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matriz[i][j]=rand()%n;
        }
    }

    ///CHECA A DIAGONAL SE TODOS OS ELEMENTOS SAO IGUAIS A 1
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j && matriz[i][j] != 1){
                printf("Matriz Nao-Identidade.");
                return 0;
            }
        }
    }

    ///MATRIZ 1 PARA VETOR
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizVetor[i*n+j] = matriz[i][j];
        }
    }


    ///VERIFICAR IDENTIDADE
    for(i=0;i<n;i++){
        soma=0;
        for(k=0;k<n;k++){
            soma+=matrizVetor[i*n+k];
        }
        if(soma != 1){
            printf("Matriz Nao-identidade.");
            return 0;
        }
    }
    printf("Matriz Identidade.");




    return 0;
}
