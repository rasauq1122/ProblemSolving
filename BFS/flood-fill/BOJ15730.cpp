// 2019.11.18

#include <iostream>
#include <queue>
#include <memory.h>
#define or ||
#define and &&
using namespace std;

int n, m, map[100][100] = {}, cnt = 0, dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
bool esc = false, vis[100][100] = {};

void bfs(int fx, int fy, int k)
{
    queue < pair < int, int> > q;
    q.push({fx,fy});
    vis[fx][fy] = true;
    int c = 0;
    bool wall = false;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        c++;
        if (x == 0 or y == 0 or x == n-1 or y == m-1) wall = true;
        
        for (int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or yy < 0 or xx >= n or yy >= m) continue;
            if (!vis[xx][yy] and map[xx][yy] <= k)
            {
                vis[xx][yy] = true;
                q.push({xx,yy});
            }
        }
    }

    if (!wall) cnt += c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) cin >> map[i][j];
    
    for (int i = 0 ; i < 10000 ; i++) 
    {
        memset(vis,0,sizeof(vis));
        for (int j = 0 ; j < n ; j++) for (int k = 0 ; k < m ; k++) if (!vis[j][k] and map[j][k] <= i) bfs(j,k,i);
    }

    cout << cnt;
}