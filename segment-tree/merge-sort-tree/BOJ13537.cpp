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
#define PRINT(V)             {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define PRINT2(V)            {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}
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
#define nl()          cout<<'\n'
#define pfl(x)        cout<<(x)<<'\n'
#define pf2l(x,y)     cout<<(x)<<' '<<(y)<<'\n'
#define pf3l(x,y,z)   cout<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4l(x,y,z,w) cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define cont(x)       {x;continue;}
#define stop(x)       {x;break;}
#define IMAX          ((1LL<<31)-1)
#define LMAX          (((1LL<<62)-1)*2+1)
#define YES           cout<<"YES"<<'\n'
#define NO            cout<<"NO"<<'\n'
#define int           long long
#define MOD           1000000007
using namespace std;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
bool safe(int nx, int ny, int gx, int gy) {return 0 <= nx && nx < gx && 0 <= ny && ny < gy;}

const int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};

int n, m, l, h=1, cnt, cnt2, sum, da, so = IMAX;
V(int) v;
W(int) w; // vector<vector<int>>(2*h)

int get(int gx, int gy, int nx, int ny, int val, int idx) {
    if (nx > gy || ny < gx) return 0; // 못찾음 ㅋㅋ
    if (gx <= nx && ny <= gy) return w[idx].end()-ub(all(w[idx]),val);
    return get(gx, gy, nx, (nx+ny)/2, val, idx*2) + get(gx, gy, (nx+ny)/2+1, ny, val, idx*2+1);
}

signed main() {
    FASTIO();
    rd(n);
    while (h < n) h <<= 1;
    w = wi(2*h); 
    rep(i, 0, h-n) w[h+i].pb(0); // 쓰레기값 넣기
    rep(i, h-n, h) {
        sc(x), w[h+i].pb(x);  // 입력받으면서 루트에 추가
    } 
    per(i, 1, h) { // 세그먼트 트리 구성
        int a = 0, b = 0, c, len = w[i*2].size();
        loop() { // while(true)
            if (a >= len || b >= len) stop(c = a >= len);
            if (w[i*2][a] < w[i*2+1][b]) w[i].pb(w[i*2][a++]);
            else w[i].pb(w[i*2+1][b++]);
        }
        if (c) rep(j, b, len) w[i].pb(w[i*2+1][j]);
        else rep(j, a, len) w[i].pb(w[i*2][j]);
    }
    TC() {
        sc3(a, b, c);
        pfl(get(a+h-n,b+h-n,1,h,c,1));
    }
}