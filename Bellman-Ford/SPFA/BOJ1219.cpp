// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
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
#define MS(T) memset(T, -1, sizeof(T))
#define ZS(T) memset(T, 0, sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW1(A,IX,EX) {for(int NI=(IX);NI<=(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define PR(V) V.erase(unique(V.begin(),V.end()),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define lb(V,K) lower_bound(V.begin(),V.end(),K)-V.begin()
#define dd(a,b) !((a)%(b))
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
int st, en;
bool cango[100][100];

V(V(pii)) v;

void dfs(int x, int k) {
    cango[x][k] = 1;
    rep(i, 0, v[k].size()) if (!cango[x][v[k][i].ff]) dfs(x,v[k][i].ff);
}

signed main() {
    IOSFAST();
    cin >> n >> st >> en >> m;
    v = V(V(pii))(n);
    V(int) w(n), d(n,IMAX), upd(n), inq(n);
    rep(i, 0, m) {
        int x, y, c;
        cin >> x >> y >> c;
        v[x].pb({y,c});
    }
    rep(i, 0, n) cin >> w[i];
    rep(i, 0, n) dfs(i,i);

    Q(int) q;
    inq[st] = 1, upd[st] = 1, d[st] = 0, q.push(st);
    bool loop = false;
    while (!q.empty()) {
        int now = q.front();
        q.pop(), inq[now] = 0;
        if (loop) continue;
        rep(i, 0, v[now].size()) {
            pii nxt = v[now][i];
            if (d[nxt.ff] > d[now] + nxt.ss - w[nxt.ff]) {
                d[nxt.ff] = d[now] + nxt.ss - w[nxt.ff];
                if (inq[nxt.ff]) continue;
                if (++upd[nxt.ff] >= n) {
                    if (cango[nxt.ff][en]) return cout << "Gee", 0;
                }
                if (upd[nxt.ff] >= n*n) loop = true;
                inq[nxt.ff] = 1;
                q.push(nxt.ff);
            }
        }
    }

    if (d[en] == IMAX) cout << "gg";
    else cout << -d[en] + w[st];
}