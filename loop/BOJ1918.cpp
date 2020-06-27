// 2019.09.30

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define and &&
#define or ||
#define not !
using namespace std;

char giho(char c)
{
  if (c == '+') {return '1';}
  if (c == '-') {return '2';}
  if (c == '*') {return '3';}
  if (c == '/') {return '4';}
  if (c == '0') {return '\0';}
  return c;
}

char giho2(char c)
{
  if (c == '0') {return '\0';}
  if (c == '1') {return '+';}
  if (c == '2') {return '-';}
  if (c == '3') {return '*';}
  if (c == '4') {return '/';}
  return c;
}

string hey(string a)
{
  vector < pair < int , int > > v;
  vector < int > v2;
  v2.push_back(-1);
  int len = a.size(), post = -200, pre = 0, n = 1;
  for (int i = 0 ; i < len ; i++)
  {
    if (a[i] == '+' or a[i] == '-')
    {
      pre++;
      v.push_back(make_pair(pre,n));
      v2.push_back(i);
      n++;
    }
    if (a[i] == '*' or a[i] == '/')
    {
      post++;
      v.push_back(make_pair(post,n));
      v2.push_back(i);
      n++;
    }
  }
  v2.push_back(len);
  sort(v.begin(),v.end());
  for (int i = 0 ; i < n - 1 ; i++)
  {
    int be = v[i].second - 1, en = v[i].second + 1, now = v2[v[i].second];
    v2[v[i].second] = -2;

    while (v2[be] == -2) {be--;} be = v2[be];
    while (v2[en] == -2) {en++;} en = v2[en];

    a = a.substr(0,now) + a.substr(now+1,en-now-1) + giho(a[now]) + a.substr(en);
  }

  return a;
}

int main()
{
  string a;
  cin >> a;
  a = "(" + a + ")";
  vector < pair < int , pair < int , pair < int, int > > > > v;
  int dep = 0, stk[100] = {}, len = a.size(), n = 0;

  for (int i = 0 ; i < len ; i++)
  {
    if (a[i]  == '(')
    {
      dep++;
      stk[dep-1]++;
      v.push_back(make_pair(0,make_pair(dep*(-1),make_pair(stk[dep-1],i))));
      n++;
    }
    if (a[i] == ')')
    {
      dep--;
      v.push_back(make_pair(1,make_pair((dep+1)*(-1),make_pair(stk[dep],i))));
    }
  }
  sort(v.begin(),v.end());

  vector < pair < int , int > > v2;
  for (int i = 0 ; i < n ; i++)
  {
    v2.push_back(make_pair(v[i].second.second.second,v[i+n].second.second.second));
  }

  for (int i = 0 ; i < n ; i++)
  {
    a = a.substr(0,v2[i].first) + '0' + hey(a.substr(v2[i].first+1,v2[i].second-v2[i].first-1)) + '0' + a.substr(v2[i].second+1);
  }

  string b = "";

  for (int i = 0 ; i < len ; i++)
  {
    b = b + giho2(a[i]);
  }
  for (int i = 0 ; i < b.size() ; i++)
  {
  	if (b[i] == '\0') {continue;}
  	cout << b[i];
  }
  //cout << b;
}
