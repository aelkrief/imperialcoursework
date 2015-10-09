//
//  Ex2Q5.h
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#ifndef ____Ex2Q5__
#define ____Ex2Q5__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <time.h>

double **make_matrix(int NR, int NC){
    double **M;
    int n;
    M=(double **)malloc((NR+1)*sizeof(double*));
    M[0]=(double *)malloc((NR+NC+1)*sizeof(double));
    M[1]=M[0];
    for (n=2; n<=NR;n++){
        M[n]=M[n-1]+NC;
    }
    return(M);
}

void free_matrix(double **M){
    free(M[0]);
    free(M);
}

void print_matrix(double **M, int NR, int NC){
    int i,j;
    printf("\n%d by %d Matrix: \n",NR, NC);
    for (i=1;i<=NR; i++){
        printf("\n");
        for (j=1;j<=NC;j++){
            printf("%10g ",M[i][j]);
        }
        
    }
    printf("\n\n");
}
/*
 double **make_random_matrix( int NR, int NC){
 double **M;
 int i,j;
 M=make_matrix(NR,NC);
 
 for (i=1;i<=NR; i++){
 for (j=1; j<=NC; j++) {
 M[i][j]=(double)rand()/(double)RAND_MAX;
 }
 }
 return(M);
 }*/

double **make_random_matrix(int NR,int NC)
{double **M; int i,j;
    M=make_matrix(NR,NC);
    for(i=1;i<=NR;i++){for(j=1;j<=NC;j++)
        M[i][j]=(double)rand()/(double)RAND_MAX;}
    return(M);}


double **mymatmul(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    for (i=1;i<=NR;i++){
        for (j=1;j<=NC2;j++){
            for (k=1;k<=NC;k++){
                
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}



#endif /* defined(____Ex2Q5__) */
