// 2019.12.30

#include <iostream>
using namespace std;

#define BIG 1000000007

long long dp[101][10][5];

int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < 10 ; i++) dp[1][i][4] = 1;
    
    for (int i = 2 ; i <= n ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            if (j > 0)
            {
                dp[i][j][0] += dp[i-1][j-1][1]%BIG;
                dp[i][j][1] += dp[i-1][j-1][2]%BIG + dp[i-1][j-1][3]%BIG + dp[i-1][j-1][4]%BIG;
                dp[i][i][1] %= BIG;
            }
            if (9 > j)
            {
                dp[i][j][2] += dp[i-1][j+1][3]%BIG;
                dp[i][j][3] += dp[i-1][j+1][0]%BIG + dp[i-1][j+1][1]%BIG + dp[i-1][j+1][4]%BIG;
                dp[i][j][3] %= BIG;
            }
        }
    }

    long long sum = 0;
    for (int i = 0 ; i < 10 ; i++) for (int j = 0 ; j < 5 ; j++) 
    {
        sum += dp[n][i][j]%BIG;
        sum %= BIG;
    }
    cout << sum;
}