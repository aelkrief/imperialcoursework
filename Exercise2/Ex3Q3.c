//
//  Ex3Q3.c
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#include "Ex2Q2.h"


int main(void){
    int N;
    double **A,**B,**C,t,f,g;
    printf("Size of N:\n");
    scanf("%d",&N);
    A=make_random_matrix(N,N);
    print_matrix(A,N,N);
    
    
    B=make_random_matrix(N,N);
    print_matrix(B,N,N);
    
    
    clock_t start = clock();
    clock_t end;
    
    C=mymatmul(A,B,N,N,N);
    print_matrix(C,N,N);
    
    
    free_matrix(A);free_matrix(B);free_matrix(C);
    end = clock();
    t=(double)(end - start);
    f=N*N*(N+(N-1));
    g=(double)f/(double)(t*1000000000);
    printf("f= %f, t= %f\n", f,t);
    printf("%e \n \n",g);
    exit(0);
    
}
