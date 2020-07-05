// 

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
#define BIG 1000000007
using namespace std;

int t, dp[5001][5001];

int foo(int len, int open) {
    if (len < open) return 0;
    if (len == 1) return open;
    if (dp[len][open] != -1) return dp[len][open];
    if (open) return dp[len][open] = (foo(len-1, open-1) + foo(len-1, open+1))%BIG;
    return dp[len][open] = foo(len-1, open+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for (int ti = 0, n ; ti < t ; ti++) {
        cin >> n;
        cout << foo(n,0) << '\n';
    }
}