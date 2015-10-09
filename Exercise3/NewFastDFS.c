#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include <stdlib.h>

complex double **make_matrix(int ,int );
complex double **MakeCn(int);
complex double *mymatmul(complex double **,complex double *, int , int );
complex double *MakeWpowers(int );


void FastDFS( complex double *x, complex double *y, complex double *w, complex double *Wp, int N, int skip)
{   int i,j,k;
    static int round=1, in_skip;
    complex double **Cn;
    
    if(round==1){
        in_skip=skip;
        round++;
    }
    
    
    
    if ((N/2)*2!=N){//odd
        
        
        Cn=MakeCn(N);
        
        if(in_skip==skip){
            if(N==3){
                x[0]=y[0]+y[skip]+y[2*skip];
                x[1]=y[0]-0.5*(y[skip]+y[2*skip])+I*(sqrt(3)/2)*(y[skip]-y[2*skip]);
                x[2]=y[0]-0.5*(y[skip]+y[2*skip])+I*(sqrt(3)/2)*(-y[skip]+y[2*skip]);
                return;
            }
            else{
                for(i=0;i<N;i++){
                    x[i]=mymatmul(Cn,y,N,N)[i];}
                return;
            }
            
            
        }
        else{
            printf("odd N=%d\n",N);
            if(N==3){
                w[1]=y[0]+y[skip]+y[2*skip];
                w[3]=y[0]-0.5*(y[skip]+y[2*skip])+I*(sqrt(3)/2)*(y[skip]-y[2*skip]);
                w[5]=y[0]-0.5*(y[skip]+y[2*skip])+I*(sqrt(3)/2)*(-y[skip]+y[2*skip]);
            }
            else{
                for(i=0;i<N;i++){
                    for (k=0; k<N; k++) {
                        w[skip*i+1]+=Cn[i][k]*y[k*skip];
                    }
                }
            }
            return;
        }
    }
    
    else{//even
        printf("even \n");
    
        if (N==4){
            if (in_skip==skip){
                x[0]=y[0]+y[skip]+y[2*skip]+y[3*skip];
                x[1]=y[0]-y[2*skip]+I*(y[skip]-y[3*skip]);
                x[2]=y[0]-y[skip]+y[2*skip]-y[3*skip];
                x[3]=y[0]-y[2*skip]+I*(y[3*skip]-y[skip]);
                return;
            }
            else{
                w[1]=y[0]+y[skip]+y[2*skip]+y[3*skip];
                w[3]=y[0]-y[2*skip]+I*(y[skip]-y[3*skip]);
                w[5]=y[0]-y[skip]+y[2*skip]-y[3*skip];
                w[7]=y[0]-y[2*skip]+I*(y[3*skip]-y[skip]);
                return;
            }
            
        }

        if (N==2){
            if(in_skip==skip){
                x[0]=y[0]+y[skip];
                x[1]=y[0]-y[skip];
                return;
            }
            else{
                w[1]=y[0]+y[skip];
                w[3]=y[0]-y[skip];
                return;
            }
        }
        
        FastDFS(x,y,w,Wp,N/2,2*skip);
        FastDFS(x,y+skip,w+N,Wp,N/2,2*skip);

        for (i=0;i<(N/2);i++){
            w[2*i]=w[2*i+1];
            w[2*i+1]=w[2*i]+Wp[i*skip/in_skip]*w[2*i+N+1];
            w[2*i+1+N]=w[2*i]+Wp[(i+N/2)*(skip/in_skip)]*w[2*i+N+1];
        }
        for(i=0;i<N;i++){
            x[i*skip]=w[2*i+1];
            
        }
    }
    //for(i=0;i<8;i++){printf("w[%d] = %lf + %lf i\n",i,creal(w[i]),cimag(w[i]));}
    
    
}
