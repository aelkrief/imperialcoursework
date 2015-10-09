//
//  Ex3Q1.c
//  
//
//  Created by Alexandre on 02.04.15.
//
//

//#include "Ex3.h"
#include <complex.h>
#define PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>
complex double **make_matrix(int ,int );


complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );
/*
complex double *MakeWpowers(int N)
{complex double *x;
    int i;
    x=(complex double * )malloc(N*sizeof(complex double));
    for(i=0;i<N;i++){
        x[i]=cos(2*PI*i/N)+I*sin(2*PI*i/N);
    }
    return(x);
    
}*/

complex double *MakeWpowers(int N)
{complex double *x,temp1,temp2;
    int i;
    x=(complex double * )malloc(N*sizeof(complex double));
    if ((N/2)*2!=N){
        x[0]=1;
        for(i=1;i<(N*1.0)/2;i++){
            temp1=cos(2*PI*i/N);
            temp2=sin(2*PI*i/N);
            x[i]=temp1+I*temp2;
            x[N-i]=temp1-I*temp2;
        }
    }
    else{
        x[0]=1;
        x[N/2]=-1;
        for(i=1;i<N/2;i++){
            temp1=cos(2*PI*i/N);
            temp2=sin(2*PI*i/N);
            x[i]=temp1+I*temp2;
            x[N-i]=temp1-I*temp2;
        }
        
    }
    return(x);
}

complex double *mymatmul(complex double **A,complex double *v, int N, int M)
{
    complex double *C;
    int i,k;
    C=(complex double * )malloc(N*sizeof(complex double));
    for(i=0;i<N;i++)  {
        for(k=0;k<M;k++){
            C[i]+=A[i][k]*v[k];
        }
    }
    
    return(C);
}

complex double **MakeCn(int N)
{
    complex double **C;
    int k,j;
    C=make_matrix(N,N);
    for(j=0;j<N;j++){
        for(k=0;k<N;k++)  {
            C[j][k]=MakeWpowers(N)[j*k % N];
            
        }
    }
    return(C);
}

complex double *MakeWpowersConj(int N)
{complex double *x;
    int i;
    x=(complex double * )malloc(N*sizeof(complex double));
    for(i=0;i<N;i++){
        x[i]=(cos(2*PI*i/N)-I*sin(2*PI*i/N));
    }
    return(x);
}

complex double **MakeCnConj(int N)
{
    complex double **C;
    int k,j;
    C=make_matrix(N,N);
    for(j=0;j<N;j++){
        for(k=0;k<N;k++)  {
            C[j][k]=MakeWpowersConj(N)[j*k % N];
            
        }
    }
    return(C);
}
/*
complex double **mymatmulmatrix(complex double **A,complex double **B, int N, int MM,int M)
{
    complex double **C;
    int i,k,j ;
    C=(complex double **)malloc(N*sizeof(complex double *));
    for (i=1;i<=N;i++){
        for (j=1;j<=M;j++){
            for (k=1;k<=MM;k++){
                
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}
*/

/*
int main(void)
{complex double **C,**Cconj,**mult;
    
    int N;
    printf("\n Enter N \n");
    scanf("%d",&N);
    
    C=MakeCn(N);
    printf("\n Cn is: \n");
    print_matrix(C,N,N);
    
    Cconj=MakeCnConj(N);
    printf("\n Cnconj is: \n");
    print_matrix(Cconj,N,N);
    
    
    //mult=mymatmulmatrix(C,Cconj,N,N,N);
    //printf("\n mult is: \n");
    //print_matrix(mult,N,N);
    
    free_matrix(C,N);
    free_matrix(Cconj,N);
    //free_matrix(mult,N);
    exit(0);}
*/





