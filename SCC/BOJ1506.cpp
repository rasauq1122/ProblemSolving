// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define endl '\n'
#define blk ' '
#define pii pair<int,int>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define ff first
#define fff first.first
#define ffs first.second
#define ss second
#define ssf second.first
#define sss second.second
#define int long long
#define str string
#define V(T) vector<T>
#define W(T) vector<vector<T>>
#define pb push_back
#define mp make_pair
#define frt front
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>
#define IMAX ((1LL<<31)-1)
#define LMAX (((1LL<<62)-1)*2+1)
#define MS(T) memset(T,-1,sizeof(T))
#define ZS(T) memset(T,0,sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW1(A,IX,EX) {for(int NI=(IX);NI<(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V) sort(V.begin(),V.end())
#define RVS(V) reverse(V.begin(),V.end())
#define PR(V) V.erase(unique(V.begin(),V.end()),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define repc(A,B,C) for(int A=(B);A<=(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define lb(V,K) lower_bound(V.begin(),V.end(),K)-V.begin()
#define dd(a,b) (!((a)%(b)))
#define sz(V) (int)(V.size())
#define sf(x) int x;cin>>x
#define sf2(x,y) int x,y;cin>>x>>y
#define sf3(x,y,z) int x,y,z;cin>>x>>y>>z
#define sf4(x,y,z,w) int x,y,z,w;cin>>x>>y>>z>>w
#define sfs(s) str s;cin>>s
#define sfc(c) char c;cin>>c
#define BIG 1000000007
using namespace std;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
bool safe(int nx, int ny, int gx, int gy) {return 0 <= nx && nx < gx && 0 <= ny && ny < gy;}

const int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};

int n, m, k, h=1, cnt, sum, da, so = IMAX;
W(int) v(100);
V(int) arr(100), vis(100), scc(100);
int cnt2;
S(int) s;

int dfs(int vtx) {
    int so = vis[vtx] = ++cnt;
    s.push(vtx);

    rep(i, 0, v[vtx].size()) {
        int nxt = v[vtx][i];
        if (!vis[nxt]) so = min(so, dfs(nxt));
        else if (!scc[nxt]) so = min(so, vis[nxt]);
    }

    if (so == vis[vtx]) {
        cnt2++;
        while (true) {
            int k = s.top();
            s.pop();
            scc[k] = cnt2;
            if (k == vtx) break;
        }
    }

    return so;
}

signed main() {
    FASTIO();
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n) {
        sfs(s);
        rep(j, 0, n) if (s[j] == '1') v[i].pb(j);
    }

    rep(i, 0, n) if (!vis[i]) dfs(i);

    W(int) sccv(cnt2+1);
    rep(i, 0, n) sccv[scc[i]].pb(i);
    repc(i, 1, cnt2) {
        int so = IMAX;
        rep(j, 0, sccv[i].size()) so = min(so, arr[sccv[i][j]]);
        sum += so; 
    }
    cout << sum;
}