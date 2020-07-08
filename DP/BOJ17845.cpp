// 2020.07.08

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
#define IMAX ((1LL<<31)-1)
#define MS(T) memset(T, -1, sizeof(T))
using namespace std;

int n, k, dp[10000][1000], arr[1000][2];

int foo(int time, int now) {
    if (dp[time][now] != -1) return dp[time][now];
    if (!now) {
        if (time >= arr[now][1]) return arr[now][0]; 
        return 0;
    }
    
    if (time >= arr[now][1]) return dp[time][now] = max(foo(time-arr[now][1], now-1) + arr[now][0], foo(time, now-1));
    return dp[time][now] = foo(time, now-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0 ; i < k ; i++) cin >> arr[i][0] >> arr[i][1];
    MS(dp);
    cout << foo(n, k);
}