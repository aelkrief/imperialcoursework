//
//  Ex2Q3.h
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#ifndef ____Ex2Q3__
#define ____Ex2Q3__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <time.h>




double **mymatmul1(double **A,double **B, int NR, int NC, int NC2){
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


double **mymatmul2(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    for (i=1;i<=NR;i++){
        for (k=1;k<=NC;k++){
            for (j=1;j<=NC2;j++){
            
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}

double **mymatmul3(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    for (k=1;k<=NC;k++){
        for (i=1;i<=NR;i++){
            for (j=1;j<=NC2;j++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}

double **mymatmul4(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    for (k=1;k<=NC;k++){
       for (j=1;j<=NC2;j++){
            for (i=1;i<=NR;i++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}

double **mymatmul5(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    for (j=1;j<=NC2;j++){
        for (k=1;k<=NC;k++){
            for (i=1;i<=NR;i++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}

double **mymatmul6(double **A,double **B, int NR, int NC, int NC2){
    double **C;
    int i,j,k;
    
    C=make_matrix(NR,NC2);
    
    
    for (j=1;j<=NC2;j++){
        for (i=1;i<=NR;i++){
            for (k=1;k<=NC;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return(C);
}












#endif /* defined(____Ex2Q3__) */
