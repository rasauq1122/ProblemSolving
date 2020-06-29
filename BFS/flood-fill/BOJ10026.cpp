// 2019.10.07

#include <iostream>
#include <queue>
#include <utility>
#define or ||
#define and &&
#define not !
using namespace std;

char nxm1[102][102] = {};
char nxm2[102][102] = {};
int vis1[102][102] = {};
int vis2[102][102] = {};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, sum1 = 0, sum2 = 0;
string s[102];

void bfs1(int i, int j, char c)
{
  queue < pair < int, int > > q;
  vis1[i][j] = 1;
  q.push({i,j});

  while (not(q.empty()))
  {
    int x = q.front().second;
    int y = q.front().first;
    q.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 or yy < 0 or xx >= n or yy >= n) {continue;}
      else
      {
        if (vis1[yy][xx] == 0 and nxm1[yy][xx] == c)
        {
          q.push({yy,xx});
          vis1[yy][xx] = 1;
        }
      }
    }
  }
}

void bfs2(int i, int j, char c)
{
  queue < pair < int, int > > q;
  vis2[i][j] = 1;
  q.push({i,j});

  while (not(q.empty()))
  {
    int x = q.front().second;
    int y = q.front().first;
    q.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 or yy < 0 or xx >= n or yy >= n) {continue;}
      else
      {
        if (vis2[yy][xx] == 0 and nxm2[yy][xx] == c)
        {
          q.push({yy,xx});
          vis2[yy][xx] = 1;
        }
      }
    }
  }
}

int main()
{
  scanf("%d",&n);
  ios::sync_with_stdio(false); cin.tie(NULL);
  for (int i = 0 ; i < n ; i++)
  {
    cin >> s[i];
  }

  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < n ; j++)
    {
      nxm1[i][j] = s[i][j];
      if (s[i][j] == 'B') {nxm2[i][j] = 'B';}
      else {nxm2[i][j] = 'A';}
    }
  }

  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < n ; j++)
    {
      if (vis1[i][j] == 0) {sum1++; bfs1(i,j,nxm1[i][j]);}
      if (vis2[i][j] == 0) {sum2++; bfs2(i,j,nxm2[i][j]);}
    }
  }

  printf("%d %d",sum1,sum2);
}
