// 2019.09.23

#include <stdio.h>
#include <vector>
#include <algorithm>
#define or ||
#define and &&
#define not !
using namespace std;

int main()
{
  int n, m, lea = 2000000001;
  scanf("%d %d",&n,&m);
  if (m == 0 or n == 1) {printf("0"); return 0;}
  vector <int> v;

  for (int i = 0 ; i < n ; i++)
  {
    int k;
    scanf("%d",&k);
    v.push_back(k);
  }

  sort(v.begin(),v.end());

  vector <int> v2;
  int len = n;
  for (int i = 0 ; i < n - 1 ; i++)
  {
    if (v[i+1] != v[i]) {v2.push_back(v[i+1]-v[i]);}
    else {len--;}
  }
  //for (int i = 0 ; i < len - 1 ; i++)
  //{
  //	printf("%d ",v2[i]);
  //}
  //printf("\n");
  int be = 0, en = 0, now = v2[0];
  //printf("%d %d : %d\n",be,en,now);

  while (true)
  {
    if (now >= m)
    {
      if (lea > now) {lea = now;}
      if (be == len - 2) {break;}
      now -= v2[be]; //printf(" -%d\n",v2[be]);
      if (be == en) {en++; now += v2[en]; //printf(" +%d\n",v2[en]);
      }
      be++;
    }
    else
    {
      if (en == len - 2) {break;}
      else {en++; now += v2[en]; //printf(" +%d\n",v2[en]);
      }
    }
    //printf("%d %d : %d\n",be,en,now);
  }

  printf("%d",lea);

}
