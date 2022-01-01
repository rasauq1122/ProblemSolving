#include <bits/stdc++.h>

#define prt(V)           {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)          {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define get1d(V,N)       for(int i=0;i<N;i++){cin>>V[i];}
#define get2d(V,N,M)     for(int i=0;i<N;i++){for(int j=0;j<M;j++){cin>>V[i][j];}}
#define getseg(V,N)      for(int i=0;i<N;i++){int a,b;cin>>a>>b;V[i]={a,b};}

#define pf0()            cout<<'\n'
#define pf1(x)           cout<<(x)<<'\n'
#define pf2(x,y)         cout<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)       cout<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)     cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)   cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'
#define pf6(x,y,z,w,u,v) cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<' '<<(v)<<'\n'
#define pflush()         cout<<flush

#define yes()            cout<<"YES"<<'\n'
#define no()             cout<<"NO"<<'\n'
#define yesif(x)         cout<<((x)?"YES":"NO")<<'\n'
#define impif(x)         if(x){cout<<-1<<'\n';continue;}

#define rep(i,j,k)       for(int i=(j);i<(k);i++)
#define repe(i,j,k)      for(int i=(j);i<=(k);i++)
#define per(i,j,k)       for(int i=(k)-1;i>=(j);i--)
#define pere(i,j,k)      for(int i=(k);i>=(j);i--)

#define sz(a)            (int)((a).size())

#define TC()             int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO()         ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FIX(a)        	 cout<<fixed;cout.precision(a);

#define pii              pair<int,int>
#define piii             pair<int,pair<int,int>>
#define ff               first
#define ss               second
#define lbound           lower_bound
#define ubound           upper_bound

#define vi               vector<int>
#define vp               vector<pair<int,int>>
#define vpp              vector<pair<int,pair<int,int>>>
#define wi               vector<vector<int>>
#define wp               vector<vector<pair<int,int>>>
#define wpp              vector<vector<pair<int,pair<int,int>>>>

#define pqueue           priority_queue

#define pb               push_back
#define bp               pop_back
#define mp               make_pair
#define itos             to_string
#define all(v)           (v).begin(), (v).end()

#define press(v)         (v).erase(unique((v).begin(),(v).end()),(v).end())
#define BIT(a,b)      	 (((a)>>(b))&1)
#define BITS(a,b,c)   	 (((a)>>(b))&((1LL<<(c)-(b)+1)-1))
#define dxdy(dx,dy)      int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}

#define INF              ((1LL<<31)-1)
#define MOD              1000000007
#define MOD2             998244353

#define endl             '\n'
#define blk              ' '

#define int              long long

#define IF()             freopen("input.txt","r",stdin)
#define TF()             freopen("input.txt","w",stdout)
#define OF()             freopen("output.txt","w",stdout)

#define RANDOM()         random_device rd;mt19937 seed(rd())
// int-random-value    : uniform_int_distribution<int> gen(min,max);
// double-random-value : uniform_real_distribution<double> gen(min,max);
// how-to-get-value    : gen(seed)

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
int gcd(int a, int b) {return b ? gcd(b,a%b) : a;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;};

using namespace std;



signed main() {
    FASTIO();
    
}