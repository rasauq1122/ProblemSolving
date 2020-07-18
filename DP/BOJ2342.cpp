// 2020.07.18

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define blk ' '
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define IMAX ((1LL<<31)-1)
#define LMAX (((1LL<<62)-1)*2+1)
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define rep(A,B,C) for(int A=B;A<C;A++)
#define per(A,B,C) for(int A=C;A>=B;A--) 
#define mod(A,B) ((A+B)%B)
using namespace std;

int x, so = IMAX, dp[100001][5][5];
V(int) v;

int mov(int a, int b) {
    if (!a) return 2;
    if (a == b) return 1;
    if (abs(a-b) == 2) return 4;
    return 3;
}

int foo(int x, int a, int b) {
    if (!x) return (a == 0 && b == 0) ? 0 : 1e6;
    if (a == b) return 1e6;
    if (v[x] != a && v[x] != b) return 1e6;
    if (dp[x][a][b] != -1) return dp[x][a][b];

    int so = 1e6;
    if (a) rep(i, 0, 5) so = min(so, foo(x-1, i, b) + mov(i,a)); 
    if (b) rep(i, 0, 5) so = min(so, foo(x-1, a, i) + mov(i,b));
    return dp[x][a][b] = so;
}

int main() {
    IOSFAST();
    cin >> x;
    v.pb(0);
    while (x) {
        v.pb(x);
        cin >> x;
    } 
    MS(dp);
    rep(i, 0, 5) so = min(so, foo(v.size()-1, i, v.back()));
    cout << so;
}