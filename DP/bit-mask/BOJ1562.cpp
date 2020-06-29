// 2020.06.30

#include <iostream>
#include <memory.h>
#define BIG 1000000000
using namespace std;

int dp[101][10][1<<10], dx[2] = {1,-1};

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1 ; i < 10 ; i++) dp[1][i][1<<i] = 1;

    for (int i = 1 ; i < n ; i++) for (int j = 0 ; j < 10 ; j++) for (int k = 0 ; k < (1<<10) ; k++) {
        for (int p = 0 ; p < 2 ; p++) {
            int nw = j+dx[p];
            if (nw >= 0 && nw <= 9) {  
                dp[i+1][nw][k|(1<<nw)] += dp[i][j][k];
                dp[i+1][nw][k|(1<<nw)] %= BIG;
            }
        }
    } 

    for (int i = 0 ; i < 10 ; i++) {
        sum += dp[n][i][1023];
        sum %= BIG;
    }
    
    cout << sum;
}