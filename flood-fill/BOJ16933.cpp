// 2020.05.02

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define ff first
#define ss second

int n, m, k, map[1000][1000], vis[1000][1000][11], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

int bfs() {
    queue < pair < pair < int, int >, int > > q;
    q.push({{0,0},0});
    vis[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().ff.ff, y = q.front().ff.ss;
        int wall = q.front().ss;
        q.pop();
        // cout << x << ' ' << y << "\n";
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int now_wall = wall;
            // cout << ">>" << xx << ' ' << yy << "\n";
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (map[xx][yy]) {
                // cout << "map_check\n";
                if (now_wall == k) continue;
                now_wall = wall+1;
            }
            int now = vis[x][y][wall]+1;
            if (now_wall != wall) now = ((now+1)/2)*2;
            if (vis[xx][yy][now_wall] != 0 && now >= vis[xx][yy][now_wall]) continue;
            vis[xx][yy][now_wall] = now;
            q.push({{xx,yy},now_wall});
        }
    }
    
    int ans = 1000001;
    for (int i = 0 ; i <= k ; i++) if (vis[n-1][m-1][i]) ans = min(ans,vis[n-1][m-1][i]);

    return ans == 1000001 ? -1 : ans; 
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++) map[i][j] = s[j]-'0';
    }

    cout << bfs();
}