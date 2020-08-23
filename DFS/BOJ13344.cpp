#include <bits/stdc++.h>

#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define pf(x)           cout<<(x)
#define pfb(x)          cout<<(x)<<' '
#define pf1(x)          cout<<(x)<<'\n'
#define pf2(x,y)        cout<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)      cout<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)    cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)  cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define bpf1(x)         cout<<' '<<(x)<<'\n'
#define bpf2(x,y)       cout<<' '<<(x)<<' '<<(y)<<'\n'
#define bpf3(x,y,z)     cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define bpf4(x,y,z,w)   cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define bpf5(x,y,z,w,u) cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define TC()            int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO()        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl            '\n'
#define blk             ' '
#define pii             pair<int,int>
#define ff              first
#define ss              second
#define vi              vector<int>
#define vp              vector<pair<int,int>>
#define wi              vector<vector<int>>
#define wp              vector<vector<pair<int,int>>>
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

using namespace std;

int n, m, cnt;
wi adj, adj2;
vp v;
vi vis, vis2, chk;

void dfs(int i, int cnt) {
    vis[i] = cnt;

    for (int j = 0 ; j < adj[i].size() ; j++) {
        int nxt = adj[i][j];
 
        if (!vis[nxt]) {
            dfs(nxt, cnt);
        }
    }
}

bool dfs2(int i) {
    if (chk[i]) return true;
    if (vis2[i]) return false;
    
    vis2[i] = 1; 
    chk[i] = 1;

    for (int j = 0 ; j < adj2[i].size() ; j++) {
        if (dfs2(adj2[i][j])) {
            return true;
        } 
    }

    chk[i] = 0;
    return false;
}

signed main() {
    // FASTIO();
    
    cin >> n >> m;
    adj = wi(n);
    vis = vi(n);

    for (int i = 0 ; i < m ; i++) {
        int x, y;
        char c;

        cin >> x >> c >> y;
        
        if (c == '=') {
            adj[x].push_back(y);
            adj[y].push_back(x);
        } 
        else {
            v.push_back({x,y});
        }
    }

    for (int i = 0 ; i < n ; i++) {
        if (!vis[i]) {
            dfs(i, ++cnt);
        }
    }

    adj2 = wi(cnt+1);
    vis2 = vi(cnt+1);
    chk = vi(cnt+1);
    for (int i = 0 ; i < v.size() ; i++) {
        if (vis[v[i].ff] == vis[v[i].ss]) {
            return cout << "inconsistent", 0;
        }

        adj2[vis[v[i].ff]].push_back(vis[v[i].ss]);
    }

    bool cyc = false;
    for (int i = 1 ; i <= cnt ; i++) {
        if (!vis2[i]) {
            cyc |= dfs2(i); 
        }
    }

    if (cyc) cout << "inconsistent";
    else cout << "consistent";
}