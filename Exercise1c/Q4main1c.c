//
//  Q4main1c.c
//
//
//  Created by Alexandre on 23.02.15.
//
//
#include <stdio.h>
#include <math.h>
#include <float.h>

int lin_root(long double *,long double *);
int quad_roots(long double *, long double *);
int rcubic_roots(long double *,long double *);
int rquartic_roots(long double *, long double *);

int main(void){
    printf("          Name: <Alexandre Elkrief> \n           CID: <00732974> \n    LIBRARY NO: <0246431227> \n Email Address: <ae2212@ic.ac.uk> \n   Course Code: <M3SC>\n");
    long double A,B,x[26] ;
    int I1,I2,I3,i;
    scanf("%d %d %d",&I1,&I2,&I3);
    A=I1+1;
    B=-I1;
    x[0]=(long double)I2/(long double)I3;
    x[1]=x[0];
    //printf("A,B= %lf, %lf\n",A,B);
    printf("x[0]=%Lf\nx[1]=%Lf\n",x[0],x[1]);
    for (i=2;i<26;i=i+1){
        
        x[i]=A*x[i-1]+B*x[i-2];
        printf("x[%d]=%Le\n",i,x[i]);
    }
    return(0);
}

