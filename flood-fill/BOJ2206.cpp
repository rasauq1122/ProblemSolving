// 2020.05.02

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define ff first
#define ss second

int n, m, map[1000][1000], vis[1000][1000][2], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

int bfs() {
    queue < pair < pair < int, int >, bool > > q;
    q.push({{0,0},0});
    vis[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().ff.ff, y = q.front().ff.ss;
        bool wall = q.front().ss;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            bool now_wall = wall;
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (vis[xx][yy][now_wall]) continue;
            if (map[xx][yy]) {
                if (now_wall) continue;
                now_wall = true;
            }
            vis[xx][yy][now_wall] = vis[x][y][wall]+1;
            q.push({{xx,yy},now_wall});
        }
    }
    
    int ans = vis[n-1][m-1][0];
    if (ans && vis[n-1][m-1][1]) ans = min(vis[n-1][m-1][0], vis[n-1][m-1][1]);  
    else if (!ans) ans = vis[n-1][m-1][1];

    return ans == 0 ? -1 : ans; 
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++) map[i][j] = s[j]-'0';
    }

    cout << bfs();
}