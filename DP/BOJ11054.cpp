// 2019.12.29

#include <iostream>
#include <algorithm>
using namespace std;

int n, list[1000], dp1[1001] = {0,1}, dp2[1001], rst, dp3[1001], dp4[1001], dp5[1001] = {-1}, dp6[1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    dp2[n] = 0;
    dp2[n-1] = 1;
    for (int i = 0 ; i < n ; i++) cin >> list[i];
    for (int i = 1 ; i < n ; i++){
        dp1[i+1] = 1;
        for (int j = 0 ; j < i ; j++) if (list[i] > list[j]) dp1[i+1] = max(dp1[i+1],dp1[j+1]+1);
    }
    for (int i = 1 ; i < n ; i++){
        dp2[n-1-i] = 1;
        for (int j = 0 ; j < i ; j++) if (list[n-1-i] > list[n-1-j]) dp2[n-1-i] = max(dp2[n-1-i],dp2[n-1-j]+1);
    }

    dp6[n] = -1;
    for (int i = 1 ; i <= n ; i++) if (dp1[i] > dp3[i-1]) {
        dp3[i] = dp1[i];
        dp5[i] = list[i-1];
    } 
    else {
        dp3[i] = dp3[i-1];
        dp5[i] = dp5[i-1];
    }
    for (int i = n-1 ; i >= 0 ; i--) if (dp2[i] > dp4[i+1]) {
        dp4[i] = dp2[i];
        dp6[i] = list[i];
    }
    else {
        dp4[i] = dp4[i+1];
        dp6[i] = dp6[i+1];
    }
    for (int i = 0 ; i <= n ; i++) rst = max(rst, dp3[i]+dp4[i] - (dp5[i] == dp6[i])); 
    cout << rst;
}