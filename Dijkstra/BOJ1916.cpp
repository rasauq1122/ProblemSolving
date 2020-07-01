// 2020.07.01

#include <iostream>
#include <algorithm>
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
#define GPQ(T) priority_queue< T, vector < T >, greater< T > >
#define Q(T) queue<T>
#define S(T) stack<T>
using namespace std;

int n, m, be, en;

int main() {
    cin >> n >> m;
    V(V(pii)) v(n+1);
    for (int i = 0, x, y, c ; i < m ; i++) {
        cin >> x >> y >> c;
        v[x].pb({c,y});
    }
    GPQ(pii) pq;
    V(int) vis(n+1, -1);
    cin >> be >> en;
    pq.push({0,be});
    while (!pq.empty()) {
        int cost = pq.top().ff;
        int vtx = pq.top().ss;
        pq.pop();
        if (vis[vtx] != -1) continue;
        vis[vtx] = cost;
        int len = v[vtx].size();
        for (int i = 0 ; i < len ; i++) {
            pii next = v[vtx][i];
            if (vis[next.ss] != -1) continue;
            pq.push({cost+next.ff, next.ss});
        }
    }
    cout << vis[en];
}