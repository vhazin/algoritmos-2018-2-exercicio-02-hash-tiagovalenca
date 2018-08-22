#include <stdio.h>

unsigned long int t, y, z, counter = 0;
unsigned long int a, b, x, n, c, d, m;

int main(void) {
  scanf("%lu", &t);
  for(unsigned long int i = 0; i < t; i++){
    scanf("%lu %lu %lu %lu %lu %lu %lu", &a, &b, &x, &n, &c, &d, &m);
    for(unsigned long int j = 0; j <= n; j++){
      z = x + j;
      y = (a*z + b) % m;
      if (y >= c && y <= d){
        counter++;
      }
    }
    printf("%lu\n", counter);
    counter = 0;
  }
  return 0;
}
