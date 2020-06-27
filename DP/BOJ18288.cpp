// 2020.01.19

#include <iostream>
using namespace std;

#define BIG 1000000007

int dp[100001][3][10][2] = {}, n, k;

int main()
{
    cin >> n >> k;

    if (k)
    {
        dp[1][0][k!=1][0] = 1;
        dp[1][1][0][0] = 1;
        dp[1][2][0][1] = 1;
        for (int i = 2 ; i <= n ; i++) for (int j = 0 ; j < 3 ; j++) for (int l = 0 ; l < k ; l++) for (int m = 0 ; m < 2 ; m++) 
        {
            dp[i][0][l][m] += dp[i-1][j][(l-1<0)?k-1:l-1][m]%BIG;
            if (j != 1) dp[i][1][l][m] += dp[i-1][j][l][m]%BIG;
            dp[i][2][l][1] += dp[i-1][j][l][m]%BIG; 
            
            dp[i][0][l][m] %= BIG;
            dp[i][1][l][m] %= BIG;
            dp[i][2][l][1] %= BIG;
        }
    }
    else
    {
        dp[1][1][0][0] = 1;
        dp[1][2][0][1] = 1;
        for (int i = 2 ; i <= n ; i++) for (int j = 1 ; j < 3 ; j++) for (int l = 0 ; l < 2 ; l++)
        {
            if (j != 1) dp[i][1][0][l] += dp[i-1][j][0][l]%BIG;
            dp[i][2][0][1] += dp[i-1][j][0][l]%BIG; 

            dp[i][1][0][l] %= BIG;
            dp[i][2][0][1] %= BIG;
        }
    }
    
    cout << ((dp[n][0][0][1]%BIG + dp[n][1][0][1]%BIG)%BIG + dp[n][2][0][1]%BIG)%BIG;
}

