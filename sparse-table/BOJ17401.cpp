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
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define mod(A,B) ((A+B)%B)
#define BIG 1000000007
using namespace std;

int t, n, m, k, h=1, cnt, da, so = IMAX, arr[101][20][20], spt[31][20][20], ans[20][20];

signed main() {
    IOSFAST();
    cin >> t >> n >> k;
    rep(i, 0, n) arr[0][i][i] = 1, ans[i][i] = 1;
    rep(i, 1, t+1) {
        int now[20][20] = {};
        TC() {
            int a, b, c;
            cin >> a >> b >> c;
            now[a-1][b-1] = c;
        }
        rep(a, 0, n) rep(b, 0, n) rep(c, 0, n) arr[i][a][b] += arr[i-1][a][c]*now[c][b]%BIG, arr[i][a][b] %= BIG;   
    }
    rep(x, 0, n) rep(y, 0, n) spt[0][x][y] = arr[t][x][y];
    rep(i, 1, 30) {
        rep(a, 0, n) rep(b, 0, n) rep(c, 0, n) spt[i][a][b] += spt[i-1][a][c]*spt[i-1][c][b]%BIG, spt[i][a][b] %= BIG;
    }

    rep(i, 0, 30) if (BIT(k/t, i)) {
        int now[20][20] = {};
        rep(a, 0, n) rep(b, 0, n) rep(c, 0, n) now[a][b] += ans[a][c]*spt[i][c][b]%BIG, now[a][b] %= BIG;
        rep(x, 0, n) rep(y, 0, n) ans[x][y] = now[x][y];
    }

    int now[20][20] = {};
    rep(a, 0, n) rep(b, 0, n) rep(c, 0, n) now[a][b] += ans[a][c]*arr[k%t][c][b]%BIG, now[a][b] %= BIG;

    rep(x, 0, n) {
        rep(y, 0, n) cout << now[x][y] << blk;
        cout << endl;
    }
}   