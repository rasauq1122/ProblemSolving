// 2019.12.30

#include <iostream>
#include <utility>
#include <stack>
using namespace std;

#define pii pair <int, int>
#define ff first
#define ss second

pii hg[100][10001];
bool vis[100][10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int top[100] = {};
    for (int i = 0 ; i < 100 ; i++) hg[i][0] = {i,-1};
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;

    for (int i = 0, x, y ; i < m ; i++)
    {
        cin >> x >> y;
        hg[y][top[y]+1] = {x,top[x]};
        top[y]++;
    }

    cin >> sx >> sy >> ex >> ey;
    stack < pii > s;
    for (int i = sy ; i >= 0 ; i--) 
    {
        s.push({sx,i});
        vis[sx][i] = true;
    }
    while (!s.empty())
    {
        pii now = s.top(), chk = hg[now.ff][now.ss];
        s.pop();
        if (now.ff == ex && now.ss == ey)
        {
            cout << 1;
            return 0;
        }
        for (int i = chk.ss ; i >= 0 ; i--)
        {
            if (vis[chk.ff][i]) break;
            else
            {
                s.push({chk.ff,i});
                vis[chk.ff][i] = true;
            }
        }
    }
    cout << 0;
}