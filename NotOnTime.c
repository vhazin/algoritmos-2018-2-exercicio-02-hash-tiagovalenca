#include <stdio.h>

unsigned long long t, y, z, counter = 0;
unsigned long long a, b, x, n, c, d, m;

int main(void) {
  scanf("%llu", &t);
  for(unsigned long long i = 0; i < t; i++){
    scanf("%llu %llu %llu %llu %llu %llu %llu", &a, &b, &x, &n, &c, &d, &m);
    z = a*x+b;
    if(a==0 && b==0 && c==0){
      counter = n + 1;
    }else if(z>=c && z<=d && m>=d && m>z && m>n && n>=d){
        counter = d-c+1;
    }else{
      for(unsigned long long j = 0; j <= n; j++){
        z = x + j;
        y = (a*z + b) % m;
        if(y >= c && y <= d){
          counter++;
        }
      }
    }
    printf("%llu\n", counter);
    counter = 0;
  }
  return 0;
}
//Tiago Lopes Valença
