// 2020.05.24

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1001][1001];
string s1, s2;

int sol(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || j == 0) return dp[i][j] = 0;

    dp[i][j] = max(sol(i,j-1), sol(i-1,j));
    if (s1[i-1] == s2[j-1]) dp[i][j] = max(dp[i][j], sol(i-1,j-1)+1);
    return dp[i][j];
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin >> s1 >> s2;
    cout << sol(s1.size(), s2.size());
}