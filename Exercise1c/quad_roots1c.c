
#include <stdio.h>
#include <math.h>
#include <float.h>


int lin_root(double *,double *);
int quad_roots(double *a, double *root)
/*  <Elkrief>_<Alexandre>_exer_1c */
{double d, dr, changeorder;
    int lin_case;
    printf("quadratic: x^2+%lf*x+%lf \n", a[1],a[0]);
    //the function calls lin_root and integrates output cases it.
    if (a[2]==0){lin_case=lin_root(a,root);
        switch(lin_case){
            case 1:{return(-1);
                break;}
            case 0:{return(-2);
                break;}
            case -1:{return(-3);
                break;}
        }
    }
    
    if (a[0]==0){
        lin_case=lin_root(a, root);
        //ordering the roots in ascending order
        if (root[1]<0){
            root[2]=0;
            return(2);
        }
        else {
            root[2]=root[1];
            root[1]=0;
            return(2);
        }
    }
    
    d=a[1]*a[1]-4*a[2]*a[0];
    printf("d= %lf\n",d);
    if (d>0){
        /*condition on the 3 cases where the although the determinant is <FLT_MAX, operations on the coefficients might trigger an Floating Point Overflow error.*/
        if (a[1]*a[1]>DBL_MAX || fabs(a[0]*a[2])>DBL_MAX){
            if (a[0]*a[2]>0){printf("DBL MAX1 \n");
                /*puting the denominator in the square root and factorising allows to divide the coefficients before multiplying them together*/
                dr= sqrt(((a[1]/(2*a[2]))+(sqrt(a[0]/a[2])))*((a[1]/(2*a[2]))-(sqrt(a[0]/a[2]))));
                if (a[1]>0){
                    root[1]=(-a[1])/(2*a[2])-dr;
                    root[2]=(a[0]/a[2])/(root[1]);
                    if (root[1]<root[2]){
                        return(2);
                    }
                    else {
                        changeorder=root[1];
                        root[1]=root[2];
                        root[2]=changeorder;
                    }}
                else {
                    root[1]=(-a[1]+dr)/(2*a[2]);
                    root[2]=(a[0]/a[2])/(root[1]);
                    if (root[1]<root[2]){
                        return(2);
                    }
                    else {
                        changeorder=root[1];
                        root[1]=root[2];
                        root[2]=changeorder;
                    }
                    
                }
                return(2);
            }
            else{
                printf("DBL MAX2 \n");
                //I do not expand the dr above to force a[1] to be divided before it is multiplied.
                dr=sqrt((a[1]/(2*a[2]))*(a[1]/(2*a[2]))-(a[0]/a[2]));
                if (a[1]>0){
                    root[1]=(-a[1])/(2*a[2])+dr;
                    root[2]=(a[0]/a[2])/(root[1]);
                    if (root[1]<root[2]){
                        return(2);
                    }
                    else {
                        //ordering the roots
                        changeorder=root[1];
                        root[1]=root[2];
                        root[2]=changeorder;
                    }}
                else {
                    root[1]=(-a[1]+dr)/(2*a[2]);
                    root[2]=(a[0]/a[2])/(root[1]);
                    if (root[1]<root[2]){
                        return(2);
                    }
                    else {
                        //ordering the roots
                        changeorder=root[1];
                        root[1]=root[2];
                        root[2]=changeorder;
                    }
                    
                }
                
                return(2);}
        }
        else
            //case where operations on a[0],a[1],a[2] don't trigger floating point overflow.
        {dr= sqrt(d);
            printf("No DBL MAX\n");
            if (a[1]>0){
                //computing the roots
                root[1]=(-a[1]-dr)/(2*a[2]);
                root[2]=(a[0]/a[2])/(root[1]);
                if (root[1]<root[2]){
                    return(2);
                }
                else {
                    changeorder=root[1];
                    root[1]=root[2];
                    root[2]=changeorder;
                }}
            else {
                printf("Normal distinct case \n");
                root[1]=(-a[1]+dr)/(2*a[2]);
                root[2]=(a[0]/a[2])/(root[1]);
                if (root[1]<root[2]){
                    return(2);
                }
                else {
                    changeorder=root[1];
                    root[1]=root[2];
                    root[2]=changeorder;
                }
                
            }
            return(2);}
    }
    
    
    //case of repeated roots.
    else if (d==0)
    {root[1]=-a[1]/(2*a[2]);
        root[2]=root[1];
        return(1);}
    else {
        printf("Imaginary Roots\n");
        dr=sqrt(-d);
        root[1]=(-a[1]/(2*a[2]));
        root[2]=dr/(2*a[2]);
        return(0);}
}
