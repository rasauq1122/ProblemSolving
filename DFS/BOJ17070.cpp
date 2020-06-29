// 2020.06.30

#include <iostream>
using namespace std;

bool map[16][16];
int n, dx[3] = {0,1,1}, dy[3] = {1,1,0}, cnt;

void dfs(int x, int y, int t) {
    if (x == n-1 && y == n-1) cnt++;
    for (int i = 0 ; i < 3 ; i++) {
        if ((i == 0 && t == 2) || (i == 2 && t == 0)) continue;
        int xx = x + dx[i], yy = y + dy[i];
        if (xx == n || yy == n) continue;
        if (map[xx][yy]) continue;
        if (i == 1 && (map[xx-1][yy] || map[xx][yy-1])) continue;
        dfs(xx, yy, i);
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) cin >> map[i][j];
    dfs(0, 1, 0);
    cout << cnt;
}