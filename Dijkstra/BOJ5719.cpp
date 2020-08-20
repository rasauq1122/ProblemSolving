#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define PRT(V) {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define PRT2(V) {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    while (1) {
        int n, m, st, en;
        cin >> n >> m;

        if (!n && !m) break;

        cin >> st >> en;

        vector<vector<piii>> w(n), iw(n); // adj-list
        vector<pii> edge(m);
        vector<int> ban(m), par(n);
        for (int i = 0, x, y, c ; i < m ; i++) {
            cin >> x >> y >> c;
            w[x].push_back({y,{c,i}});
            iw[y].push_back({x,{c,i}});
            edge[i] = {x,y};
        }   

        vector<int> dist(n, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.push({0, st});
        while (pq.size()) {
            int now = pq.top().ss;
            int cost = pq.top().ff;
            pq.pop();
            
            if (dist[now] != -1) continue;   
            
            dist[now] = cost;
            for(int i = 0 ; i < w[now].size() ; i++) {
                piii nxt = w[now][i];
                
                if (dist[nxt.ff] != -1) continue;
                pq.push({nxt.ss.ff + cost, nxt.ff});
            }
        }

        if (dist[en] == -1) {
            cout << -1 << endl;
            continue;
        }

        queue <int> q;
        q.push(en);
        while (q.size()) {
            int now = q.front();
            q.pop();

            for(int i = 0 ; i < iw[now].size() ; i++) {
                piii nxt = iw[now][i];
                if (dist[nxt.ff] + nxt.ss.ff == dist[now]) {
                    q.push(nxt.ff);
                    ban[nxt.ss.ss] = 1;
                } 
            }
        }

        dist = vector<int>(n,-1);
        pq.push({0, st});
        while (pq.size()) {
            int now = pq.top().ss;
            int cost = pq.top().ff;
            pq.pop();
            
            if (dist[now] != -1) continue;   
            
            dist[now] = cost;
            for(int i = 0 ; i < w[now].size() ; i++) {
                piii nxt = w[now][i];
                
                if (ban[nxt.ss.ss]) continue;
                if (dist[nxt.ff] != -1) continue;
                pq.push({nxt.ss.ff + cost, nxt.ff});
            }
        }

        cout << dist[en] << endl;
    }
}