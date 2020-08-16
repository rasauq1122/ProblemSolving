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
#define SHOW1(A,IX,EX)       {for(int NI=(IX);NI<(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
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
#define mp            make_pair
#define clr           clear
#define vc(T,n)       vector<T>(n)
#define wc(T,n)       vector<vector<T>>(n)
#define vc2(T,n,m)    vector<vector<T>>(n,vector<T>(m))
#define vc3(T,n,m,l)  vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(l)))               
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
#define SET(V,A)      fill((V).begin(),(V).end(),(A))
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
#define pf(x)         cout<<(x)<<' '
#define pf2(x,y)      cout<<(x)<<' '<<(y)<<' '
#define pf3(x,y,z)    cout<<(x)<<' '<<(y)<<' '<<(z)<<' '
#define pf4(x,y,z,w)  cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '
#define nl()          cout<<'\n'
#define pfl(x)        cout<<(x)<<'\n'
#define pf2l(x,y)     cout<<(x)<<'\n'<<(y)<<'\n'
#define pf3l(x,y,z)   cout<<(x)<<'\n'<<(y)<<'\n'<<(z)<<'\n'
#define pf4l(x,y,z,w) cout<<(x)<<'\n'<<(y)<<'\n'<<(z)<<'\n'<<(w)<<'\n'
#define com(x,y)      x,y;
#define cont(x)       {x;continue;}
#define stop(x)       {x;break;}
#define IMAX          ((1LL<<31)-1)
#define LMAX          (((1LL<<62)-1)*2+1)
#define YES()         cout<<"YES"<<'\n'
#define NO()          cout<<"NO"<<'\n'
#define int           long long
#define BIG           1000000007
using namespace std;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
bool safe(int nx, int ny, int gx, int gy) {return 0 <= nx && nx < gx && 0 <= ny && ny < gy;}

const int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};

int n, m, l, h=1, cnt, cnt2, sum, da, so = IMAX;
V(int) v;
W(int) w;

signed main() {
    FASTIO();
    cin >> n;
    unsigned long long lo = 0, hi = (n > 4e+9 ? 4e+9 : n);
    while (hi - lo > 1) {
        unsigned long long mid = (lo+hi)/2;
        if (mid*mid >= n) hi = mid;
        else lo = mid;
    }
    pf(hi);
}