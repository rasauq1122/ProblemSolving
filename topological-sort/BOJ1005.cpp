// 2019.12.23

#include <queue>
#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--)
    {
        vector < vector < int > > v(1000);
        queue <int> q;
        bool fin = false;
        int n, k, cost[1000] = {}, wait[1000] = {}, ans[1000] = {}, in[1000] = {}, tg, x, y;
        cin >> n >> k;

        for (int i = 0 ; i < n ; i++)  cin >> cost[i];
        for (int i = 0 ; i < k ; i++) 
        {
            cin >> x >> y;
            v[x-1].push_back(y-1);  
            in[y-1]++;
        }

        cin >> tg;

        for (int i = 0 ; i < n ; i++) if (!in[i]) q.push(i);
        while (!q.empty())
        {
            int now = q.front(), len = v[now].size();
            q.pop();
            ans[now] = cost[now] + wait[now];
            
            for (int i = 0 ; i < len ; i++) 
            {
                wait[v[now][i]] = wait[v[now][i]] < ans[now] ? ans[now] : wait[v[now][i]]; 
                if (!--in[v[now][i]]) 
                {
                    if (v[now][i] != tg-1) q.push(v[now][i]);
                    else
                    {
                        printf("%d\n",cost[v[now][i]]+wait[v[now][i]]);
                        fin = true;
                        break;
                    } 
                }
            }
            if (fin) break;
        }
    }
}