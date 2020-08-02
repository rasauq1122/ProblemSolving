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
#define SHOW1(A,IX,EX) {cout<<'\n';for(int NI=(IX);NI<=(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
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
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
piii arr[100];
int xyz[100][100][100], dp[100][100][100];
V(int) x, y, z;

int foo(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (dp[x][y][z] != -1) return dp[x][y][z];
    return dp[x][y][z] = xyz[x][y][z] + foo(x-1,y,z) + foo(x,y-1,z) + foo(x,y,z-1) 
                        - foo(x-1,y-1,z) - foo(x-1,y,z-1) - foo(x,y-1,z-1) 
                        + foo(x-1,y-1,z-1);
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    rep(i, 0, n) {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        arr[i] = {x1,{y1,z1}};
        x.pb(x1), y.pb(y1), z.pb(z1);
    }
    ST(x), PR(x), ST(y), PR(y), ST(z), PR(z);
    rep(i, 0, n) {
        int xi = lb(x,arr[i].ff);
        int yi = lb(y,arr[i].ss.ff);
        int zi = lb(z,arr[i].ss.ss);
        xyz[xi][yi][zi]++;
    }
    MS(dp);
    foo(x.size()-1,y.size()-1,z.size()-1);
    rep(i, 0, x.size()) rep(j, 0, y.size()) rep(k, 0, z.size()) if (dp[i][j][k] == m) so = min(so, x[i]+y[j]+z[k]);
    cout << so;
}