#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>
//#include "Ex3.h"


complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );
complex double *MakeWpowersConj(int);
complex double **MakeCnConj(int);

void FastDFT( complex double *, complex double *, complex double *, complex double *, int , int);

void FastSINE(double *S, double *T, int N){
    complex double *x,*y,*Wp,*w;
    double *rx,*ry,*imx,*imy;
    int i,j,skip=1;
    
    x=(complex double * )malloc(2*N*skip*sizeof(complex double));
    y=(complex double * )malloc(2*N*skip*sizeof(complex double));
    rx=( double * )malloc(2*N*skip*sizeof( double));
    imx=( double * )malloc(2*N*skip*sizeof( double));
    w=(complex double * )malloc((4*N)*sizeof(complex double));
    Wp=MakeWpowersConj(2*N);
    
    for (j=0;j<2*N;j++){
        rx[j]=0;
    }
    
    imx[0]=0;
    imx[N]=0;
    for (j=1;j<=N-1;j++){
        imx[j]=S[j];
        imx[2*N-j]=-S[j];
    }
    
    
    for(i=0;i<2*N*skip;i++){
        x[i]=rx[i]+I*imx[i];
    }
    
    for(i=0;i<2*N;i++){printf("x[%d] = %lf + %lf i\n",i,creal(x[i]),cimag(x[i]));}
    
    FastDFT(x,y,w,Wp,2*N,1);
    
    for(i=0;i<2*N;i++){printf("y[%d] = %lf + %lf i\n",i,creal(y[i]),cimag(y[i]));}
    for(i=1;i<N*skip;i++){
        T[i]=N*creal(y[i]);
    }
    
     //NEED TO FREE
    
    return;
    
}