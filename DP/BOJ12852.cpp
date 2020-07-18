// 2020.07.18

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

int n, m, k;
int dp[1000005];

int foo(int k) {
    if (dp[k] != -1) return dp[k];
    if (k <= 0) return 1e6;
    if (k == 1) return 0;
    if (k%6 == 0) return dp[k] = min({foo(k-1), foo(k/2), foo(k/3)}) + 1;
    if (k%3 == 0) return dp[k] = min(foo(k-1), foo(k/3)) + 1;
    if (k%2 == 0) return dp[k] = min(foo(k-1), foo(k/2)) + 1;
    return dp[k] = foo(k-1) + 1;
}

void bar(int k) {
    cout << k << ' ';
    if (k == 1) return;
    if (k%6 == 0) {
        if (min({foo(k-1), foo(k/2), foo(k/3)}) == foo(k-1)) bar(k-1);
        else if (min(foo(k/2), foo(k/3)) == foo(k/2)) bar(k/2);
        else bar(k/3);
    }
    else if (k%3 == 0) {
        if (min(foo(k-1), foo(k/3)) == foo(k/3)) bar(k/3);
        else bar(k-1);
    }
    else if (k%2 == 0)  {
        if (min(foo(k-1), foo(k/2)) == foo(k/2)) bar(k/2);
        else bar(k-1);
    } 
    else if (k) bar(k-1);
}

int main() {
    IOSFAST();
    MS(dp);
    cin >> n;
    cout << foo(n) << endl;
    bar(n);
}   