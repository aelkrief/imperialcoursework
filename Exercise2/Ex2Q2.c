//
//  Ex2Q2.c
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#include "Ex2Q2.h"
#include "Ex2Q3.h"
int main(void){
    int N;
    double **A,**B,**C,t,f,g;
    clock_t start;
    clock_t end;
    
    //comment on running the code for each mymatmul

    for (N=8; N<=10; N++) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    for (N=12; N<=36; N=N+2) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    for (N=40; N<=72; N=N+4) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    for (N=80; N<=144; N=N+8) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    for (N=160; N<=288; N=N+16) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    for (N=320; N<=1024; N=N+32) {
        A=make_random_matrix(N,N);
        start=clock();
        C=mymatmul3(A,A,N,N,N);
        end = clock();
        t=(double)(end - start)/1000000;
        f=N*N*(N+(N-1));
        g=(double)f/(double)(t*1000000000);
        //printf("f= %f, t= %f\n", f,t);
        
        printf("%lf \n",g);
        free_matrix(A);
        free_matrix(C);
    }
    
    
    

    

    exit(0);
}
