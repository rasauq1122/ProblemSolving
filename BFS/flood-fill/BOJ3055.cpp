// 2019.10.08

#include <iostream>
#include <queue>
#include <utility>
#define and &&
#define or ||
#define not !
using namespace std;

int map[51][51] = {};
int vis1[51][51] = {};
int vis2[51][51] = {};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
string s[51];
queue < pair < int, int > > q1;
queue < pair < int, int > > q2;
int ex,ey, n, m;

void bfs()
{
  while (not(q1.empty()))
  {
    int x = q1.front().second;
    int y = q1.front().first;
    q1.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 or yy < 0 or xx >= m or yy >= n) {continue;}
      else
      {
        if (vis1[yy][xx] == 0 and map[yy][xx] == 0)
        {
          q1.push({yy,xx});
          vis1[yy][xx] = vis1[y][x] + 1;
        }
      }

    }
  }
  while (not(q2.empty()))
  {
    int x = q2.front().second;
    int y = q2.front().first;
    q2.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 or yy < 0 or xx >= m or yy >= n) {continue;}
      else
      {
        if ((vis1[yy][xx] == 0 or vis1[yy][xx] > vis2[y][x]+1) and map[yy][xx] != 1 and vis2[yy][xx] == 0)
        {
          q2.push({yy,xx});
          vis2[yy][xx] = vis2[y][x] + 1;
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
    cin >> s[i];
  }

  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      if (s[i][j] == 'D') {ex = j; ey = i; map[i][j] = 2;}
      else if (s[i][j] == 'S') {q2.push({i,j}); vis2[i][j] = 1;}
      else if (s[i][j] == '*') {q1.push({i,j}); vis1[i][j] = 1;}
      else if (s[i][j] == 'X') {map[i][j] = 1;}
    }
  }

  bfs();
  if (vis2[ey][ex] == 0) {printf("KAKTUS");}
  else {printf("%d",vis2[ey][ex]-1);}

  // printf("\n");
  // for (int i = 0 ; i < n ; i++)
  // {
  //   for (int j = 0 ; j < m ; j++)
  //   {
  //
  //     printf("%3d ",vis1[i][j]);
  //   }
  //   printf(" ");
  //   for (int j = 0 ; j < m ; j++)
  //   {
  //     printf("%3d ",vis2[i][j]);
  //   }
  //   printf("\n");
  // }
}
