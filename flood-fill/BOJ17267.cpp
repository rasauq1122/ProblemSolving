// 2019.10.08

#include <iostream>
#include <queue>
#include <utility>
#define and &&
#define or ||
#define not !
using namespace std;

int nxm[1001][1001] = {};
int vis[1001][1001] = {};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m, le, ri, sx, sy;
string s[1001];

void bfs(int i, int j, int l, int r)
{
  queue < pair < pair < int, int >, pair < int, int > > > q;
  int ii = i;
  while (0 <= ii and ii < n and nxm[ii][j] != 1)
  {
    if ((1 <= j and nxm[ii][j-1] == 0) or (j < m-1 and nxm[ii][j+1] == 0)) {q.push({{ii,j},{l,r}});}
    vis[ii][j] = 1;
    ii++;
  }
  ii = i-1;
  while (0 <= ii and ii < n and nxm[ii][j] != 1)
  {
    if ((1 <= j and nxm[ii][j-1] == 0) or (j < m-1 and nxm[ii][j+1] == 0)) {q.push({{ii,j},{l,r}});}
    vis[ii][j] = 1;
    ii--;
  }
//  printf(" %d %d %d %d %d\n",i,q.front().first.first,q.front().first.second,q.front().second.first,q.front().second.second);

  while(not(q.empty()))
  {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int ll = q.front().second.first;
    int rr = q.front().second.second;
    q.pop();

    for (int i = 0 ; i < 4 ; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
    //  printf(" %d %d %d %d %d\n",i,ll,rr,i == 2 and rr == 0,i == 3 and ll == 0);
      if (xx < 0 or yy < 0 or xx >= m or yy >= n or (i == 2 and rr == 0) or (i == 3 and ll == 0)) {continue;}
      else
      {
        if (vis[yy][xx] == 0 and nxm[yy][xx] != 1)
        {
          if (i < 2)
          {
            int yyy = yy;
            while (0 <= yyy and yyy < n and nxm[yyy][xx] != 1)
            {
              if ((1 <= xx and nxm[yyy][xx-1] == 0) or (xx < m-1 and nxm[yyy][xx+1] == 0)) {q.push({{yyy,xx},{ll,rr}});}
              vis[yyy][xx] = 1;
              yyy++;
            }
            yyy = yy-1;
            while (0 <= yyy and yyy < n and nxm[yyy][xx] != 1)
            {
              if ((1 <= xx and nxm[yyy][xx-1] == 0) or (xx < m-1 and nxm[yyy][xx+1] == 0)) {q.push({{yyy,xx},{ll,rr}});}
              vis[yyy][xx] = 1;
              yyy--;
            }
          }
          else if (i == 2) {q.push({{yy,xx},{ll,rr-1}});}
          else if (i == 3) {q.push({{yy,xx},{ll-1,rr}});}
          vis[yy][xx] = 1;
        //  printf(" %d %d %d %d %d\n",i,q.front().first.first,q.front().first.second,q.front().second.first,q.front().second.second);
        }
      }
    }
  }
}

int main()
{
  scanf("%d %d",&n,&m);
  scanf("%d %d",&le,&ri);
  ios::sync_with_stdio(false); cin.tie(NULL);
  for (int i = 0 ; i < n ; i++)
  {
    cin >> s[i];
  }
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      if (s[i][j] == '1') {nxm[i][j] = 1; vis[i][j] = 2;}
      else if (s[i][j] == '2') {sy = i; sx = j;}
   }
  }

  bfs(sy,sx,le,ri);
  int cnt = 0;
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      if (vis[i][j] == 1) {cnt++;}
    //  printf("%d ",vis[i][j]);
    }
  //  printf("\n");
  }

  printf("%d",cnt);
}
