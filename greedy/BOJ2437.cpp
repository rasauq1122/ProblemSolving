// 2019.08.30

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, k=1;
  vector < int > v;
  scanf("%d",&n);
  
  for (int i = 0 ; i < n ; i++)
  {
    int k; scanf("%d",&k);
    v.push_back(k);
  }

  sort(v.begin(),v.end());

  for (int i = 0 ; i < n ; i++)
  {
    if( k >= v[i] ) {k += v[i];}
    else {break;}
  }
  printf("%d",k);
}