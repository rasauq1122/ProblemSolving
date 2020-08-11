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
#define ff first
#define ss second
#define int long long
#define str string
#define V(T) vector<T>
#define pb push_back
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
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V) sort(V.begin(),V.end())
#define PR(V) V.erase(unique(V.begin(),V.end()),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define repc(A,B,C) for(int A=(B);A<=(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define lb(V,K) lower_bound(V.begin(),V.end(),K)-V.begin()
#define dd(a,b) !((a)%(b))
#define sc(x) int x;cin>>x
#define sc2(x,y) int x,y;cin>>x>>y
#define sc3(x,y,z) int x,y,z;cin>>x>>y>>z
#define scs(s) str s;cin>>s
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
int io[200001][3], vis[200001], seg[800000];
V(V(int)) v(200001);

void dfs(int now, int h) {
    io[now][0] = ++cnt;
    io[now][2] = h;
    vis[now] = 1;
    rep(i, 0, v[now].size()) if (!vis[v[now][i]]) dfs(v[now][i], h+1);
    io[now][1] = cnt; 
}

int get(int gx, int gy, int nx, int ny, int idx) {
    if (ny < gx || gy < nx) return 0;
    if (gx <= nx && ny <= gy) return seg[idx];
    return get(gx, gy, nx, (nx+ny)/2, idx*2) + get(gx, gy, (nx+ny)/2+1, ny, idx*2+1);
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    while (h < n) h <<= 1;
    rep(i, 1, n) {
        sc2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(m, 1);
    TC() {
        sc2(a,b);
        if (a == 1) {
            int i = io[b][0]+h-1;
            seg[i]++;
            while (i > 1) {
                i /= 2;
                seg[i] = seg[i*2] + seg[i*2+1];
            }
        } else cout << io[b][2]*get(io[b][0],io[b][1],1,h,1) << endl;
    }
}