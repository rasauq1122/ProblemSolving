// 2019.11.19

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t, dp[65][10] = {{0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1}};
    cin >> t;
    for (int i = 0, n, k = 1 ; i < t ; i++)
    {
        cin >> n;
        for (; k < n ; k++)
        {
            for (int i = 0 ; i < 10 ; i++)
            {
                for (int j = i ; j < 10 ; j++)
                {
                    dp[k+1][j] += dp[k][i];
                }
            }
        }

        long long sum = 0;
        for (int i = 0 ; i < 10 ; i++) sum += dp[n][i];
        cout << sum << '\n';
    }
}