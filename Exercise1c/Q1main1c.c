//
//  Q1main1c.c
//  
//
//  Created by Alexandre on 20.02.15.
//
//



#include <stdio.h>
#include <math.h>
#include <float.h>

int lin_root(double *,double *);
int quad_roots(double *, double *);
int rcubic_roots(double *,double *);

int main(void){
    printf("          Name: <Alexandre Elkrief> \n           CID: <00732974> \n    LIBRARY NO: <0246431227> \n Email Address: <ae2212@ic.ac.uk> \n   Course Code: <M3SC>\n");
    double A,B,C;
    double a[3],root[4];
    scanf("%lf %lf %lf", &a[2], &a[1], &a[0]);
    int rcubic_case, quad_case;
    
    rcubic_case=rcubic_roots(a,root);
    printf("Roots= %lf, %lf, %lf \n",root[1], root[2], root[3]);
}

