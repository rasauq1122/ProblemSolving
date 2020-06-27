// 2020.05.02

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define piib pair<pii,bool>
#define ff first
#define ss second

vector < vector <pii> > v(4001);
ll n, e, dist[4001][3], init, ans;

int main() {
    cin >> n >> e;
    for (ll i = 0, s, f, c ; i < e ; i++) {
        cin >> s >> f >> c;
        v[s].push_back({c,f});
        v[f].push_back({c,s});
    }
    
    priority_queue < pii, vector<pii>, greater<pii> > pq;

    memset(dist, -1, sizeof(dist));
    
    pq.push({0,1});
    while(!pq.empty()) {
        ll cost = pq.top().ff, node = pq.top().ss;
        pq.pop();
        if (dist[node][0] != -1) continue;
        dist[node][0] = cost;

        ll len = v[node].size();
        for (ll i = 0 ; i < len ; i++) if (dist[v[node][i].ss][0] == -1) pq.push({cost+2*v[node][i].ff, v[node][i].ss});
    }

    priority_queue < piib, vector<piib>, greater<piib> > pq2;
    pq2.push({{0,1},1});
    while (!pq2.empty()) {
        ll cost = pq2.top().ff.ff, node = pq2.top().ff.ss;
        bool can_run = pq2.top().ss;
        pq2.pop();

        if (dist[node][1+can_run] != -1) continue;
        dist[node][1+can_run] = cost;

        ll len = v[node].size();
        for (ll i = 0 ; i < len ; i++) if (dist[v[node][i].ss][1+!can_run] == -1) pq2.push({{cost+(can_run ? 1 : 4)*v[node][i].ff, v[node][i].ss}, !can_run});
    }

    for (ll i = 1 ; i <= n ; i++) if (dist[i][1]*dist[i][2] <= 0) dist[i][1] = dist[i][2] = -dist[i][1]*dist[i][2];
    ll sum = 0;
    for (ll i = 1 ; i <= n ; i++) sum += (dist[i][0] < min(dist[i][1],dist[i][2]));
    cout << sum;
}