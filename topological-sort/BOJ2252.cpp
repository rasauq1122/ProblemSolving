// 2019.12.22

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector <int> v[32000];
int in[32000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0, t, f ; i < m ; i++)
    {
        cin >> t >> f;
        v[t-1].push_back(f-1);
        in[f-1]++;
    }

    queue <int> q;
    for (int i = 0 ; i < n ; i++) if (!in[i]) q.push(i);

    while (!q.empty())
    {
        int now = q.front(), len = v[now].size();
        cout << now+1 << ' ';
        q.pop();
        for (int i = 0 ; i < len ; i++) if (!(--in[v[now][i]])) q.push(v[now][i]);
    }
}