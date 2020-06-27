// 2019.08.30

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define and &&
#define or ||
#define not !
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);

  for (int i = 0 ; i < n ; i++)
  {
    int k;
    scanf("%d",&k);
    vector < pair < int, string > > v;
    for (int j = 0 ; j < k ; j++)
    {
      string a;
      cin >> a;
      v.push_back(make_pair(a.size(),a));
    }

    sort(v.begin(),v.end());
    
    bool allig = true;
    for (int j = 0 ; j < k-1 ; j++)
    {
      for (int p = j+1 ; p < k ; p++)
      {
        int len = v[j].first; bool ig = false;
        for (int q = 0 ; q < len ; q++)
        {
          ig = ig or (v[j].second[q] != v[p].second[q]);
          if (ig) {break;}
        }
        allig = allig and ig;
        if (not(allig)) {break;}
      }
      if (not(allig)) {break;}
    }
    if (allig) {printf("YES");}
    else {printf("NO");}

    if (i != n-1) {printf("\n");}
  }
}