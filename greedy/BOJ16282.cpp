// 2019.09.09

#include <stdio.h>

int main()
{
  long long k = 0, n, sum = 0;
  scanf("%lld",&n);
  while (sum < n) {
    k++;
    sum = k;
    for (long long i = 0 ; i < k+1 ; i++) sum += sum+1;
  }
  printf("%lld",k);
}