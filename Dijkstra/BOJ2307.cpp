// 2020.05.02

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define pii pair<int,int>
#define piii pair<pii,int>
#define ff first
#define ss second

vector < vector <pii> > v(1001);
int n, e, dist[1001][2], init, ans;

int main() {
    cin >> n >> e;
    for (int i = 0, s, f, c ; i < e ; i++) {
        cin >> s >> f >> c;
        v[s].push_back({c,f});
        v[f].push_back({c,s});
    }
    
    priority_queue < piii, vector<piii>, greater<piii> > pq;

    memset(dist, -1, sizeof(dist));
    
    pq.push({{0,1},0});
    while(!pq.empty()) {
        int cost = pq.top().ff.ff, node = pq.top().ff.ss, prev = pq.top().ss;
        pq.pop();
        if (dist[node][0] != -1) continue;
        dist[node][0] = cost;
        dist[node][1] = prev;

        int len = v[node].size();
        for (int i = 0 ; i < len ; i++) if (dist[v[node][i].second][0] == -1) pq.push({{cost+v[node][i].first, v[node][i].second}, node});
    }

    queue < pii > q;
    for (int i = n ; dist[i][1] != 0 ; i = dist[i][1]) q.push({dist[i][1],i});
    init = dist[n][0];

    while (!q.empty()) {
        int v1 = q.front().ff, v2 = q.front().ss;
        q.pop();

        priority_queue < pii, vector <pii>, greater<pii> > pq;
        vector < int > new_dist(n+1, -1);
        pq.push({0,1});
        while (!pq.empty()) {
            int cost = pq.top().ff, node = pq.top().ss;
            pq.pop();
            if (new_dist[node] != -1) continue;
            new_dist[node] = cost;

            int len = v[node].size(); 
            for (int i = 0 ; i < len ; i++) {
                int next = v[node][i].second;
                if (node == v1 && next == v2 || node == v2 && next == v1) continue;
                if (new_dist[next] == -1) pq.push({cost+v[node][i].first, next});
            }
        }

        if (new_dist[n] == -1) {
            cout << -1;
            return 0;
        }

        ans = max(new_dist[n],ans);
    }
    cout << ans-init;
}
