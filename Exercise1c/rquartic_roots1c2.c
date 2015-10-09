
#include <stdio.h>
#include <math.h>
#include <float.h>


int lin_root(double *,double *);
int quad_roots(double *, double *);
int rcubic_roots(double *,double *);

int rquartic_roots(double *a, double *root)
/* <Elkrief>_<Alexandre>_exer_1c */
{double b[3]={(4*a[0]*a[2]-a[1]*a[1]-a[0]*a[3]*a[3]),(a[1]*a[3]-4*a[0]),-a[2]};
    double root_inter1[4],r,quad_roots1[3],quad_roots2[3],r1,r2,r3,r4;
    int rcubic_case,quad_case1, quad_case2,quad_case_spec,cub_inter_case;
    
    if (a[0]==0){
        //printf("a0=0\n");
        double cub_inter_coeffs[3]={a[1],a[2],a[3]},cub_inter_roots[4];
        cub_inter_case=rcubic_roots(cub_inter_coeffs,cub_inter_roots);
        //printf("cub_inter_case=%d\n",cub_inter_case);
        //printf("cub_inter_roots= %lf %lf %lf \n", cub_inter_roots[1],cub_inter_roots[2],cub_inter_roots[3]);
        
        if (cub_inter_case==0){
            if (cub_inter_roots[1]<=0){
                root[1]=cub_inter_roots[1];
                root[2]=0;
                root[3]=cub_inter_roots[2];
                root[4]=cub_inter_roots[3];
            }
            else{
                root[1]=0;
                root[2]=cub_inter_roots[1];
                root[3]=cub_inter_roots[2];
                root[4]=cub_inter_roots[3];
            }
            return(2);
        }
        else{//dont forget cases of repeated roots for appropriate return value!!!!!
            if (cub_inter_roots[1]>=0){
                root[1]=0;
                root[2]=cub_inter_roots[1];
                root[3]=cub_inter_roots[2];
                root[4]=cub_inter_roots[3];
            }
            else if(cub_inter_roots[1]<0 && cub_inter_roots[2]>=0){
                root[1]=cub_inter_roots[1];
                root[2]=0;
                root[3]=cub_inter_roots[2];
                root[4]=cub_inter_roots[3];
            }
            else if(cub_inter_roots[2]<0 && cub_inter_roots[3]>=0){
                root[1]=cub_inter_roots[1];
                root[2]=cub_inter_roots[2];
                root[3]=0;
                root[4]=cub_inter_roots[3];
            }
            else{
                root[1]=cub_inter_roots[1];
                root[2]=cub_inter_roots[2];
                root[3]=0;
                root[4]=cub_inter_roots[3];
                
            }
            if (cub_inter_case==3){//3 distinct roots
                //printf("cub case 3 ordering\n");
                if(cub_inter_roots[1]!=0 && cub_inter_roots[2]!=0 && cub_inter_roots[3]!=0){
                    return(4);
                }
                else{return(3);}
            }
            else if (cub_inter_case==2){//1 repeated, 1 real root
                if(cub_inter_roots[1]!=cub_inter_roots[2]){//repeated roots are r2,r3
                    if(cub_inter_roots[1]==0){return(2);}
                    else if(cub_inter_roots[2]==0){return(1);}
                    else{return(3);}
                }
                else{
                    if(cub_inter_roots[1]==0){return(1);}
                    else if(cub_inter_roots[3]==0){return(2);}
                    else{return(3);}
                }
            }
            else{//triple/quadruple root
                return(1);
            }
        }
    }
    
    else if (a[1]==0 && a[2]==0 && a[3]==0){
        if (a[0]>0){
            root[1]=0;
            root[2]=0;
            root[3]=-pow(fabs(a[0]),1.0/4.0);
            root[4]=pow(fabs(a[0]),1.0/4.0);
            return(0);
        }
        else{
            root[1]=-pow(fabs(a[0]),1.0/4.0);
            root[2]=-pow(fabs(a[0]),1.0/4.0);
            root[3]=pow(fabs(a[0]),1.0/4.0);
            root[4]=pow(fabs(a[0]),1.0/4.0);
            return(2);
        }
        
    }
    //Q2-(ii)
    else if(a[1]==0 && a[3]==0){
        //printf("a1=a3=0\n");
        double quad_special[3]={a[0],a[2],1},quad_inter1, quad_inter2;
        quad_case_spec=quad_roots(quad_special,root);
        quad_inter1=root[1];
        quad_inter2=root[2];
        if (quad_case_spec==0){//imaginary roots of quadratric
            root[1]=(1/sqrt(2))*sqrt(sqrt(quad_inter1*quad_inter1+quad_inter2*quad_inter2)+quad_inter1);
            if(quad_inter2>=0){
                root[2]=(1/sqrt(2))*sqrt(sqrt(quad_inter1*quad_inter1+quad_inter2*quad_inter2)-quad_inter1);
            }
            else{root[2]=-(1/sqrt(2))*sqrt(sqrt(quad_inter1*quad_inter1+quad_inter2*quad_inter2)-quad_inter1);}
                root[3]=-root[1];
                root[4]=-root[2];
            if(root[3]<=root[1]){
                r1=root[3];
                r2=root[4];
                r3=root[1];
                r4=root[2];}
            else{
                r1=root[1];
                r2=root[2];
                r3=root[3];
                r4=root[4];}
            root[1]=r1;
            root[2]=r2;
            root[3]=r3;
            root[4]=r4;
            return(0);
        }
        else{
            if(quad_inter1>0 && quad_inter2>0){
                root[1]=-sqrt(quad_inter2);
                root[2]=-sqrt(quad_inter1);
                root[3]=sqrt(quad_inter1);
                root[4]=sqrt(quad_inter2);
                return(4);
            }
            else if(quad_inter1<0 && quad_inter2>0){
                //printf("r3, r4 are complex on imaginary conjugates, r1,r2 are real\n");
                root[1]=-sqrt(quad_inter2);
                root[2]=sqrt(quad_inter2);
                root[3]=-sqrt(fabs(quad_inter1));
                root[4]=sqrt(fabs(quad_inter1));
                return(2);
            }
            else {
               // printf("all imaginary parts\n");
                root[1]=-sqrt(fabs(quad_inter1));
                root[2]=-sqrt(fabs(quad_inter2));
                root[3]=sqrt(fabs(quad_inter2));
                root[4]=sqrt(fabs(quad_inter1));
                return(2);
            }
            
        }
    }
    
    
    
    
    else{
        //printf("No special case\n");
        rcubic_case=rcubic_roots(b,root_inter1);
        //printf("cubic case=%d\n",rcubic_case);
        //printf("Cubic roots= %lf %lf %lf \n", root_inter1[1],root_inter1[2],root_inter1[3]);
        if (rcubic_case==0){
            r=root_inter1[1];
        }
        else{
            r=root_inter1[3];
        }
        //printf("r=%lf \n \n",r);
        
        double quad_coeff1[3]={((r/2)+sqrt((r/2)*(r/2)-a[0])),((a[3]/2)+sqrt(((a[3]*a[3])/4)+r-a[2])),1};
        double quad_coeff2[3]={((r/2)-sqrt((r/2)*(r/2)-a[0])),((a[3]/2)-sqrt(((a[3]*a[3])/4)+r-a[2])),1};
        double quad_coeff3[3]={((r/2)+sqrt((r/2)*(r/2)-a[0])),((a[3]/2)-sqrt(((a[3]*a[3])/4)+r-a[2])),1};
        double quad_coeff4[3]={((r/2)-sqrt((r/2)*(r/2)-a[0])),((a[3]/2)+sqrt(((a[3]*a[3])/4)+r-a[2])),1};
        
        if (r>=0){
            quad_case1=quad_roots(quad_coeff1,quad_roots1);
            quad_case2=quad_roots(quad_coeff2,quad_roots2);
        }
        else{
            quad_case1=quad_roots(quad_coeff3,quad_roots1);
            quad_case2=quad_roots(quad_coeff4,quad_roots2);
        }
        
        
        if (quad_case1==0 && quad_case2==0){
            //4 imaginary
            if (quad_roots1[1]<quad_roots2[1]){
                root[1]=quad_roots1[1];
                root[2]=quad_roots1[2];
                root[3]=quad_roots2[1];
                root[4]=quad_roots2[2];
            }
            else {
                root[1]=quad_roots2[1];
                root[2]=quad_roots2[2];
                root[3]=quad_roots1[1];
                root[4]=quad_roots1[2];
            }
            return(0);
        }
        else if (quad_case1==0 && quad_case2!=0){
            //2 real, 2 imaginary
            root[1]=quad_roots2[1];
            root[2]=quad_roots2[2];
            root[3]=quad_roots1[1];
            root[4]=quad_roots1[2];
            return(2);
        }
        else if (quad_case1!=0 && quad_case2==0){
            //2 real, 2 imaginary
            root[1]=quad_roots1[1];
            root[2]=quad_roots1[2];
            root[3]=quad_roots2[1];
            root[4]=quad_roots2[2];
            return(2);
        }
        else if ((quad_case1==1) && (quad_case2==1)){
            //2 equal, 2 equal
            if (quad_roots1[1]<quad_roots2[1]){
                root[1]=quad_roots1[1];
                root[2]=quad_roots1[2];
                root[3]=quad_roots2[1];
                root[4]=quad_roots2[2];
            }
            else{
                root[1]=quad_roots2[1];
                root[2]=quad_roots2[2];
                root[3]=quad_roots1[1];
                root[4]=quad_roots1[2];
                
            }
            return(1);
        }
        else if (quad_case1==1 || quad_case2==1){
            if (quad_case1==2){//2 real 1 repeated
                if(quad_roots1[2]<quad_roots2[1]){
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots1[2];
                    root[3]=quad_roots2[1];
                    root[4]=quad_roots2[2];
                }
                else if (quad_roots1[1]>quad_roots2[1]){
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots2[2];
                    root[3]=quad_roots1[1];
                    root[4]=quad_roots1[2];
                }
                else {
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots2[1];
                    root[3]=quad_roots2[2];
                    root[4]=quad_roots1[2];
                }
            }
            else if (quad_case2==2){//1 repeated, 2 real
                if(quad_roots2[2]<quad_roots1[1]){
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots2[2];
                    root[3]=quad_roots1[1];
                    root[4]=quad_roots1[2];
                }
                else if (quad_roots1[1]<quad_roots2[1]){
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots1[2];
                    root[3]=quad_roots2[1];
                    root[4]=quad_roots2[2];
                }
                else {
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots1[1];
                    root[3]=quad_roots1[2];
                    root[4]=quad_roots2[2];
                }
            }
            
            if (root[2]==root[3]){return(1);
            }
            else{return(3);}
        }
        
        else {
            if (quad_roots1[1]<quad_roots2[1]){
                //start with r1
                if(quad_roots1[2]<quad_roots2[1]){//r1 r2 r3 r4
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots1[2];
                    root[3]=quad_roots2[1];
                    root[4]=quad_roots2[2];
                }
                else if ((quad_roots1[2]>quad_roots2[1]) && (quad_roots1[2]<quad_roots2[2])){//r1 r3 r2 r4
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots2[1];
                    root[3]=quad_roots1[2];
                    root[4]=quad_roots2[2];
                }
                else{//r1 r3 r4 r2
                    root[1]=quad_roots1[1];
                    root[2]=quad_roots2[1];
                    root[3]=quad_roots2[2];
                    root[4]=quad_roots1[2];
                }
                
            }
            else{//start with r3
                if(quad_roots2[2]<quad_roots1[1]){//r3 r4 r1 r2
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots2[2];
                    root[3]=quad_roots1[1];
                    root[4]=quad_roots1[2];
                }
                else if ((quad_roots2[2]>quad_roots1[1]) && (quad_roots2[2]<quad_roots1[2])){//r3 r1 r4 r2
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots1[1];
                    root[3]=quad_roots2[2];
                    root[4]=quad_roots1[2];
                }
                else{//r3 r1 r2 r4
                    root[1]=quad_roots2[1];
                    root[2]=quad_roots1[1];
                    root[3]=quad_roots1[2];
                    root[4]=quad_roots2[2];
                }
            }
            return(4);
        }
    }
}