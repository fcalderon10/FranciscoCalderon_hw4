#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n_points 1000
#define delta_t 0.0005
#define T 40.0
#define rho 10.0
#define L 100.0
#define iteraciones 300
#define c pow((T/rho),0.5)

void solve(double *u_past , double *u_present , double *u_fut , double r);

int main(){

  double *x=malloc(n_points*sizeof(double));
  double *u_init=malloc(n_points*sizeof(double));
  double *u_present=malloc(n_points*sizeof(double));
  double *u_fut=malloc(n_points*sizeof(double));
  double *u_past=malloc(n_points*sizeof(double));
  int i;

  for(i=0;i<n_points;i++){
    x[i]=i*L/n_points;
  }

  double delta_x = x[1]-x[0];

  double r=c*delta_t/delta_x;

  
  for(i=0;i<n_points;i++){

    if(x[i]<=0.8*L) {

    u_init[i]=1.25*x[i]/L;
    
    }

    else {
      u_init[i]=5-(5*x[i]/L);
    }
  }

  /*Condiciones iniciales*/
  
  u_init[0]=0.0;
  u_init[n_points-1]=0.0;

  u_fut[0]=0.0;
  u_fut[n_points-1]=0.0;

  for(i=1;i<n_points-1;i++){
    u_fut[i] = u_init[i] + (r*r/2.0) * (u_init[i+1] - 2.0 * u_init[i] + u_init[i-1]);
      }

  for(i=0;i<n_points;i++){

    u_past[i]=u_init[i];
    u_present[i]=u_fut[i];
  }

  solve(u_past , u_present , u_fut, r);

  return 0;

}

void solve(double *u_past , double *u_present , double *u_fut, double r){
 
  int i;
  int j;

  for(j=0;j<iteraciones;j++){
    for(i=1;i<n_points-1;i++){

      u_fut[i] = (2.0*(1.0-pow(r,2)))*u_present[i] - u_past[i] + (pow(r,2))*(u_present[i+1] +  u_present[i-1]);
    }
    for(i=0;i<n_points;i++){
      u_past[i] = u_present [i];
      u_present[i] = u_fut[i];
    }
  }
  
  for(i=0;i<n_points;i++){

    printf("%f",u_present[i]);
    } 
}
