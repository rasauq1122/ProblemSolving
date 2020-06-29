// 2019.10.07

#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
#define and &&
#define or ||
#define not !
using namespace std;

bool debug = false;
int nxm[301][301] = {};
int vis[301][301] = {};
int tom[301][301] = {};
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n, m;

void bfs(int i, int j)
{
  queue < pair < int, int > > q;
  q.push({i,j});
  vis[i][j] = 1;

  while (not(q.empty()))
  {
    int x = q.front().second;
    int y = q.front().first;
    q.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 0 or yy < 0 or xx >= m or yy >= n) {continue;}
      else
      {
        if (vis[yy][xx] == 0 and nxm[yy][xx] != 0)
        {
          q.push({yy,xx});
          vis[yy][xx] = 1;
        }
        else if (nxm[yy][xx] == 0)
        {
          tom[y][x]++;
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
      if(debug) {printf("%d ",nxm[i][j]);}
    }
    if(debug) {printf("\n");}
  }
  if(debug) {printf("\n");}

  int cnt = 1, year = 0;
  while (cnt == 1)
  {
    cnt = 0;
    year++;
    for (int i = 0 ; i < n ; i++)
    {
      for (int j = 0 ; j < m ; j++)
      {
        if (vis[i][j] == 0 and nxm[i][j] != 0) {bfs(i,j);}
      }
    }

    for (int i = 0 ; i < n ; i++)
    {
      for (int j = 0 ; j < m ; j++)
      {
        nxm[i][j] -= tom[i][j];
        if (nxm[i][j] < 0) {nxm[i][j] = 0;}
        if(debug) {printf("%d ",nxm[i][j]);}
      }
      if(debug) {printf("\n");}
    }
    if(debug) {printf("\n");}

    memset(tom, false, sizeof(tom));
    memset(vis, false, sizeof(vis));

    for (int i = 0 ; i < n ; i++)
    {
      for (int j = 0 ; j < m ; j++)
      {
        if (vis[i][j] == 0 and nxm[i][j] != 0) {cnt++; bfs(i,j);}
      }
    }

    memset(tom, false, sizeof(tom));
    memset(vis, false, sizeof(vis));
  }

  if (cnt != 0) {printf("%d",year);}
  else {printf("0");}
}
