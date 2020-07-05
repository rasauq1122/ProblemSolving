// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#include <string>
#define pii pair<int,int>
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
using namespace std;

int t;
ll dp[11][21], comb[21][21];

ll foo(int n, int k) {
    if (k == 0 || k == n) return comb[n][k] = 1;
    return comb[n][k] = foo(n-1,k-1) + foo(n-1,k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1][0] = 1;
    for (int i = 1 ; i <= 20 ; i++) dp[1][i] = dp[1][i-1]<<1;
    for (int i = 2 ; i <= 10 ; i++) for (int j = 0 ; j <= 20 ; j++) {
        for (int k = 0 ; k <= j ; k++) dp[i][j] += foo(j,k)*dp[i-1][k];
    }
    
    cin >> t;
    for (int ti = 0, n, e, i ; ti < t ; ti++) {
        cin >> n >> e;
        for (i = 0 ; dp[e][i] < n ; i++);
        cout << i << '\n';
    }
}