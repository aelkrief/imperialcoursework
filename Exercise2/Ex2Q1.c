
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include "Q1h.h"



double **matrix_addition(double **A, double **B, int L, int M){
    double **C;
    int i,j;
    
    C=make_matrix(L,M);
    for(i=1;i<=L;i++){
        for(j=1;j<=M;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return(C);
}

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



int main(void){
    

    int NC, NR,NC2,i,j,ii,jj;
    double **A,**B,**C,**D,t,f;
    printf("Enter NR, NC, NC2 and entries of 1st matrix:\n");
    scanf("%d %d %d\n", &NR, &NC, &NC2);
    A=make_matrix(NR,NC);
    
    for(i=1;i<=NR;i++){
        for(j=1;j<=NC;j++){
            scanf("%lf",&A[i][j]);
        }
    }
    print_matrix(A,NR,NC);
    printf("Enter entries of 2nd matrix:\n");
    B=make_matrix(NC,NC2);
    
    for(ii=1;ii<=NC;ii++){
        for(jj=1;jj<=NC2;jj++){
            scanf("%lf",&B[ii][jj]);
        }
    }
    
    
    print_matrix(B,NC,NC2);
    
    //C=make_random_matrix(NR,NR);
    //print_matrix(C,NR,NR);
    
    clock_t start = clock();
    clock_t end;
    
    D=mymatmul(A,B,NR,NC,NC2);
    print_matrix(D,NR,NC2);
    
    
    free_matrix(A);free_matrix(B);free_matrix(D);
    exit(0);
    
}