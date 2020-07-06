// 2020.07.06

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
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
ll dp[21][211];

ll foo(int k, int n) {
    if (n < 0) return 0;
    if (k == 1) return n <= 1;
    if (dp[k][n] != -1) return dp[k][n];
    ll sum = 0;
    for (int i = 0 ; i <= k ; i++) sum += foo(k-1, n-i);
    return dp[k][n] = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    memset(dp,-1,sizeof(dp));
    for (int ti = 0, n, k; ti < t ; ti++) {
        cin >> k >> n;
        cout << foo(k, n) << '\n';
    }
}