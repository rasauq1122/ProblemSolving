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
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
int arr[100][100], vis[100][100], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int bfs() {
    ZS(vis);
    Q(pii) q, melt;
    q.push({0,0});
    vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().ff, y = q.front().ss;
        q.pop();
        rep(i, 0, 4) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            if (arr[xx][yy]) melt.push({xx,yy});
            else q.push({xx,yy});
        }
    }
    int rtn = k - melt.size();
    while (!melt.empty()) {
        int x = melt.front().ff, y = melt.front().ss;
        arr[x][y] = 0;
        melt.pop();
    }
    if (k) cnt++;
    return rtn;
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> arr[i][j], k += arr[i][j];

    while (int p = bfs()) k = p; 
    cout << cnt << endl << k;
}