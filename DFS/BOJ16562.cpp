// 2020.07.07

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
using namespace std;

int n, m, k, cost[10001], p;
bool vis[10001];
V(V(int)) v;

int dfs(int p) {
    vis[p] = true;
    int so = cost[p];
    for (int i = 0 ; i < v[p].size() ; i++) if (!vis[v[p][i]]) so = min(so, dfs(v[p][i]));
    return so; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    v = V(V(int))(n+1);
    for (int i = 1 ; i <= n ; i++) cin >> cost[i];
    for (int i = 1, x, y ; i <= m ; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    for (int i = 1 ; i <= n ; i++) if (!vis[i]) p += dfs(i);
    
    if (p > k) cout << "Oh no";
    else cout << p;
}