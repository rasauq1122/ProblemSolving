#include <bits/stdc++.h>

#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define rd(x)           cin>>x
#define rd2(x,y)        cin>>x>>y
#define rd3(x,y,z)      cin>>x>>y>>z
#define rd4(x,y,z,w)    cin>>x>>y>>z>>w
#define rd5(x,y,z,w,u)  cin>>x>>y>>z>>w>>u

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

#define endl            '\n'
#define blk             ' '
#define pii             pair<int,int>
#define ff              first
#define ss              second
#define pb              push_back
#define vi              vector<int>
#define wi              vector<vector<int>>
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

using namespace std;

signed main() {
    int n, m;
    rd2(n, m);
    
    vi v(n), v2(n), ps(n+1);
    for (int i = 0, x ; i < n ; i++) {
        rd2(x, v[i]);
        v2[i] = v[i];
    }
    
    sort(all(v));
    v.erase(unique(all(v)),v.end());

    map<int,int> comp;
    for (int i = 0 ; i < v.size() ; i++) {
        comp[v[i]] = i;
    }

    for (int i = 0 ; i < n ; i++) {
        v2[i] = comp[v2[i]];
    }

    for (int i = 0, x, y, c ; i < m ; i++) {
        rd3(x, y, c);
        ps[min(v2[x-1],v2[y-1])] += c;
        ps[max(v2[x-1],v2[y-1])+1] -= c;
    } 
    int da = ps[0];
    for (int i = 1 ; i < n ; i++) {
        ps[i] += ps[i-1];
        da = max(da, ps[i]);
    }
    pf(da);
}