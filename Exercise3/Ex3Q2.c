#include <stdio.h>

#include <math.h>

#include <float.h>

#include <complex.h>
#include <stdlib.h>
#include "Ex3.h"


complex double *MakeWpowers(int );
complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );


void FastDFS( complex double *, complex double *, complex double *, complex double *, int , int);

int main(void)
{complex double *x,*y,*Wp,*w;
    double *rx,*ry,*imx,*imy;
    int N,i,skip;
    printf("\n Enter N \n");
    scanf("%d",&N);
    skip=1;
    
    x=(complex double * )malloc(N*skip*sizeof(complex double));
    y=(complex double * )malloc(N*skip*sizeof(complex double));
    rx=( double * )malloc(N*skip*sizeof( double));
    ry=( double * )malloc(N*skip*sizeof( double));
    imx=( double * )malloc(N*skip*sizeof( double));
    imy=( double * )malloc(N*skip*sizeof( double));
    w=(complex double * )malloc((2*N)*sizeof(complex double));
    Wp=MakeWpowers(N);
    

    printf("\n Enter real part of y \n");
    for(i=0;i<N*skip;i++){
        scanf("%lf",&ry[i]);
    }
    printf("\n Enter im part of y \n");
    for(i=0;i<N*skip;i++){
        scanf("%lf",&imy[i]);
    }
    
    for(i=0;i<N*skip;i++){
        //x[i]=rx[i]+I*imx[i];
        y[i]=ry[i]+I*imy[i];
    }
    
    FastDFS(x,y,w,Wp,N,skip);
    
    for(i=0;i<N*skip;i++){
        printf("x[%d]= %lf + %lf i \n",i,creal(x[i]),cimag(x[i]));
    }
    free(x);free(y);free(rx);free(ry);free(imx);free(imy);free(Wp);
    return(0);
}