// 2020.06.30

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

int main() {
    int n, m, x, da = 0;
    cin >> n >> m >> x;
    vector < vector <pii> > v(n+1);
    vector <int> back(n+1, -1);
    for (int i = 0, a, b, c ; i < m ; i++) {
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }

    priority_queue < pii, vector<pii>, greater<pii> > pq;
    pq.push({0, x});
    while (!pq.empty()) {
        int cost = pq.top().ff;
        int vtx = pq.top().ss;
        pq.pop();
        if (back[vtx] != -1) continue;
        back[vtx] = cost;
        int len = v[vtx].size();
        for (int i = 0 ; i < len ; i++) {
            pii next = v[vtx][i];
            if (back[next.ss] != -1) continue;
            pq.push({cost+next.ff, next.ss});
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        priority_queue < pii, vector<pii>, greater<pii> > pq;
        pq.push({0, i});
        vector <bool> chk(n+1);
        while (!pq.empty()) {
            int cost = pq.top().ff;
            int vtx = pq.top().ss;
            pq.pop();
            if (chk[vtx]) continue;
            if (vtx == x) {
                da = max(da, cost+back[i]);
                break;
            }
            chk[vtx] = 1;
            int len = v[vtx].size();
            for (int j = 0 ; j < len ; j++) {
                pii next = v[vtx][j];
                if (chk[next.ss]) continue;
                pq.push({cost+next.ff, next.ss});
            }
        }
    }
    cout << da;
}