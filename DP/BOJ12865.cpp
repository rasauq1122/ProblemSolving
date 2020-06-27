// 2020.05.24

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int arr[100][2], dp[100][100001];

int sol(int i, int k) {
    if (i < 0) return 0;
    if (dp[i][k] != -1) return dp[i][k];

    dp[i][k] = sol(i-1,k);
    if (arr[i][0] <= k) dp[i][k] = max(dp[i][k], arr[i][1] + sol(i-1,k-arr[i][0]));
    return dp[i][k];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) cin >> arr[i][0] >> arr[i][1];
    cout << sol(n-1, m);
}