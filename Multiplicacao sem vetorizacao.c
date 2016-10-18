#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void imprimir(float **matriz, float **matriz2, float *matrizResultante, int n){
    int i,j;
    printf("Matriz A:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%0.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz B:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%0.2f ", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("\n\nMatriz R:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%0.2f ", matrizResultante[i*n+j]);
        }
        printf("\n");
    }

}

int main()
{
    float soma=0;
    int i,j,k;
    int n=1200;  ///TAMANHO MATRIZ

    ///////////Alocar matrizes
            ///MATRIZ1
        float **matriz=(float**)malloc(n*sizeof(float*));
        for(i=0;i<n;i++)
            matriz[i]=(float*)malloc(n*sizeof(float));
        ///MATRIZ1 EM VETOR
        float *matrizVetor=malloc(n*n*sizeof(float));

        ///MATRIZ2
        float **matriz2=(float**)malloc(n*sizeof(float*));
        for(i=0;i<n;i++)
            matriz2[i]=(float*)malloc(n*sizeof(float));

        ///MATRIZ2 TRANSPOSTA
        float **matriz2Transposta=(float**)malloc(n*sizeof(float*));
        for(i=0;i<n;i++)
            matriz2Transposta[i]=(float*)malloc(n*sizeof(float));

        ///MATRIZ2 TRANSPOSTA EM VETOR
        float *matriz2Transpostavetor=(float*)malloc(n*n*sizeof(float));

        ///MATRIZ RESULTANTE EM VETOR
        float *matrizResultanteVetor=(float*)malloc(n*n*sizeof(float));
    /////////////////


    /////////////////GERAZ MATRIZ ALEATORIA
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matriz[i][j]=rand()%n;
            matriz2[i][j]=rand()%n;
        }
    }
    ////////////////////


    ///MATRIZ 2 TRANSPOSTA
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matriz2Transposta[i][j] = matriz2[j][i];
        }
    }

    ///MATRIZ 1 e 2 PARA VETOR
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizVetor[i*n+j] = matriz[i][j];
            matriz2Transpostavetor[i*n+j] = matriz2Transposta[i][j];
        }
    }

    //////////////////////////////////

    ///////////////////Multiplicar matrizes
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            soma=0;
            for(k=0;k<n;k++)
                soma+=matrizVetor[i*n+k]*matriz2Transpostavetor[j*n+k];
            matrizResultanteVetor[i*n+j]=soma;
        }
    }

    //imprimir(matriz, matriz2, matrizResultanteVetor, n);

    return 0;
}
