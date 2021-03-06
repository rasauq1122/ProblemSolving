// 

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
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C);A>=(B);A--)
#define mod(A,B) ((A+B)%B)
#define BIG ((int)1e9+7)
using namespace std;

int n, m, k;
V(int) sum(8);
V(pii) eg;
V(V(int)) v(8);

int main() {
    IOSFAST();
    cin >> n;
    eg.pb({0,1});
    eg.pb({0,4});
    eg.pb({1,4});
    eg.pb({1,5});
    eg.pb({4,5});
    eg.pb({1,2});
    eg.pb({2,5});
    eg.pb({5,6});
    eg.pb({2,6});
    eg.pb({2,3});
    eg.pb({6,7});
    eg.pb({3,7});
    rep(i, 0, eg.size()) v[eg[i].ff].pb(eg[i].ss), v[eg[i].ss].pb(eg[i].ff);
    
    sum[0] = 1;
    rep(i, 0, n) {
        V(int) cum(8);
        rep(j, 0, 8) rep(k, 0, v[j].size()) cum[j] += sum[v[j][k]], cum[j] %= BIG;
        rep(j, 0, 8) sum[j] = cum[j]; 
    }
    cout << sum[0];
}   