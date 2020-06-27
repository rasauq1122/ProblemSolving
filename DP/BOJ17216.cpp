// 2019.11.15

#include <iostream>
using namespace std;

int a[1000], n;

int main()
{
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];

    int best = a[0], dp[1000] = {a[0]};
    for (int i = 1 ; i < n ; i++)
    {
        int sum = 0;
        for (int j = 0 ; j < i ; j++) if (a[j] > a[i] && dp[j] > sum) sum = dp[j];
        if (sum) dp[i] = a[i] + sum;
        else dp[i] = a[i];
        if (dp[i] > best) best = dp[i];
    }
    
    cout << best;
}