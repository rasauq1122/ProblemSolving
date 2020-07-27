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
using namespace std;

int n, vis[300001], dp[300001][3];
ll d, g;
V(V(int)) v;

piii dfs(int x) {
    vis[x] = 1;
    rep(i, 0, v[x].size()) if (!vis[v[x][i]]) {
        dp[x][0]++;
        piii nxt = dfs(v[x][i]);
        dp[x][1] += nxt.ff;
        dp[x][2] += nxt.ss.ff + nxt.ss.ss;
    }
    return {dp[x][0], {dp[x][1], dp[x][2]}};
}

void get(int x) {
    vis[x] = 1;
    Q(int) q;
    rep(i, 0, v[x].size()) if (!vis[v[x][i]]) q.push(v[x][i]), get(v[x][i]);
    int chi = q.size()-1, len = v[x].size();
    g += max(1LL*len*(len-1)*(len-2)/6, 0LL);
    while (!q.empty()) d += 1LL*chi*dp[q.front()][0] + dp[q.front()][1], q.pop();
}

int main() {
    IOSFAST();
    cin >> n;
    v = V(V(int))(n+1);
    
    rep(i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    dfs(1);
    memset(vis, 0, sizeof(vis));
    get(1);

    if (d > 3*g) cout << 'D';
    else if (d < 3*g) cout << 'G';
    else cout << "DUDUDUNGA";
}   