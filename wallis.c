#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

double wallis_pi(int n) 
{
double ans=1.0;
for(int i=1;i<=n;i++) 
{float nr= 4*i*i;

ans= ans*(nr/(nr-1));

} 

return ans*2; 
}
float mc_pi(int n) 
{float c=0.0;
float ans; 

for(int i=1;i<=n;i++) 
{ 
float x= frandom(); 
float y= frandom(); 
printf("%f %f\n ",x,y);
if(sqrt(x*x+y*y)<1) 
c++; 
} 

ans = 4*c/n;
return ans; 
}
