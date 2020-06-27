// 2019.10.02

#include <iostream>
#define and &&
#define or ||
using namespace std;

int main()
{
  string s;
  cin >> s;
  s = "00" + s;
  int len = s.size(), round = 1, sum = 0, second = false;
  for (int i = 2 ; i < len ; i++)
  {
    int now;
    if (round <= 10)
    {
      if (s[i] == 'S')
      {
        now = 10;
        round++;
        second = false;
      }
      else if (s[i] == 'P')
      {
        if (s[i-1] == '-') {now = 10;}
        else {now = 10 - s[i-1] + '0';}
        round++;
        second = false;
      }
      else if (s[i] == '-')
      {
        now = 0;
        if (second)
        {
          round++;
          second = false;
        }
        else {second = true;}
      }
      else
      {
        now = s[i] - '0';
        if (second)
        {
          round++;
          second = false;
        }
        else {second = true;}
      }

      sum += now * (1 + (s[i-1] == 'S' or s[i-1] == 'P' ? 1 : 0) + (s[i-2] == 'S' ? 1 : 0));
      // printf("%d\n",sum);
    }
    else
    {
      if (s[i] == 'S') {now = 10;}
      else if (s[i] == 'P')
      {
        if (s[i-1] == '-') {now = 10;}
        else {now = 10 - s[i-1] + '0';}
      }
      else if (s[i] == '-') {now = 0;}
      else {now = s[i] - '0';}

      sum += now * (1 + (round == 11 and s[i-2] == 'S' ? 1 : 0));
      // printf("%d\n",sum);
      round++;
    }
  }
  // printf("\n");
  printf("%d",sum);
}
