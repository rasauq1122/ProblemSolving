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
int arr[100][100], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

signed main() {
    IOSFAST();
    cin >> n >> m;
    swap(n,m);
    rep(i, 0, n) {
        scs(s);
        rep(j, 0, m) arr[i][j] = s[j]-'0';
    }
    V(V(V(piii))) v(n,V(V(piii))(m));
    rep(i, 0, n) rep(j, 0, m) rep(k, 0, 4) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m) continue;
        v[i][j].pb({arr[x][y],{x,y}});
    }

    GPQ(piii) pq;
    V(V(int)) dist(n, V(int)(m, IMAX));
    pq.push({0,{0,0}});
    while (!pq.empty()) {
        int cost = pq.top().ff;
        int x = pq.top().ss.ff;
        int y = pq.top().ss.ss;
        pq.pop();
        if (dist[x][y] <= cost) continue;
        dist[x][y] = cost;
        rep(i, 0, v[x][y].size()) {
            piii nxt = v[x][y][i];
            if (dist[nxt.ss.ff][nxt.ss.ss] == IMAX) pq.push({cost+nxt.ff,{nxt.ss.ff,nxt.ss.ss}});
        }
    }
    cout << dist[n-1][m-1];
}