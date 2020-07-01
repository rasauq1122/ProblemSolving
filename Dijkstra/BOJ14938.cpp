// 2020.07.01

#include <iostream>
#include <queue>
using namespace std;

#define pii pair <int, int>
#define ff first
#define ss second

int main() {
    int tem[101], n, m, r, da = 0;

    cin >> n >> m >> r;
    vector < vector < pii > > v(n+1);
    for (int i = 1 ; i <= n ; i++) cin >> tem[i];
    for (int i = 0, x, y, c ; i < r ; i++) {
        cin >> x >> y >> c;
        v[x].push_back({c,y});
        v[y].push_back({c,x});
    }

    for (int i = 1 ; i <= n ; i++) {
        int now = 0;
        vector < bool > vis(n+1);
        priority_queue < pii, vector<pii>, greater<pii> > pq;
        pq.push({0,i});
        while (!pq.empty()) {
            int cost = pq.top().ff;
            int vtx = pq.top().ss;
            pq.pop();
            if (vis[vtx]) continue;
            if (cost > m) continue;
            vis[vtx] = 1;
            now += tem[vtx];
            int len = v[vtx].size();
            for (int j = 0 ; j < len ; j++) {
                pii next = v[vtx][j];
                if (vis[next.ss]) continue;
                pq.push({cost+next.ff, next.ss});
            }
        }
        da = max(da, now);
    }
    cout << da;
}