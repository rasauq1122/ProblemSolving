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
#define dd(a,b) !((a)%(b))
#define BIG 1000000007
using namespace std;

int n, m, k;
V(V(int)) v, d;

V(int) getV(int i, int j) {
    if (d[i][j] == -1) {
        V(int) r = {i, j};
        return r;
    }
    V(int) a = getV(i, d[i][j]), b = getV(d[i][j], j);
    rep(x, 0, b.size()) a.pb(b[x]);
    return a;
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    v = V(V(int))(n,V(int)(n,IMAX));
    d = V(V(int))(n,V(int)(n,-1));
    rep(i, 0, m) {
        int x, y, c;
        cin >> x >> y >> c;
        v[x-1][y-1] = min(v[x-1][y-1], c);
    }
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
        if (i == j) continue;
        if (v[i][j] > v[i][k] + v[k][j]) {
            v[i][j] = v[i][k] + v[k][j];
            d[i][j] = k;
        }
    }
    rep(i, 0, n) v[i][i] = IMAX;
    rep(i, 0, n) {
        rep(j, 0, n) cout << (v[i][j] == IMAX ? 0 : v[i][j]) << blk;
        cout << endl;
    }

    rep(i, 0, n) rep(j, 0, n) {
        if (v[i][j] == IMAX) cout << 0 << endl;
        else {
            V(int) k = getV(i,j);
            PR(k);
            cout << k.size() << blk;
            rep(x, 0, k.size()) cout << k[x]+1 << blk;
            cout << endl;
        }
    }
}   