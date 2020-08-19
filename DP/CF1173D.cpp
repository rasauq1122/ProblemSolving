// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <random>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define SHOW(A,IX,EX)        {for(int NI=(IX);NI<(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define PRT(V)               {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define PRT2(V)              {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}
#define endl          '\n'
#define blk           ' '
#define pii           pair<int,int>
#define piii          pair<int,pii>
#define piiii         pair<pii,pii>
#define ff            first
#define fff           first.first
#define ffs           first.second
#define ss            second
#define ssf           second.first
#define sss           second.second
#define str           string
#define pb            push_back
#define bp            pop_back
#define lb            lower_bound
#define ub            upper_bound
#define rvs           reverse
#define mp            make_pair
#define clr           clear
#define vi(n)         vector<int>(n)
#define vi2(n,m)      vector<vector<int>>(n,vector<int>(m))
#define wi(n)         vector<vector<int>>(n)
#define wi2(n,m)      vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m))
#define wp(n)         vector<vector<pair<int,int>>>(n)
#define wp2(n,m)      vector<vector<pair<int,pair<int,int>>>>(n,vector<pair<int,pair<int,int>>>(m))
#define V(T)          vector<T>
#define W(T)          vector<vector<T>>
#define Q(T)          queue<T>
#define S(T)          stack<T>
#define DQ(T)         deque<T>
#define PQ(T)         priority_queue<T>
#define GPQ(T)        priority_queue<T,vector<T>,greater<T>>
#define UID(T)        uniform_int_distribution<T>
#define MS(V)         memset(V,-1,sizeof(V))
#define ZS(V)         memset(V,0,sizeof(V))
#define FL(V,A)       fill((V).begin(),(V).end(),(A))
#define RANDOM(A,B)   random_device A; mt19937 B(A());
#define BIT(A,B)      (!!((A)&(1LL<<(B))))
#define BITS(A,B,C)   (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define FASTIO()      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC()          int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V)         sort((V).begin(),(V).end())
#define RVS(V)        reverse((V).begin(),(V).end())
#define PR(V)         (V).erase(unique((V).begin(),(V).end()),(V).end())
#define FIN()         freopen("input.txt","r",stdin)
#define FTC()         freopen("input.txt","w",stdout)
#define FOUT()        freopen("output.txt","w",stdout)
#define rep(A,B,C)    for(int A=(B);A<(C);A++)
#define repc(A,B,C)   for(int A=(B);A<=(C);A++)
#define per(A,B,C)    for(int A=(C)-1;A>=(B);A--)
#define loop()        while(true)
#define pump(V)       for(;!(V).empty();(V).pop())
#define dd(a,b)       (!((a)%(b)))
#define all(V)        (V).begin(),(V).end()
#define sz(V)         (int)((V).size())
#define sc(x)         int x;cin>>x
#define sc2(x,y)      int x,y;cin>>x>>y
#define sc3(x,y,z)    int x,y,z;cin>>x>>y>>z
#define sc4(x,y,z,w)  int x,y,z,w;cin>>x>>y>>z>>w
#define ssc(s)        str s;cin>>s
#define ssc2(s,t)     str s,t;cin>>s>>t
#define csc(c)        char c;cin>>c
#define rd(x)         cin>>x
#define rd2(x,y)      cin>>x>>y
#define rd3(x,y,z)    cin>>x>>y>>z
#define rd4(x,y,z,w)  cin>>x>>y>>z>>w
#define pf(x)         cout<<(x)
#define pf0()         cout<<'\n'
#define pf1(x)        cout<<(x)<<'\n'
#define pf2(x,y)      cout<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)    cout<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)  cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define cont(x)       {x;continue;}
#define stop(x)       {x;break;}
#define IMAX          ((1LL<<31)-1)
#define LMAX          (((1LL<<62)-1)*2+1)
#define YES           cout<<"YES"<<'\n'
#define NO            cout<<"NO"<<'\n'
#define int           long long
#define MOD           998244353
using namespace std;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
bool safe(int nx, int ny, int gx, int gy) {return 0 <= nx && nx < gx && 0 <= ny && ny < gy;}

const int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};

int n, m, l, h=1, cnt, cnt2, sum, da, so = IMAX;
int dp[200001], fct[200001], root = 1, vis[200001]; 
W(int) w;

int foo(int i) {
    if (dp[i] != -1) return dp[i];
    vis[i] = 1;
    int rtn = 1, cnt = 0;
    rep(j, 0, w[i].size()) {
        int nxt = w[i][j];
        if (!vis[nxt]) cnt++, rtn *= foo(nxt), rtn %= MOD;
    }
    return dp[i] = rtn*fct[cnt + (root != i)]%MOD;
}

signed main() {
    FASTIO();
    rd(n);
    w = wi(n+1);
    rep(i, 1, n) {
        sc2(x, y);
        w[x].pb(y), w[y].pb(x);
    }
    fct[0] = 1;
    repc(i, 1, 200000) fct[i] = i*fct[i-1]%MOD;
    MS(dp);
    pf(n*foo(1)%MOD);
}