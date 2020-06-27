// 2019.08.29

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b)
{
  if (a > b) {return b;}
  return a;
}

int main()
{
  int se, st, sum = 0;
  scanf("%d %d",&se,&st);
  vector <int> v_se;

  for (int i = 0 ; i < se ; i++)
  {
    int n;
    scanf("%d",&n);
    v_se.push_back(n);
  }
  sort(v_se.begin(),v_se.end());
  int ans = v_se[se-1] - v_se[0];

  vector <int> v_re;
  v_re.push_back(v_se[0]);
  for (int i = 0 ; i < se - 1 ; i++)
  {
    if (v_se[i] != v_se[i+1]) {v_re.push_back(v_se[i+1]);}
  }

  int len = v_re.size();
  vector <int> v_de;
  for (int i = 0 ; i < len - 1 ; i++)
  {
    v_de.push_back(v_re[i]-v_re[i+1]);
  }

  sort(v_de.begin(),v_de.end());

  len = min(st - 1,len - 1);
  for (int i = 0 ; i < len ; i++)
  {
    sum += v_de[i];
  }

  ans += sum;
  printf("%d",ans);
}
