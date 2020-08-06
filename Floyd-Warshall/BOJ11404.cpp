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
int dp[101][101][101];

int foo(int i, int j, int k) { 
    // i번 정점에서 j번 정점까지, 
    // 1~k번의 정점을 추가로 사용했을 때의 최단 경로 
    if (dp[k][i][j] != -1) return dp[k][i][j];
    return dp[k][i][j] = min(foo(i, j, k-1), foo(i, k, k-1) + foo(k, j, k-1));
    // i번 정점에서 j번 정점을 k번 정점을 추가로 사용하지 않을 때의 최단 경로의 비용.     
    // 즉, 기존의 값
    // i번 정점에서 k번 정점, k번 정점에서 j번 정점으로 이동했을 때의 최단 경로의 비용. 
    // 즉, 새롭게 도출한 값
    
    // i - j 경로를 만드는 데 있어서, 사용하는 정점을 점점 늘리면서 결국 최단경로가 되게끔 유도하는 것
    
    // 결국 정점의 개수가 n일때만 의미 있으므로 dp로 괜히 모든 정보를 저장할 필요는 없고
    // 3중 for문으로 해결할 수 있다.
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    MS(dp);
    repc(i, 1, n) repc(j, 1, n) dp[0][i][j] = IMAX;
    repc(i, 1, n) dp[0][i][i] = 0;

    rep(i, 0, m) {
        sc3(x, y, z);
        dp[0][x][y] = min(dp[0][x][y], z);
    }

    repc(i, 1, n) {
        repc(j, 1, n) {
            int k = foo(i, j, n);
            cout << (k == IMAX ? 0 : k) << blk;  
        }
        cout << endl;
    }

}