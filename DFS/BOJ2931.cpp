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
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define endl         '\n'
#define blk          ' '
#define pii          pair<int,int>
#define piii         pair<int,pii>
#define piiii        pair<pii,pii>
#define ff           first
#define fff          first.first
#define ffs          first.second
#define ss           second
#define ssf          second.first
#define sss          second.second
#define str          string
#define pb           push_back
#define bp           pop_back
#define rsz          resize
#define lb           lower_bound
#define ub           upper_bound
#define mp           make_pair
#define V(T)         vector<T>
#define W(T)         vector<vector<T>>
#define Q(T)         queue<T>
#define S(T)         stack<T>
#define DQ(T)        deque<T>
#define PQ(T)        priority_queue<T>
#define GPQ(T)       priority_queue<T,vector<T>,greater<T>>
#define UID(T)       uniform_int_distribution<T>
#define MS(T)        memset(T,-1,sizeof(T))
#define ZS(T)        memset(T,0,sizeof(T))
#define RANDOM(A,B)  random_device A; mt19937 B(A());
#define BIT(A,B)     (!!((A)&(1LL<<(B))))
#define BITS(A,B,C)  (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define FASTIO()     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC()         int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V)        sort((V).begin(),(V).end())
#define RVS(V)       reverse((V).begin(),(V).end())
#define PR(V)        (V).erase(unique((V).begin(),(V).end()),(V).end())
#define FIN()        freopen("input.txt","r",stdin)
#define FTC()        freopen("input.txt","w",stdout)
#define FOUT()       freopen("output.txt","w",stdout)
#define rep(A,B,C)   for(int A=(B);A<(C);A++)
#define repc(A,B,C)  for(int A=(B);A<=(C);A++)
#define per(A,B,C)   for(int A=(C)-1;A>=(B);A--)
#define loop()       while(true)
#define pump(V)      for(;!(V).empty();(V).pop())
#define dd(a,b)      (!((a)%(b)))
#define all(V)       (V).begin(),(V).end()
#define sz(V)        (int)((V).size())
#define sc(x)        int x;cin>>x
#define sc2(x,y)     int x,y;cin>>x>>y
#define sc3(x,y,z)   int x,y,z;cin>>x>>y>>z
#define sc4(x,y,z,w) int x,y,z,w;cin>>x>>y>>z>>w
#define ssc(s)       str s;cin>>s
#define csc(c)       char c;cin>>c
#define IMAX         ((1LL<<31)-1)
#define LMAX         (((1LL<<62)-1)*2+1)
#define int          long long
#define BIG          1000000007
using namespace std;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
bool safe(int nx, int ny, int gx, int gy) {return 0 <= nx && nx < gx && 0 <= ny && ny < gy;}

const int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};

int n, m, k, h=1, cnt, cnt2, sum, da, so = IMAX;
bool chk[8][4] = {{},
                 {1,0,1,0},
                 {0,1,1,0},
                 {0,1,0,1},
                 {1,0,0,1},
                 {1,1,0,0},
                 {0,0,1,1},
                 {1,1,1,1}}, vis[25][25];
int arr[25][25], bx, by, test[25][25];
Q(pii) q;

void dfs(int x, int y) {
    vis[x][y] = 1;
    if (arr[x][y] == 8) return;
    rep(i, 0, 4) if (chk[arr[x][y]][i]) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!vis[xx][yy]) {
            if (!arr[xx][yy]) bx = xx, by = yy, q.push({x,y});
            else dfs(xx,yy); 
        }
    }
}

signed main() {
    FASTIO();
    cin >> n >> m;
    rep(i, 0, n) {
        ssc(s);
        rep(j, 0, m) {
            if (s[j] == '|') arr[i][j] = 5;
            else if (s[j] == '-') arr[i][j] = 6;
            else if (s[j] == '+') arr[i][j] = 7;
            else if ('1' <= s[j] && s[j] <= '4') arr[i][j] = s[j]-'0';
            else if (s[j] == 'M' || s[j] == 'Z') arr[i][j] = 8;
        }
    }
    rep(i, 0, n) rep(j, 0, m) if (!vis[i][j] && arr[i][j]) dfs(i, j);
    cout << bx+1 << blk << by+1 << blk;
    pump(q) test[q.front().ff][q.front().ss] = 1;
    int x[4] = {};
    rep(i, 0, 4) {
        int xx = bx + dx[i], yy = by + dy[i];
        if (safe(xx,yy,n,m)) x[i] = test[xx][yy];
    }
    int kk = 0;
    repc(i, 1, 7) {
        bool okay = true;
        rep(j, 0, 4) okay &= chk[i][j] == x[j];
        kk = i;
        if (okay) break;
    }
    char c[8] = {0,'1','2','3','4','|','-','+'};
    cout << c[kk];
}