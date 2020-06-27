// 2019.11.15

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define and &&
#define or ||
#define not !
using namespace std;

char c[100] = {};

void pprint(int l)
{
    for (int i = 0 ; i < l ; i++) if (c[i] != 0) printf("%c",c[i]);
    printf("\n");
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.size();

    vector < pair < char, int > > v;
    priority_queue < int > q;
    pair < char, int > p[100] = {};

    for (int i = 0 ; i < len ; i++) v.push_back({s[i],i});
    sort(v.begin(),v.end());

    int cnt = 0;
    q.push(-1);
    for (int i = 0, j = 0 ; ; i++)
    {
        if (j <= v[i].second)
        {
            j = v[i].second;
            p[cnt++] = {j,v[i].first};
            q.push(j);
            v[i] = {0,0};
            if (j == len - 1) break;
        }
    }

    int ri = q.top();
    q.pop();
    int le = q.top();

    for (int i = 0 ; cnt < len ; i++)
    {
        while (ri - le == 1)
        {
            ri = le;
            q.pop();
            le = q.top();
        }

        if (le < v[i].second and v[i].second < ri and v[i].first != 0)
        {
            le = v[i].second;
            q.push(le);
            p[cnt++] = {le,v[i].first};
            v[i] = {0,0};
            i = 0;
        }
    }

    for (int i = 0 ; i < len ; i++)
    {
        c[p[i].first] = p[i].second;
        pprint(len);
    }
}