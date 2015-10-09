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
#define PI 3.14159265

int lin_root(double *,double *);
int quad_roots(double *, double *);
int rcubic_roots(double *,double *);
int rquartic_roots(double *, double *);

int main(void){
    printf("          Name: <Alexandre Elkrief> \n           CID: <00732974> \n    LIBRARY NO: <0246431227> \n Email Address: <ae2212@ic.ac.uk> \n   Course Code: <M3SC>\n\n");
    double root[5],a[4],b,X,Y,theta1, theta2, theta3, theta4,theta_max1, theta_max2,theta_max3,theta_max4;
    double x1,x2,x3,x4,y1,y2,y3,y4;
    int rcubic_case, quad_case,rquartic_case;
    X=0.2;
    Y=1.0/3.0;
    printf("  B      Root1        Root2     Root3        Root4       Quad_Case    Phi1       Phi2       Phi3       Phi4\n");
    
    for(b=0.05;b<0.96;b=b+0.05){
        a[0]=-1;
        a[1]=(2*X-2+2*b*b)/(b*Y);
        a[2]=0;
        a[3]=(2*X+2-2*b*b)/(b*Y);
        rquartic_case=rquartic_roots(a,root);
        theta1=2*atan(root[1])*(180/PI);
        theta2=2*atan(root[2])*(180/PI);
        theta3=2*atan(root[3])*(180/PI);
        theta4=2*atan(root[4])*(180/PI);
        if (rquartic_case==4){
            printf("%.2f %11lf  %10lf  %10lf   %10lf  %8d  %10.2f %10.2f %10.2f %10.2f\n",b,root[1], root[2], root[3],root[4],rquartic_case,theta1, theta2, theta3, theta4);
        }
        else{
            printf("%.2f %11lf  %10lf  %10lf   I*%8lf  %8d  %10.2f %10.2f %10.2f %10.2f\n",b,root[1], root[2], root[3],root[4],rquartic_case,theta1, theta2, theta3, theta4);
        }
    }
    b=0.64429054104497;
    a[0]=-1;
    a[1]=(2*X-2+2*b*b)/(b*Y);
    a[2]=0;
    a[3]=(2*X+2-2*b*b)/(b*Y);
    rquartic_case=rquartic_roots(a,root);
    theta_max1=2*atan(root[1]);
    theta_max2=2*atan(root[2]);
    theta_max3=2*atan(root[3]);
    theta_max4=2*atan(root[4]);
    x1=cos(theta_max1);
    x2=cos(theta_max2);
    x3=cos(theta_max3);
    x4=cos(theta_max4);
    y1=b*sin(theta_max1);
    y2=b*sin(theta_max2);
    y3=b*sin(theta_max3);
    y4=b*sin(theta_max4);
    
    //the following are all the values for the maximum b for which there are 4 real roots.
    //The angles are computed in radians to be able to reuse them in r to plot the elipse and the normal lines.
    printf("B_MAX:  \n");
    printf("%lf %11lf  %10lf  %10lf   %10lf  %8d %10.2f %10.2f %10.2f %10.2f\n",b,root[1], root[2], root[3],root[4],rquartic_case, theta_max1,theta_max2, theta_max3, theta_max4);
    printf("t1=%lf, phi1=%lf, x1=%lf, y1=%lf\n",root[1],theta_max1,x1,y1);
    printf("t2=%lf, phi2=%lf, x2=%lf, y2=%lf\n",root[2],theta_max2,x2,y2);
    printf("t3=%lf, phi3=%lf, x3=%lf, y3=%lf\n",root[3],theta_max3,x3,y3);
    printf("t4= %lf, phi4=%lf, x4=%lf, y4=%lf\n",root[4],theta_max4,x4,y4);
}

