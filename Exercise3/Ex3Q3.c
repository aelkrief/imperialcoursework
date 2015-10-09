#include <stdio.h>

#include <math.h>

#include <float.h>

#include <complex.h>
#include <stdlib.h>
#include "Ex3.h"


complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );
complex double *MakeWpowersConj(int);
complex double **MakeCnConj(int);

void FastDFT( complex double *, complex double *, complex double *, complex double *, int , int);


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
    Wp=MakeWpowersConj(N);
    
    /*
    printf("\n Enter real part of x \n");
    for(i=0;i<N;i++){
        scanf("%lf",&rx[i]);
    }
    printf("\n Enter im part of x \n");
    for(i=0;i<N;i++){
        scanf("%lf",&imx[i]);
    }
    */
    printf("\n Enter real part of x \n");//pretend x for now.
    for(i=0;i<N*skip;i++){
        scanf("%lf",&rx[i]);
    }
    printf("\n Enter im part of x \n");//Pretend its x for now
    for(i=0;i<N*skip;i++){
        scanf("%lf",&imx[i]);
    }
    
    for(i=0;i<N*skip;i++){
        x[i]=rx[i]+I*imx[i];
    }

    
    FastDFT(x,y,w,Wp,N,skip);
    
    for(i=0;i<N;i++){
        printf("y[%d]= %lf + %lf i \n",i,creal(y[i]),cimag(y[i]));
    }
    free(x);free(y);free(rx);free(ry);free(imx);free(imy);
    return(0);
}