// 2019.10.07

#include <iostream>
#include <queue>
#include <utility>
#define and &&
#define or ||
#define not !
using namespace std;

int nxm[1001][1001] = {};
int vis[1001][1001] = {};
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int n, m, stx, sty;

void bfs()
{
  queue < pair < int, int > > q;
  q.push({sty,stx});
  vis[sty][stx] = 1;

  while (not(q.empty()))
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 0 or yy < 0 or xx >= m or yy >= n) {continue;}
      else
      {
        if (vis[yy][xx] == 0 and nxm[yy][xx] == 1)
        {
          q.push({yy,xx});
          vis[yy][xx] = vis[y][x] + 1;
        }
      }
    }
  }
}


int main()
{
  scanf("%d %d",&n,&m);
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      scanf("%d",&nxm[i][j]);
      if (nxm[i][j] == 2) {stx = j; sty = i;}
    }
  }

  bfs();

  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      if (vis[i][j] == 0)
      {
        if (nxm[i][j] != 0) {vis[i][j]--;}
      }
      else
      {
        vis[i][j]--;
      }
    }
  }

  for (int i = 0 ; i < n ; i++)
  {
    bool boot = false;
    for (int j = 0 ; j < m ; j++)
    {
      if (boot) {printf(" ");}
      else {boot = true;}
      printf("%d",vis[i][j]);
    }
    if (i != n-1) {printf("\n");}
  }
}
