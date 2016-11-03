#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 250.0
#define l 100.0
#define d 50.0
#define h 0.02
#define v 100.0

void em(double *V, double *Ex, double *Ey, int n, int N);

int main(){

  int n = (int)L;

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
    V[(int)((((n*(L-l))+L-d)/2)+(n*d))+j]=-v/2;

  }

  em(V,Ex,Ey,n,N);
  
  return 0;

}

void em(double *V, double *Ex, double *Ey, int n, int N){

  int i;
  int j;
  int z;

for(j=0;j<N;j++){
  
  for(z=1;j<n-1;z++){

  for(i=1;i<n-1;i++){

    if(!((i<(L-l)/2 && z==(L-d)/2 && i>(L+l)/2) || (i<(L-l)/2 && z==(L+d)/2 && i>(L-l)/2))){

      V[i+(n*z)]=((V[i+1+(n*z)]+V[i-1+(n*z)]+V[i+(n*(z-1))]+V[i+(n*(z+1))])/4);
    }
  }
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
