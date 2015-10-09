//
//  Ex2Q5.c
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#include "Ex2Q2.h"
#define PI 3.14159265358979323846

double **MakeSN(int N){
    int j,k;
    double **S,**A,t,f,g;
    
    S=make_matrix(N-1,N-1);
    
    for (j=1;j<N;j++) {
        for (k=1; k<N;k++) {
            S[j][k]=sin(j*k*PI/N);
            
        }
    }
    
    //print_matrix(S,N-1,N-1);
    return(S);
    
}

int main(void){
    double **Sn,**Sn_Square;
    int N;
    printf("Size of N:\n");
    scanf("%d",&N);
    
    
    Sn=MakeSN(N);
    print_matrix(Sn,N-1,N-1);
    
    Sn_Square=mymatmul(Sn,Sn,N-1,N-1,N-1);
    print_matrix(Sn_Square,N-1,N-1);

    exit(0);
}
