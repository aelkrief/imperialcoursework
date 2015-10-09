
#include <stdio.h>
#include <math.h>
#include <float.h>


int lin_root(double *,double *);
int quad_roots(double *, double *);
int rcubic_roots(double *,double *);

int rcubic_roots(double *a,double *root)
/* <Elkrief>_<Alexandre>_exer_1c */

{double p,alpha,beta,i,fx,df,ytemp,y,big,small,middle,delta_quad,p2,y2;
    double root_inter1[3],root_inter2[3];
    int quad_case;
    if (a[1]==0 && a[2]==0){
        //printf("a[2]=a[1]=%f\n",a[0]);
        if (a[0]>0){
            root[1]=-pow(fabs(a[0]),1.0/3.0);
            //real part of x=-sign(a[0])|a[0]|^(1/3)*cubic root of unity
            root[2]=-pow(fabs(a[0]),1.0/3.0)*(-0.5);
            //imaginary part of x=-sign(a[0])|a[0]|^(1/3)*cubic root of unity
            root[3]=pow(fabs(a[0]),1.0/3.0)*sqrt(3)*0.5;
        }
        else{root[1]=pow(fabs(a[0]),1.0/3.0);
            root[2]=pow(fabs(a[0]),1.0/3.0)*(-0.5);
            root[3]=pow(fabs(a[0]),1.0/3.0)*sqrt(3)*0.5;
        }
        return(0);
    }
    
    else if(a[0]==0){
        //printf("a[0]=%f\n",a[0]);
        root[1]=0;
        double quad1[3]={a[1],a[2],1};
        quad_case=quad_roots(quad1,root_inter1);
        //printf("root_inter=%lf, %lf\n",root_inter1[1],root_inter1[2]);
        root[2]=root_inter1[1];
        root[3]=root_inter1[2];
        //printf("quad_case=%d\n",quad_case);
        if (root[2]<0 && root[3]>0){
            middle=root[1];
            small=root[2];
            big=root[3];
        }
        else if(root[3]<0){
            big=root[1];
            middle=root[3];
            small=root[2];
        }
        else{
            big=root[3];
            middle=root[2];
            small=root[1];
        }
        root[1]=small;
        root[2]=middle;
        root[3]=big;
        
        if (root[1]==root[2] && root[2]==root[3]){
            return(1);
        }
        else if (root[1]==root[2] || root[2]==root[3] || root[1]==root[3]){
            return(2);
        }
        else if (root[1]!=root[2] && root[2]!=root[3] && root[1]!=root[3]){
            return(3);
        }
        else if(quad_case==0){return(0);}
        else{//printf("test");
            return(0);}
    }
    else if(a[0]==a[1]*a[2]){
       // printf("a[0]=a[1]*a[2]\n");
        //printf("a[1]=%f\n",a[1]);
        //printf("sqrt(a[1])=%f\n",sqrt(a[1]));
        if(a[1]<0){
            if (fabs(a[2])>sqrt(fabs(a[1]))){
                root[1]=-a[2];
                root[2]=-sqrt(-a[1]);
                root[3]=sqrt(-a[1]);
            }
            else{
                root[1]=-sqrt(-a[1]);
                root[2]=-a[2];
                root[3]=sqrt(-a[1]);
            }
            return(3);
        }
        else{
            root[1]=-a[2];
            root[2]=0;
            root[3]=sqrt(a[1]);
            return(0);
        }
    }
    else if(3*a[1]==a[2]*a[2] && 27*a[0]==a[2]*a[2]*a[2]){
        //printf("3-27 case\n");
        root[1]=-a[2]/3.0;
        root[2]=-a[2]/3.0;
        root[3]=-a[2]/3.0;
        return(1);
    }
    
    
    else {
        
        beta= -a[2]/3.0;
        //printf("a[0] print=%f\n",a[0]);
        //printf("beta print=%lf \n", beta);
        if ((beta*beta*beta+a[2]*beta*beta+a[1]*beta+a[0])>0){
            //printf("neg\n");
            alpha=-pow((beta*beta*beta+a[2]*beta*beta+a[1]*beta+a[0]),1.0/3.0);
            //alpha=-pow(fabs(((beta+a[2])*beta+a[1])*1+a[0]/beta),1.0/3.0)*pow(fabs(beta),1.0/3.0);
        }
        else{
           // printf("pos\n");
            //printf("kk=%lf\n",beta*beta*beta+a[2]*beta*beta+a[1]*beta+a[0]);
            alpha=pow(fabs(beta*beta*beta+a[2]*beta*beta+a[1]*beta+a[0]),1.0/3.0);
            //alpha=pow(fabs(((beta+a[2])*beta+a[1])*1+a[0]/beta),1.0/3.0)*pow(fabs(beta),1.0/3.0);
        }
        //printf("alpha=%lf, beta=%e \n",alpha,beta);
        //p=(3*beta*beta+2*a[2]*beta+a[1])/(alpha*alpha);
        p=((3*beta*beta+2*a[2]*beta+a[1])/alpha)/alpha;
        //printf("p=%lf \n",p);
        //printf("Reduced cubic: y^3+%lf*y-1=0 \n",p);
        i=0;
        p2=-3/pow(4,1.0/3.0);
        y2=-1/pow(2,1.0/3.0);
        //printf("p2=%f, y2=%f\n",p2,y2);
        
        //special case Q3-vi
        if (fabs(p-p2)<0.01){
            //printf("p-p2 case\n");
            if (alpha*y2+beta<alpha*(1/(y2*y2))+beta){
                root[1]=alpha*y2+beta;
                root[2]=alpha*y2+beta;
                root[3]=alpha*(1/(y2*y2))+beta;
            }
            else{
                root[1]=alpha*(1/(y2*y2))+beta;
                root[2]=alpha*y2+beta;
                root[3]=alpha*y2+beta;
            }
            //printf("Roots=%lf %lf %lf\n", root[1],root[2],root[3]);
            return(2);
        }
        
        //special case Q3-v
        else if (p==0){
            //printf("p=0 case\n");
            root[1]=1;
            root[2]=-0.5;
            root[3]=sqrt(3)/2.0;
            return(0);
            
        }
        
        
        
        else if (fabs(p)<2) {
            y=1-p/3;
           // printf("|p|<2\n");
        }
        else {
            y=1/p;
            //printf("|p|>2\n");
        }
        //printf("y=%f \n",y);
        
        while (ytemp!=y && i<4){
            
            
            fx=y*y*y+p*y-1;
            df=3*y*y+p;
            
            ytemp=y;
            y=y-fx/df;
            //printf("%.25lf \n",y);
            i=i+1;
        }
        root[1]=alpha*y+beta;
        
        double quad2[3]={(-a[0]/(root[1])),(a[2]+root[1]),1};
        quad_case=quad_roots(quad2, root_inter2);
        //printf("root_inter=%lf, %lf\n",root_inter2[1],root_inter2[2]);
        root[2]=root_inter2[1];
        root[3]=root_inter2[2];
        //printf("Quadratic coeffs: %f, %f \n",a[2]+(root[1]),-a[0]/(root[1]));
        //ordering the roots in ascending order
        delta_quad=(a[2]+(root[1]))*(a[2]+(root[1]))-4*(-a[0]/(root[1]));
        //printf("Delta_quad= %lf\n",delta_quad);
        if (delta_quad>=0){
            if (root[1]>root[2] && root[1]>root[3]){
                big=root[1];
                if (root[2]>root[3]){
                    middle=root[2];
                    small=root[3];
                }
                else{
                    middle=root[3];
                    small=root[2];
                }
            }
            
            else if (root[2]>root[3]){
                big=root[2];
                if (root[1]>root[3]){
                    middle=root[1];
                    small=root[3];
                }
                else{
                    middle=root[3];
                    small=root[1];
                }
            }
            else{
                big=root[3];
                if (root[1]>root[2]){
                    middle=root[1];
                    small=root[2];
                }
                else{
                    middle=root[2];
                    small=root[1];
                }
            }
            root[1]=small;
            root[2]=middle;
            root[3]=big;
            
            if (root[1]==root[2] && root[2]==root[3]){
                return(1);
            }
            else if (root[1]==root[2] || root[2]==root[3] || root[1]==root[3]){
                return(2);
            }
            else {
                return(3);
            }
        }
        
        else{
            return(0);
        }
    }
    
    
}

