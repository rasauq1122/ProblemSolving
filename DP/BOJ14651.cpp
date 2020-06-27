// 2020.01.19

#include <iostream>
using namespace std;

#define BIG 1000000009

int dp[33334][3] = {{0,0,0},{0,1,1}}, n;

int main()
{
    cin >> n;
    for (int i = 2 ; i <= n; i++) for (int j = 0 ; j < 3 ; j++) dp[i][j] = ((dp[i-1][0]%BIG + dp[i-1][1]%BIG)%BIG + dp[i-1][2]%BIG)%BIG;
    cout << dp[n][0]%BIG;
}