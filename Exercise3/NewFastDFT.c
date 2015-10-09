#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>

complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );
complex double *MakeWpowersConj(int);
complex double **MakeCnConj(int);

void FastDFT( complex double *x, complex double *y, complex double *w, complex double *Wp, int N, int skip)
{   int i,j,k;
    static int round=1, in_skip;
    complex double **Cn;
    
    if(round==1){
        in_skip=skip;
        round++;
    }
    
    
    
    if ((N/2)*2!=N){//odd
        
        Cn=MakeCnConj(N);
        
        if (in_skip==skip){
            if(N==3){
                printf("test3\n");
                y[0]=(x[0]+x[skip]+x[2*skip])*(1/(complex double) N);
                y[1]=(x[0]-0.5*(x[skip]+x[2*skip])-I*(sqrt(3)/2)*(x[skip]-x[2*skip]))*(1/(complex double) N);
                y[2]=(x[0]-0.5*(x[skip]+x[2*skip])-I*(sqrt(3)/2)*(-x[skip]+x[2*skip]))*(1/(complex double) N);
                return;
            }
            
            else{
                for(i=0;i<N;i++){
                    y[i]=mymatmul(Cn,x,N,N)[i]*(1/(complex double) N);}
                return;
            }
            
        }
        else{
            if(N==3){
                printf("test4\n");
                w[1]=x[0]+x[skip]+x[2*skip];
                w[3]=x[0]-0.5*(x[skip]+x[2*skip])-I*(sqrt(3)/2)*(x[skip]-x[2*skip]);
                w[5]=x[0]-0.5*(x[skip]+x[2*skip])-I*(sqrt(3)/2)*(-x[skip]+x[2*skip]);
            }
            
            else{
                for(i=0;i<N;i++){
                    for (k=0; k<N; k++) {
                        w[skip*i+1]+=Cn[i][k]*x[k*skip];
                    }
                }
            }
        }
        return;
    }
    
    else{//even
        printf("even \n");
        if (N==4){
            
            if (in_skip==skip){
                printf("test1\n");
                y[0]=(x[0]+x[skip]+x[2*skip]+x[3*skip])*(1/(complex double) N);
                y[1]=(x[0]-x[2*skip]-I*(x[skip]-x[3*skip]))*(1/(complex double) N);
                y[2]=(x[0]-x[skip]+x[2*skip]-x[3*skip])*(1/(complex double) N);
                y[3]=(x[0]-x[2*skip]-I*(x[3*skip]-x[skip]))*(1/(complex double) N);
                return;
            }
            else{
                printf("test2\n");
                w[1]=(x[0]+x[skip]+x[2*skip]+x[3*skip]);
                w[3]=(x[0]-x[2*skip]-I*(x[skip]-x[3*skip]));
                w[5]=(x[0]-x[skip]+x[2*skip]-x[3*skip]);
                w[7]=(x[0]-x[2*skip]-I*(x[3*skip]-x[skip]));
                return;
            }
            
        }
        
        if (N==2){
            if(in_skip==skip){
                y[0]=(x[0]+x[skip])*(1/(complex double) N);
                y[1]=(x[0]-x[skip])*(1/(complex double) N);
                return;
            }
            else{
                printf("N not 2, skip=%d\n",skip);
                w[1]=x[0]+x[skip];
                w[3]=x[0]-x[skip];
                return;
            }
        }
        
        FastDFT(x,y,w,Wp,N/2,2*skip);
        FastDFT(x+skip,y,w+N,Wp,N/2,2*skip);
        
        for (i=0;i<(N/2);i++){
            w[2*i]=w[2*i+1];
            w[2*i+1]=w[2*i]+Wp[i*skip/in_skip]*w[2*i+N+1];
            w[2*i+1+N]=w[2*i]+Wp[(i+N/2)*(skip/in_skip)]*w[2*i+N+1];
        }
        for(i=0;i<N;i++){
            y[i*skip]=w[2*i+1]*(1/(complex double) N);
            
        }
    }
    //for(i=0;i<8;i++){printf("w[%d] = %lf + %lf i\n",i,creal(w[i]),cimag(w[i]));}
    
    
}
