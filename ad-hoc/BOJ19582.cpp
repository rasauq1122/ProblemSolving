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
#define INF             ((1LL<<31)-1)
#define int             long long
#define all(x)          (x).begin(), (x).end()
#define MOD             1000000007

using namespace std;

int n, m, l;

signed main() {
    rd(n);
    wi v(n, vi(2));
    for (int i = 0 ; i < n ; i++) {
        rd2(v[i][0], v[i][1]);
    }

    vi da(n+1);
    
    for (int i = 0 ; i < n ; i++) {
        da[i+1] = max(da[i], v[i][1]);
    }
    
    bool ban = false;
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        if (sum > v[i][0]) {
            if (ban) return pf("Zzz"), 0;
            ban = true;
            if (da[i] > v[i][1] && sum - da[i] <= v[i][0]) {
                sum -= da[i];
                sum += v[i][1];
            }
            continue;
        } 
        sum += v[i][1];
    }
    pf("Kkeo-eok");
}