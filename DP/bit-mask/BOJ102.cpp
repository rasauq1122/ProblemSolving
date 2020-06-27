// 2020.05.22

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int dat[16][16], dp[1<<16], n, k;

int sol(int bit) {
    if (dp[bit] != -1) return dp[bit];

    int cnt = 0;
    for (int i = 0 ; i < n ; i++) if (bit & 1<<i) cnt++;
    if (cnt >= k) return dp[bit] = 0;

    for (int i = 0 ; i < n ; i++) {
        if ((bit | 1<<i) == bit) 
            for (int j = 0 ; j < n ; j++) {
            if ((bit & 1<<j) == 0) {
                int get = sol(bit | 1<<j);
                if (get != 10000) {
                    if (dp[bit] == -1) dp[bit] = dat[i][j] + get;
                    else dp[bit] = min(dp[bit], dat[i][j] + get);
                }
            }
        }
    }

    if (dp[bit] == -1) return dp[bit] = 10000;
    return dp[bit];
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) cin >> dat[i][j];
    
    string s;
    cin >> s;
    cin >> k;

    int p = 0;
    for (int i = n-1 ; i >= 0 ; i--) {
        p <<= 1;
        p += s[i] == 'Y';
    }

    int ans = sol(p);
    if (ans >= 10000) cout << -1;
    else cout << ans;
}