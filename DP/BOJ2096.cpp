// 2020.07.02

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

int t, dp[3][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    cin >> dp[0][0] >> dp[1][0] >> dp[2][0];
    dp[0][1] = dp[0][0];
    dp[1][1] = dp[1][0];
    dp[2][1] = dp[2][0];
    for (int i = 1, x, x2, y, y2, z, z2 ; i < t ; i++) {
        cin >> x >> y >> z;
        x2 = x, y2 = y, z2 = z;
        x += max(dp[0][0],dp[1][0]);
        y += max({dp[0][0],dp[1][0],dp[2][0]});
        z += max(dp[1][0],dp[2][0]);
        dp[0][0] = x;
        dp[1][0] = y;
        dp[2][0] = z;
        x2 += min(dp[0][1],dp[1][1]);
        y2 += min({dp[0][1],dp[1][1],dp[2][1]});
        z2 += min(dp[1][1],dp[2][1]);
        dp[0][1] = x2;
        dp[1][1] = y2;
        dp[2][1] = z2;
    }
    cout << max({dp[0][0],dp[1][0],dp[2][0]}) << ' ' << min({dp[0][1],dp[1][1],dp[2][1]});
}