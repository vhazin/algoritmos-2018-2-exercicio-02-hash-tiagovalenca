#include <stdio.h>

unsigned long int t, y, z, counter = 0;
unsigned long int a, b, x, n, c, d, m;

int main(void) {
  scanf("%lu", &t);
  for(unsigned long int i = 0; i < t; i++){
    scanf("%lu %lu %lu %lu %lu %lu %lu", &a, &b, &x, &n, &c, &d, &m);
    y = (a*x+b) % m;
    if(a==0 && b==0 && c==0){
      counter = n + 1;
    }else if(m==1 && m>=c && m<=d){
     counter = n + 1;
    }else if(y>=c && y<=d && m>d && m>y && n>d && m>n){
      if(c == 0 && d!=1){
        counter = d-c+1;
      }else {
        counter = d-c;
      }
    } else{
      for(unsigned long int j = 0; j <= n; j++){
        z = x + j;
        y = (a*z + b) % m;
        if(y >= c && y <= d){
          counter++;
        }
      }
    }
    printf("%lu\n", counter);
    counter = 0;
  }
  return 0;
}
