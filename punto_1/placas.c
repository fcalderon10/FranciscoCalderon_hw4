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

    V[(int)(((L-l+(n*(L-d)))/2))+j]=v/2;
    V[(int)(((L-l+(n*(L-d)))/2) + (n*d))+j]=-v/2;

  }

  for(i=0;i<pow(n,2);i++){

   Ex[i]=(V[i-1]-V[i+1])/(2*h);
   Ey[i]=(V[i-n]-V[i+n])/(2*h);
   
 }

  em(V,Ex,Ey,n,N);
  
  return 0;

}

void em(double *V, double *Ex, double *Ey, int n, int N){

  int i;
  int j;
  int z;


for(z=0;z<N;z++){

    for(j=1;j<n-1;j++){

  for(i=1;i<n;i++){

    if((i+(n*j)<(int)((L-l+(n*(L-d)))/2) || i+(n*j)>(int)(((L-l+(n*(L-d)))/2)+l)) && (i+(n*j)<(int)(((L-l+(n*(L-d)))/2) + (n*d)) || (i+(n*j))>(int)(((L-l+(n*(L-d)))/2) + (n*d)+l))){
      
      V[i+(n*j)]=((V[i+1+(n*j)]+V[i-1+(n*j)]+V[i+(n*(j-1))]+V[i+(n*(j+1))])/4);
    
    }
  }
    }
 }
      
 for(i=0;i<pow(n,2);i++){

   Ex[i]=(V[i-1]-V[i+1])/(2*h);
   Ey[i]=(V[i-n]-V[i+n])/(2*h);
   
 }


  for(i=0;i<pow(n,2);i++){
  
    printf("%f %f %f\n",V[i],Ex[i],Ey[i]);
  
}

}
