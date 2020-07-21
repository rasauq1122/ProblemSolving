// 2020.07.21

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
using namespace std;

int n, m, k, arr[100001], cnt, da;
bool vis[100001];
V(V(pii)) v;

int main() {
    IOSFAST();
    GPQ(pii) pq;
    cin >> n >> m;
    rep(i, 1, n+1) {
        cin >> arr[i];
        pq.push({arr[i],i});
    }
    v = V(V(pii))(n+1,V(pii)());
    cin >> k;
    rep(i, 0, k) {
        int a, b, x;
        cin >> a >> b >> x;
        v[a].pb({b,x});
    }
    while (cnt < m) {
        int cost = pq.top().ff, vtx = pq.top().ss;
        pq.pop();
        if (vis[vtx]) continue;
        da = max(da, cost), cnt++;
        vis[vtx] = true;
        rep(i, 0, v[vtx].size()) {
            pii nxt = v[vtx][i];
            if (vis[nxt.ff]) continue;
            pq.push({(arr[nxt.ff] -= nxt.ss), nxt.ff});
        }
    }
    cout << da;
}