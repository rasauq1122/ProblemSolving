// 2019.11.17

#include <iostream>
#include <queue>
#include <memory.h>
#define and &&
#define or ||
#define not !
using namespace std;

int map[100][100], vis[100][100], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, a, b, t, m;

void bfs(void)
{
    queue < pair < int, int > > q;
    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        if (map[x][y] == 2) m = vis[x][y] + a-x + b-y - 3;
        q.pop();

        for (int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or yy < 0 or xx >= a or yy >= b) continue;
            else if ((!vis[xx][yy] or vis[x][y]+1 < vis[xx][yy]) and map[xx][yy] != 1)
            {
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx,yy});
            }
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> t;

    for (int i = 0 ; i < a ; i++) for (int j = 0 ; j < b ; j++) cin >> map[i][j];
    bfs();
    int x = min(vis[a-1][b-1] ? vis[a-1][b-1]-1 : 10001,m ? m : 10001);

    if (x > t) cout << "Fail";
    else cout << x;
}