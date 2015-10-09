

#include <stdio.h>
#include <math.h>
#include <float.h>





//lin_root function solves a linear equation taking care of the cases where a1 or/and a0 =0.
//each case returns a special a value which will then be interpreted by the quad_roots function
int lin_root(double *a,double *root)
/*  <Elkrief>_<Alexandre>_exer_1c */
{if (a[1]!=0){
    root[0] = -a[0]/a[1];
    return(1);}
else if (a[1]==0 && a[0]==0){
    return(0);}
else {
    return(-1);}
}

