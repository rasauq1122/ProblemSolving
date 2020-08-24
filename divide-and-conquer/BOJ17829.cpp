#include <bits/stdc++.h>
 
#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}
 
#define pf0()           cout<<'\n'
#define pf1(x)          cout<<' '<<(x)<<'\n'
#define pf2(x,y)        cout<<' '<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)      cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)    cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)  cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'
 
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
#define pb              push_back
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007
 
using namespace std;

int n, arr[1024][1024];

int dnq(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return arr[x1][y1];
    }
    vi v;
    v.pb(dnq(x1, y1, x1+(x2-x1)/2, y1+(y2-y1)/2));
    v.pb(dnq(x1+(x2-x1)/2+1, y1, x2, y1+(y2-y1)/2));
    v.pb(dnq(x1, y1+(y2-y1)/2+1, x1+(x2-x1)/2, y2));
    v.pb(dnq(x1+(x2-x1)/2+1, y1+(y2-y1)/2+1, x2, y2));
    sort(all(v));
    return v[2];
}

signed main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
        }
    }
    cout << dnq(0,0,n-1,n-1);
}