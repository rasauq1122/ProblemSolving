// 2019.10.04

#include <iostream>
using namespace std;

int memo[1001][1001] = {}; //[sero][garo]

int loop(int garo, int sero);

int min(int garo, int sero)
{
  int min = 1000001;

  for (int i = 1 ; garo >= 2*i ; i++)
  {
    int sum = loop(i,sero) + loop(garo-i,sero);
    if (min > sum) {min = sum;}
  }

  for (int i = 1 ; sero >= 2*i ; i++)
  {
    int sum = loop(garo,i) + loop(garo,sero-i);
    if (min > sum) {min = sum;}
  }

  memo[sero][garo] = min;
  return min;
}

int loop(int garo, int sero)
{
  if (garo < sero) {int temp = garo; garo = sero; sero = temp;}
  if (memo[sero][garo] == 0) {return min(garo,sero);}
  else {return memo[sero][garo];}
}

int main()
{
  int garo, sero;
  scanf("%d %d",&garo,&sero);

  for (int i = 1 ; i <= garo ; i++) {memo[1][i] = i;}
  for (int i = 1 ; i <= sero ; i++) {memo[i][i] = 1;}
  printf("%d",loop(garo,sero));
}
