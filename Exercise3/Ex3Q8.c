#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>
#include "Ex3.h"
#define PI 3.14159265358979323846

complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );
complex double *MakeWpowersConj(int);
complex double **MakeCnConj(int);

void FastDFT( complex double *, complex double *, complex double *, complex double *, int , int);

void FastSINE(double *S, double *T,int N);

int main(void){
    double *S,*T;
    int N,i,skip=1;

    S=( double * )malloc(N*skip*sizeof( double));
    T=( double * )malloc(N*skip*sizeof( double));
    
    printf("\n Enter N \n");
    scanf("%d",&N);
    
    for (i=1;i<N;i++){
        S[i]=i;
        
    }

    
    /*for (i=0;i<N-1;i++){
        S[i]=sin(2*PI*i/N);
        
    }*/
    
    for(i=1;i<N;i++){printf("S[%d] = %f \n",i,S[i]);}
    FastSINE(S,T,N);
    
    for(i=1;i<N;i++){printf("\n\nT[%d] = %lf\n",i,T[i]);}
    
    //free(S);free(T);
    
    return(0);

}

