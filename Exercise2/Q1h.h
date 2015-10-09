//
//  Q1h.h
//  
//
//  Created by Alexandre on 17.03.15.
//
//

#ifndef _Q1h_h
#define _Q1h_h
double **make_matrix(int NR, int NC){
    double **M;
    int n;
    M=(double **)malloc((NR+1)*sizeof(double*));
    M[0]=(double *)malloc((NR+NC+1)*sizeof(double*));
    M[1]=M[0];
    for (n=2; n<=NR;n++){
        M[n]=M[n-1]+NC;
    }
    return(M);
}

void free_matrix(double **M){
    free(M[0]);
    free(M);
}

void print_matrix(double **M, int NR, int NC){
    int i,j;
    printf("\n%d by %d Matrix: \n",NR, NC);
    for (i=1;i<=NR; i++){
        printf("\n");
        for (j=1;j<=NC;j++){
            printf("%10g ",M[i][j]);
        }
        
    }
    printf("\n\n");
}

double **make_random_matrix( int NR, int NC){
    double **M;
    int i,j;
    M=make_matrix(NR,NC);
    
    for (i=1;i<=NR; i++){
        for (j=1; j<=NC; j++) {
            M[i][j]=(double)rand()/(double)RAND_MAX;
        }
    }
    return(M);
}


#endif
