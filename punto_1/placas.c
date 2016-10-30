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
  double *Ex=malloc(pow(n,2)*sizeof(double));
  double *Ey=malloc(pow(n,2)*sizeof(double));

  int i;

  for(i<0;i<pow(n,2);i++){

    V[i]=0.0;
    Ex[i]=0.0;
    Ey[i]=0.0;

  }

  int j;
  
  for(j=0;j<l;j++){

    V[(int)(((n*(L-l))+L-d)/2)+j]=v/2;
    V[(int)(((n*(L-l))+L+d)/2)+j]=-v/2;

  }

  em(V,Ex,Ey,n,N);
  
  return 0;

}

void em(double *V, double *Ex, double *Ey, int n, int N){

  int i;
  int j;

for(j=0;j<N;j++){

  for(i=n;i<pow(n,2)-n;i++){

    V[i]=((V[i+n]+V[i-n]+V[i-1]+V[i+1])/4);

  }

  }

 for(i=1;i<pow(n,2)-1;i++){

   Ex[i]=(V[i-1]-V[i+1])/(2*h);
   Ey[i]=(V[i-n]-V[i+n])/(2*h);
   
 }
 

  for(i=0;i<pow(n,2);i++){
  
    printf("%f %f %f\n",V[i],Ex[i],Ey[i]);
  
}

}
