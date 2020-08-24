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
#define bp              pop_back
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

using namespace std;

int n, r, c;

int dnq(int x, int y, int s, int v) {
    if (s == 1) return v;
    if (x <= r && r < x + s/2 && y <= c && c < y + s/2) {
        return dnq(x, y, s/2, v);
    } 
    if (x <= r && r < x + s/2 && y + s/2 <= c && c < y + s) {
        return dnq(x, y + s/2, s/2, v + (s/2)*(s/2));
    }  
    if (x + s/2 <= r && r < x + s && y <= c && c < y + s/2) {
        return dnq(x + s/2, y, s/2, v + (s/2)*(s/2)*2);
    }
    return dnq(x + s/2, y + s/2, s/2, v + (s/2)*(s/2)*3);
}

signed main() {
    FASTIO();
    cin >> n >> r >> c;

    int h = 1;
    for (int i = 0 ; i < n ; i++) h <<= 1;
    cout << dnq(0, 0, h, 0);
}