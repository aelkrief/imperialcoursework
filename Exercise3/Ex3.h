#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>

complex double **make_matrix(int NR,int NC)
{complex double **M; int n;
    M=(complex double **)malloc((NR)*sizeof(complex double*));
    M[0]=( complex double *)malloc(((NR-1)*(NC-1)+1)*sizeof( complex double));
    
    for(n=1;n<NR;n++) M[n]=(complex double *)malloc(((NR-1)*(NC-1)+1)*sizeof( complex double));
    return(M);}

void free_matrix( complex double **M,int N){
    int i;
    for(i=0;i<N;i++){free(M[i]);}
}

void print_matrix(complex double **M, int NR, int NC)
{int i,j;
    printf("\n %d by %d Matrix: \n",NR,NC);
    for(i=0;i<NR;i++){printf("\n");
        for(j=0;j<NC;j++)printf("%10f+%10fi",creal(M[i][j]),cimag(M[i][j]));}
    printf("\n\n");}







double **rmake_matrix(int NR,int NC)
{double **M; int n;
    M=(double **)malloc((NR)*sizeof(double*));
    M[0]=( double *)malloc(((NR-1)*(NC-1)+1)*sizeof( double));
    
    for(n=1;n<NR;n++) M[n]=(double *)malloc(((NR-1)*(NC-1)+1)*sizeof( double));
    return(M);}

void rfree_matrix( double **M,int N){
    int i;
    for(i=0;i<N;i++){free(M[i]);}
}

void rprint_matrix( double **M, int NR, int NC)
{int i,j;
    printf("\n %d by %d Matrix: \n",NR,NC);
    for(i=0;i<NR;i++){printf("\n");
        for(j=0;j<NC;j++)printf("%10f",M[i][j]);}
    printf("\n\n");}