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
#define SHOW1(A,IX,EX) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define mod(A,B) ((A+B)%B)
#define MOD 998244353
using namespace std;

int n, m = 1, k;
V(pii) v;

signed main() {
    IOSFAST();
    cin >> n;   
    rep(i, 0, n) {
        int x;
        cin >> x;
        v.pb({x,i});
    }
    ST(v);
    v.pb({0,0});    
    bool md = false;
    V(pii) pv;
    rep(i, 0, n) {
        if (md) {
            if (v[i].ff != v[i+1].ff) {
                pv.pb({k,v[i].ss});
                md = false;
            }
        }
        else if (v[i].ff == v[i+1].ff) {
            md = true;
            k = v[i].ss;
        }
        else pv.pb({v[i].ss,v[i].ss});
    }
    ST(pv);
    S(pii) s;
    s.push(pv[0]);
    rep(i, 1, pv.size()) {
        if (pv[i].ff < s.top().ss) {
            pii mgd = {s.top().ff, max(pv[i].ss,s.top().ss)};
            s.pop();
            s.push(mgd);
        } 
        else s.push(pv[i]);
    }
    rep(i, 0, s.size()-1) m <<= 1, m %= MOD;
    cout << m;
}   