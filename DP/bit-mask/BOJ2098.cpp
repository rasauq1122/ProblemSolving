// 2020.05.08

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int mat[16][16], dp[16][1<<16], n;

int f(int now, int state) { // now에서 state에 기록된 모든 node를 이동하는 데 최소비용
    int &ret = dp[now][state];
    if (ret != -1) return ret;

    if (state == (1<<n)-1) {
        if (mat[now][0] == 0) return 1e8;
        return mat[now][0];
    }

    ret = 1e8;
    for (int i = 0 ; i < n ; i++) {
        if (state & (1<<i) || !mat[now][i]) continue;
        ret = min(ret, f(i, (1<<i)|state) + mat[now][i]);
    }
    
    return ret;
}

int main() {
    cin >> n;
    
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) cin >> mat[i][j];
    memset(dp,-1,sizeof(dp));
    cout << f(0,1);
}