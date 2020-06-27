// 2019.09.24

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int loop(string a);

int main()
{
  string a;
  cin >> a;
  printf("%d",loop(a));
}

int ism1(int a)
{
  if (a == -1) {return 51;}
  else {return a;}
}

int loop(string a)
{
  if (a.find("(") == -1) {return a.size();}
  else
  {
    int now = 1, be = a.find("("), bkt = a.find("("), en, len = bkt + 1;
    bool boot = false;
    while (now)
    {
      if (boot) {len++;}
      else {boot = true;}
      bkt = min(ism1(a.substr(len).find(")")),ism1(a.substr(len).find("(")));
      if (a[len+bkt] == '(') {now++;}
      else {now--;}
      len = len + bkt;
    }
    en = len;
    return a.substr(0,max(0,be-1)).size() + (a[be-1] - '0')*loop(a.substr(be+1,en-be-1)) + loop(a.substr(en+1));
  }
}
