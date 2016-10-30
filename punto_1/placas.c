#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 5.0
#define l 2.0
#define d 1.0
#define h 0.02
#define v 100.0

void em(double *V, double *Ex, double *Ey, int n, int N);

int main(){

  int n = (int)(L/h);

  int N = 2*pow(n,2);

  double *V=malloc(pow(n,2)*sizeof(double));
  double *Ex=malloc(n*sizeof(double));
  double *Ey=malloc(n*sizeof(double));

  int i;

  for(i<0;i<pow(n,2);i++){

    V[i]=0.0;

  }

  int j;
  
  for(j=0;j<l;j++){

    V[(int)(((n*(L-l))+L-d)/2)+j]=v/2;
    V[(int)(((n*(L-l))+L+d)/2)+j]=v/2;

  }

  em(V,Ex,Ey,n,N);
  
  return 0;

}

void em(double *V, double *Ex, double *Ey, int n, int N){

  int i;
  int j;

for(j=0;j<N;j++){

  for(i=(int)(n*h);i<pow(n,2)-(int)(n*h);i++){

    V[i]=((V[i+(int)(n*h)]+V[i-(int)(n*h)]+V[i-(int)h]+V[i+(int)h])/4);

  }

  }

  for(i=0;i<pow(n,2);i++){
  
  printf("%f\n",V[i]);
  
}

}
