// 2020.07.01

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue< T, vector < T >, greater< T > >
#define Q(T) queue<T>
#define S(T) stack<T>
using namespace std;

int n, m, map[100][100], t, vis[100][100], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
Q(pii) melt;

int bfs() {
    memset(vis, 0, sizeof(vis));
    Q(pii) q;
    vis[0][0] = 1;
    q.push({0,0});
    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (map[xx][yy]) {
                if (vis[xx][yy]++ == 1) melt.push({xx,yy});    
            } else if (!vis[xx][yy]) {
                vis[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) cin >> map[i][j];
    
    while (true) {
        bfs();
        if (melt.empty()) break;
        t++;    
        while (!melt.empty()) {
            int x = melt.front().ff;
            int y = melt.front().ss;
            map[x][y] = 0;
            melt.pop();
        }
    }
    cout << t;
}