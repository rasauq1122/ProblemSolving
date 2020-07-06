// 2020.07.06

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

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    V(V(pii)) v(n+1);
    for (int i = 0, x, y, c ; i < m ; i++) {
        cin >> x >> y >> c;
        v[x].pb({y,0});
        v[y].pb({x,!c});
    }
    V(V(int)) vis(n+1, V(int)(n+1,-1));
    for (int i = 1 ; i <= n ; i++) {
        GPQ(pii) pq;
        pq.push({0,i});
        while (!pq.empty()) {
            int cost = pq.top().ff;
            int vtx = pq.top().ss;
            pq.pop();
            if (vis[i][vtx] != -1) continue;
            vis[i][vtx] = cost;
            int len = v[vtx].size();
            for (int j = 0 ; j < len ; j++) {
                pii next = v[vtx][j];
                if (vis[i][next.ff] != -1) continue;
                pq.push({cost+next.ss, next.ff});
            }
        }
    }
    cin >> k;
    for (int i = 0, x, y ; i < k ; i++) {
        cin >> x >> y;
        cout << vis[x][y] << '\n';
    }
}