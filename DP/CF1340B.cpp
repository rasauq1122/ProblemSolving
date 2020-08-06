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
#define MS(T) memset(T,-1,sizeof(T))
#define ZS(T) memset(T,0,sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW1(A,IX,EX) {for(int NI=(IX);NI<(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V) sort(V.begin(),V.end())
#define PR(V) V.erase(unique(V.begin(),V.end()),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define repc(A,B,C) for(int A=(B);A<=(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define lb(V,K) lower_bound(V.begin(),V.end(),K)-V.begin()
#define dd(a,b) !((a)%(b))
#define sc(x) int x;cin>>x
#define sc2(x,y) int x,y;cin>>x>>y
#define sc3(x,y,z) int x,y,z;cin>>x>>y>>z
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
int hsh[128][10], seg[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
int arr[2000];
str dp[2000][2000];

str btk(int i, int k) {
    if (i == n) return (k ? "-1" : "");
    if (dp[i][k] != "") return dp[i][k];
    per(j, 0, 10) {
        if (hsh[arr[i]][j] != -1 && hsh[arr[i]][j] <= k) {
            str p = btk(i+1, k - hsh[arr[i]][j]);
            if (p == "-1") continue;
            return dp[i][k] = (char)('0'+j) + p; 
        }
    }
    return dp[i][k] = "-1";
}

signed main() {
    IOSFAST();
    rep(i, 0, 1<<7) {
        rep(k, 0, 10) {
            bool okay = true;
            rep(j, 0, 7) if (BIT(i,j) && !BIT(seg[k],j)) okay = false;
            if (!okay) hsh[i][k] = -1;
            else {
                int p = i^seg[k], cnt = 0;
                rep(j, 0, 7) cnt += BIT(p,j);
                hsh[i][k] = cnt;
            }
        }
    }
    cin >> n >> m;
    rep(i, 0, n) {
        str s;
        cin >> s;
        int k = 0;
        rep(j, 0, 7) k *= 2, k += s[j]-'0';
        arr[i] = k; 
    }
    cout << btk(0, m);
}