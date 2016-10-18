#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <xmmintrin.h>

int main()
{
    int n=10000;
    int i,j,k;
    __m128 a;
    __m128 b;
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



    for(i=0;i<n;i++){
        a = _mm_loadu_ps(matrizVetor+i*n);
        for(k=4;k<n;k+=4){
            b = _mm_loadu_ps(matrizVetor+i*n+k);
            a = _mm_add_ps(a, b);
        }
        for(k=0;k<4;k++){
            soma+=a[k];
        }
        if(soma != 1){
            printf("Matriz Nao-identidade.");
            return 0;
        }
    }
    printf("Matriz Identidade.");


    return 0;
}
