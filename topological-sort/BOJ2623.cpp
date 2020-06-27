// 2019.12.23

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector < vector < int > > v(1000);
    int n, m, in[1000] = {};
    cin >> n >> m;

    for (int i = 0, j = 0, x, s, f ; i < m ; i++)
    {
        cin >> x;
        for (cin >> s ; j < x-1 ; j++)
        {
            cin >> f;
            v[s-1].push_back(f-1);
            in[f-1]++;
            s = f;
        }
        j = 0;
    }

    queue <int> qi, qo;
    for (int i = 0 ; i < n ; i++) if (!in[i]) qi.push(i);

    while(!qi.empty()) 
    {
        int now = qi.front();
        qi.pop();
        qo.push(now);
        int len = v[now].size();
        for (int i = 0 ; i < len ; i++) if (!--in[v[now][i]]) qi.push(v[now][i]);
    }

    if (qo.size() != n) printf("0");
    else
    {
        while(!qo.empty())
        {
            int now = qo.front();
            printf("%d\n",now+1);
            qo.pop();
        }
    }
    
}