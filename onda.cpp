#include <iostream>
#include <cmath>

double value(double x);

int main(){
  double x = 0.0;
  float v = 0.01;
  double dx = 0.01;
  double dt = 0.0001;
  double c = ((v*v)*(dt * dt)) /(dx*dx);

  int Newx = 1.0/dx +1 ;
  
  double *u_i = new double[Newx];
  double *u_ip = new double[Newx];
  double *u_j = new double[Newx];
  double *u_jp = new double[Newx];

  double u1 = new double[Newx];
  double u2 = new double[Newx];
  double u3 = new double[Newx];
  double u4 = new double[Newx];

  for(int i=0; i<Newx ; i++){
    u_ip[i] = value(x);
    u1[i] = value(x);
    u_j[i] = value(x);
    u_i[i] = value(x);
    u_jp[i] = value(x);
    
    x =i*dx;
  }

  for(int j = 1; j<Newx-1 ; j++){
    for( int i=1; i<Newx-1 ; i++){
	if(j==1){
	  u_i[i] = (c/2)*(u_ip[i+1] - 2*u_ip[i] + u_ip[i-1]) + u_ip[i]; 
	}
	else{
	  u_i[i] = c * (u_ip[i+1] - 2*u_ip[i] + u_ip[i-1]) - u_jp[j-1] + 2*u_ip[i] ;
	}
	u_ip[i] = u_i[i];
      }
    u_jp[j] = u_i[j]; 
    
  }

	x = 0;

     for(int i = 0; i<Newx; i++){
    std::cout << x << " " << u_i[i] << std::endl;
    x += dx;
  }
  return 0;
}
double value(double x){
  if(x==0 || x == 1){
    return 0;
  }
  else{
    return sin(2*3.14*x);
  }
}
