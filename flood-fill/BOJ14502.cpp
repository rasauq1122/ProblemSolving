// 2020.10.09
// brute-force

#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
#define not !
#define and &&
#define or ||
using namespace std;

typedef pair <int, int> pii;
typedef queue <pii> qp;

int map[9][9] = {};
int vis[9][9] = {};
int wal[9][9] = {};
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m, now, best = 0;
vector <pii> v1; // 벽세울수있는 모든 좌표

int bfs(int i, int j)
{
	qp q;
	q.push({ i,j });
	vis[i][j] = 1;

	int cnt = 0;

	while (not(q.empty()))
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 or yy < 0 or xx >= n or yy >= m) continue;
			else
			{
				if (vis[xx][yy] == 0 and wal[xx][yy] == 0 and map[xx][yy] != 1)
				{
					if (map[xx][yy] == 2) { cnt = -100; }
					vis[xx][yy] = 1;
					q.push({ xx,yy });
				}
			}
		}
	}

	return cnt > 0 ? cnt : 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> now;
			if (now == 0) v1.push_back({ i,j });
			else if (now == 1) map[i][j] = 1;
			else map[i][j] = 2;
		}
	}

	int len = v1.size();
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				memset(wal, 0, sizeof(wal));
				wal[v1[i].first][v1[i].second] = 1;
				wal[v1[j].first][v1[j].second] = 1;
				wal[v1[k].first][v1[k].second] = 1;
				
				int nn = 0;
				for (int ix = 0; ix < n; ix++)
				{
					for (int iy = 0; iy < m; iy++)
					{
						if (map[ix][iy] == 0 and wal[ix][iy] == 0 and vis[ix][iy] == 0)
						{
							int a = bfs(ix, iy);
							nn += a;
						}
					}
				}
				best = nn > best ? nn : best;
				memset(vis,0,sizeof(vis));
			}
		}
	}
	
	printf("%d", best);
}