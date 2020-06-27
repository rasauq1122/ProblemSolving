// 2020.05.02

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

vector < vector <pii> > v(801);
int n, e, dist[801][3], v1, v2, ans[2] = {1000000, 1000000};

int main() {
    cin >> n >> e;
    for (int i = 0, s, f, c ; i < e ; i++) {
        cin >> s >> f >> c;
        v[s].push_back({c,f});
        v[f].push_back({c,s});
    }
    cin >> v1 >> v2;
    
    priority_queue < pii, vector<pii>, greater<pii> > pq;

    memset(dist, -1, sizeof(dist));
    
    for (int j = 0, start ; j < 3 ; j++) {
        if (j == 0) start = 1;
        else if (j == 1) start = v1;
        else start = v2;

        pq.push({0,start});
        while(!pq.empty()) {
            int cost = pq.top().ff, node = pq.top().ss;
            pq.pop();
            if (dist[node][j] != -1) continue;
            dist[node][j] = cost;

            int len = v[node].size();
            for (int i = 0 ; i < len ; i++) if (dist[v[node][i].second][j] == -1) pq.push({cost+v[node][i].first, v[node][i].second});
        }
    }

    if (dist[v1][0] != -1 && dist[v2][1] != -1 && dist[n][2] != -1) ans[0] = dist[v1][0] + dist[v2][1] + dist[n][2];
    if (dist[v2][0] != -1 && dist[v1][2] != -1 && dist[n][1] != -1) ans[1] = dist[v2][0] + dist[v1][2] + dist[n][1];

    int result = min(ans[0],ans[1]);
    cout << (result == 1000000 ? -1 : result);
}
