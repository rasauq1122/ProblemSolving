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
using namespace std;

int n, k, p, cnt = 0, so, da, h = 1, used[200001], arr[200001];

int nodes(int i) {
    if (i <= n) return 1 + nodes(i*2) + nodes(i*2+1);
    return 0;
}

void up(int i, int x) {
    used[x] = 1, arr[i] = x;
    if (i > 1) up(i/2, x-1);
}

void down() {
    Q(int) q;
    q.push(p);
    for(;!q.empty();q.pop()) {
        int t = q.front();
        used[k] = 1;
        arr[t] = k++;
        if (2*t <= n) q.push(2*t);
        if (2*t+1 <= n) q.push(2*t+1);
    }
}

signed main() {
    IOSFAST();
    cin >> n >> k >> p;
    while (h <= p) da++, h <<= 1;
    da--, so = nodes(p)-1;
    if (k > n-so || k <= da) return cout << -1, 0;
    down();
    if (k > 1) up(p/2, da);
    int j = 1;
    rep(i, 1, n+1) if (!arr[i]) {
        while (used[j]) j++;
        used[j] = 1;
        arr[i] = j;
    } 
    rep(i, 1, n+1) cout << arr[i] << endl;
}   