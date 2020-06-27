// 2019.10.08

#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
#define and &&
#define not !
#define or ||
using namespace std;

int nxm[31][31][31] = {};
int vis[31][31][31] = {};
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int mz, my, mx, sx, sy, sz, ex, ey, ez;
string s[51][51];

void bfs(int i, int j, int k)
{
  queue < pair < int, pair < int, int > > > q;
  q.push({i,{j,k}});
  vis[i][j][k] = 1;

  while(not(q.empty()))
  {
    int z = q.front().first;
    int y = q.front().second.first;
    int x = q.front().second.second;
    q.pop();

    for (int i = 0 ; i < 6 ; i++)
    {
      int zz = z + dz[i];
      int yy = y + dy[i];
      int xx = x + dx[i];
      if (zz < 0 or yy < 0 or xx < 0 or zz >= mz or yy >= my or xx >= mx) {continue;}
      else
      {
        if (vis[zz][yy][xx] == 0 and nxm[zz][yy][xx] == 0)
        {
          vis[zz][yy][xx] = vis[z][y][x] + 1;
          q.push({zz,{yy,xx}});
        }
      }
    }
  }
}

int main()
{
  bool boot = false;
  while (true)
  {
    scanf("%d %d %d",&mz,&my,&mx);
    if (mz + my + mx == 0) {break;}
    if (boot) {printf("\n");}
    else {boot = true;}
    for (int i = 0 ; i < mz ; i++)
    {
      for (int j = 0 ; j < my ; j++)
      {
        cin >> s[i][j];
        // cout << s[i][j] << endl;
      }
    }
    memset(nxm, 0, sizeof(nxm));
    for (int i = 0 ; i < mz ; i++)
    {
      for (int j = 0 ; j < my ; j++)
      {
        for (int k = 0 ; k < mx ; k++)
        {
          if (s[i][j][k] == '#') {nxm[i][j][k] = 1;}
          else if (s[i][j][k] == 'S')
          {
            sz = i; sy = j; sx = k;
            // cout << "1 " << sz << ' ' << sy << ' ' << sx << endl;
          }
          else if (s[i][j][k] == 'E')
          {
            ez = i; ey = j; ex = k;
            // cout << "2 " << ez << ' ' << ey << ' ' << ex << endl;
          }
        }
      }
    }
    memset(vis, 0, sizeof(vis));
    bfs(sz,sy,sx);
    if (vis[ez][ey][ex] == 0) {printf("Trapped!");}
    else {printf("Escaped in %d minute(s).",vis[ez][ey][ex]-1);}
  }
}
