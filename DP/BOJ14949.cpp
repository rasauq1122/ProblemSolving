// 2020.07.14

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
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
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1<<(B))))
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
#define BIG 1000000007
using namespace std;

int comb[401][401], dp[201][7], h, w;

int cmb(int n, int r) {
    if (comb[n][n-r] != -1) return comb[n][r] = comb[n][n-r];
    if (comb[n][r] != -1) return comb[n][r];  
    if (n == r || r == 0) return 1;
    return comb[n][r] = (cmb(n-1,r-1)%BIG + cmb(n-1,r)%BIG)%BIG;
}

int foo(int n, int h) {
    if (dp[n][h] != -1) return dp[n][h];
    if (h == 0) return n == 1;

    int tmp = 0;
    for (int i = 1 ; i <= w ; i++) {
        tmp += (1LL*(foo(i,h-1)%BIG)*(cmb(i+n-1,n)%BIG))%BIG;
        tmp %= BIG;
    }
    return dp[n][h] = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    MS(comb), MS(dp);
    cout << foo(0,h+1);
}