// 2019.11.19

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[500][500], a[500][2], n;

int loop(int s, int e)
{
    if (s == e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    int m = 2147483647;
    for (int i = s ; i < e ; i++) m = min(m,loop(s,i)+loop(i+1,e)+a[s][0]*a[i][1]*a[e][1]);
    return dp[s][e] = m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i][0] >> a[i][1];
    memset(dp,-1,sizeof(dp));
    cout << loop(0,n-1);
}