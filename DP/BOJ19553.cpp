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
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define mod(A,B) ((A+B)%B)
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, so = IMAX;
int arr[1000];
unsigned dp[201][1000][1000], da;

unsigned foo(int t, int l, int r) {
    if (l == r) {
        if (t <= 0) return arr[l]<<16;
        return arr[l];
    }
    if (r < 0) return foo(t, l, n-1);
    if (l > n-1) return foo(t, 0, r);
    if (dp[t+100][l][r]) return dp[t+100][l][r];

    int a, b;
    if (t <= 0) {
        a = foo(t+arr[l], l+1, r);
        b = foo(t+arr[r], l, r-1);
        if ((a>>16)+arr[l] > (b>>16)+arr[r]) return dp[t+100][l][r] = a + (arr[l]<<16); 
        return dp[t+100][l][r] = b + (arr[r]<<16);
    }
    a = foo(t-arr[l], l+1, r);
    b = foo(t-arr[r], l, r-1);
    if ((((1<<16)-1)&a) + arr[l] > (((1<<16)-1)&b) + arr[r]) return dp[t+100][l][r] = a + arr[l];
    return dp[t+100][l][r] = b + arr[r];
}

signed main() {
    IOSFAST();
    cin >> n; 
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n) {
        da = max((foo(arr[i], i+1, i-1)>>16) + arr[i], da);
    }
    cout << da;  
}