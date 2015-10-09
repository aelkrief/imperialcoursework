//
//  Ex2Q3.c
//  
//
//  Created by Alexandre on 17.03.15.
//
//
#include "Ex2Q2.h"
#include "Ex2Q3.h"

int main(void){
    
    
    int NC, NR,NC2,i,j,ii,jj;
    double **A,**B,**C,**D,**E,**F,**G,**H,**I,t1,t2,t3,t4,t5,t6,f;
    clock_t start1,start2,start3,start4,start5,start6;
    clock_t end1,end2,end3,end4,end5,end6;
    
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
    
    start1=clock();
    D=mymatmul1(A,B,NR,NC,NC2);
    printf("Mymatmul1:\n");
    print_matrix(D,NR,NC2);
    end1 = clock();
    
    start2=clock();
    E=mymatmul2(A,B,NR,NC,NC2);
    printf("Mymatmul2:\n");
    print_matrix(E,NR,NC2);
    end2 = clock();
    
    
    start3=clock();
    F=mymatmul3(A,B,NR,NC,NC2);
    printf("Mymatmul3\n");
    print_matrix(F,NR,NC2);
    end3 = clock();
    
    start4=clock();
    G=mymatmul4(A,B,NR,NC,NC2);
    printf("Mymatmul4\n");
    print_matrix(G,NR,NC2);
    end4 = clock();
    
    start5=clock();
    H=mymatmul5(A,B,NR,NC,NC2);
    printf("Mymatmul5\n");
    print_matrix(H,NR,NC2);
    end5 = clock();
    
    start6=clock();
    I=mymatmul6(A,B,NR,NC,NC2);
    printf("Mymatmul6\n");
    print_matrix(I,NR,NC2);
    end6 = clock();
    
    
    
    free_matrix(A);free_matrix(B);
    free_matrix(D);
    free_matrix(E);
    free_matrix(F);
    free_matrix(G);
    free_matrix(H);
    free_matrix(I);

    
    
    /*
    t1=(double)(end1 - start1);
    t2=(double)(end2 - start2);
    t3=(double)(end3 - start3);
    t4=(double)(end4 - start4);
    t5=(double)(end5 - start5);
    t6=(double)(end6 - start6);
    f=NC*NR*(NC+(NC-1));
    
    printf("t1= %f\n",t1);
    printf("t2= %f\n",t2);
    printf("t3= %f\n",t3);
    printf("t4= %f\n",t4);
    printf("t5= %f\n",t5);
    printf("t6= %f\n",t6);
    
    
    //printf("%e\n \n",f/(t*1000000000));*/
    exit(0);
    
}