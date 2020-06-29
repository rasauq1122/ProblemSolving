// 2020.05.02

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, map[1000][1000], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}, vis[1000][1000], ans[1000][1000];

void bfs(int i, int j, int now) {

    int cnt = 0;
    
    queue < pair <int, int> > q, q2;
    q.push({i,j});
    
    cnt++; 
    vis[i][j] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (map[xx][yy]) {
                if (vis[xx][yy] == now) continue;
                vis[xx][yy] = now;
                q2.push({xx,yy});
                continue;
            }
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            q.push({xx,yy});
            cnt++;
        }
    }

    while (!q2.empty()) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        ans[x][y] += cnt;
        ans[x][y] %= 10;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++) map[i][j] = s[j] - '0';
    }
    
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) if (map[i][j]) ans[i][j]++;

    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) if (!map[i][j] && !vis[i][j]) bfs(i,j,i*m+j+1);
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) cout << ans[i][j];
        cout << '\n';
    }
}   