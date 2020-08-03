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

int n, m, k, h=1, cnt, da, so = IMAX;
V(V(int)) v(100001);
int in[100001], st, wei[100001];
bool vis[100001];

void dfs(int i) {
    cout << i << blk;
    vis[i] = true;
    Q(int) q;
    rep(j, 0, v[i].size()) if (!vis[v[i][j]]) q.push(v[i][j]);
    
    if (q.empty()) return;
    else if (q.size() == 1) dfs(q.front());
    else {
        int go;
        for(;!q.empty();q.pop()) if (wei[q.front()]++ == 1) go = q.front();
        dfs(go);
    }
}

signed main() {
    IOSFAST();
    cin >> n;
    rep(i, 0, n-2) {
        int x, y, z;
        cin >> x >> y >> z;
        in[x]++, in[y]++, in[z]++;
        v[x].pb(y), v[x].pb(z);
        v[y].pb(x), v[y].pb(z);
        v[z].pb(x), v[z].pb(y);
    }
    rep(i, 1, n+1) if (in[i] == 1) {
        st = i;
        break;
    }
    rep(i, 0, 2) if (in[v[st][i]] == 2) wei[v[st][i]]++;
    dfs(st);
}