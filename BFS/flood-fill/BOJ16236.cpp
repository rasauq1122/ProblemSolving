// 2020.06.29

#include <iostream>
#include <queue>
#include <memory.h>
#define pii pair<int,int>
using namespace std;

int map[20][20], n, sx, sy, t, vis[20][20], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, ss = 2, cnt;

priority_queue < pii, vector<pii>, greater<pii> > pq;

bool bfs() {
    memset(vis, -1, sizeof(vis));
    queue <pii> q;
    q.push({sx,sy});
    vis[sx][sy] = 0;

    int eat = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (eat != 0 && vis[x][y] >= eat) break;
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
            if (vis[xx][yy] == -1) {
                if (map[xx][yy] == 0 || map[xx][yy] == ss) q.push({xx, yy});
                else if (map[xx][yy] < ss) {
                    eat = vis[x][y]+1;
                    pq.push({xx,yy});
                }
                vis[xx][yy] = vis[x][y]+1;
            }
        }
    }

    return eat;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) for (int j = 0, a ; j < n ; j++) {
        cin >> a;
        if (a == 9) {
            sx = i;
            sy = j;
            map[i][j] = 0;
        } else map[i][j] = a;
    }

    while (bfs()) {
        int x = pq.top().first;
        int y = pq.top().second;
        t += vis[x][y];
        sx = x;
        sy = y;
        cnt++;
        if (cnt == ss) {
            ss++;
            cnt = 0;
        }
        map[x][y] = 0;
        while (!pq.empty()) pq.pop();
    }

    cout << t;
}