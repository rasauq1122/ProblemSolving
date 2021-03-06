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

int n, m, l, cnt;
wi sub, adj;
vi vis;

void dfs(int i) {
    sub[i][0] = ++cnt;
    vis[i] = true;

    for (int j = 0 ; j < adj[i].size() ; j++) {
        int nxt = adj[i][j];

        if (!vis[nxt]) {
            dfs(nxt);
        }
    }

    sub[i][1] = cnt;
}

signed main() {
    FASTIO();
    cin >> n >> m >> l;
    sub = wi(n+1, vi(2));
    adj = wi(n+1);
    vis = vi(n+1);

    for (int i = 1, x, y ; i < n ; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(m);

    for (int i = 0, x ; i < l ; i++) {
        cin >> x;
        cout << (sub[x][1]-sub[x][0]+1) << endl;
    }
}