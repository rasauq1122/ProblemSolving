// 2019.10.10

#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
#define and &&
#define or ||
#define not !
using namespace std;

int map[3000][3000] = {};
int vis[3000][3000] = {};
int ord[3000][3000] = {};
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, sx, sy, ex, ey;
string s[3000];

void bfs_lake(int i, int j)
{
	queue < pair < int, int > > q;
	q.push({ i,j });
	vis[i][j] = 1;

	while (not(q.empty()))
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 or yy < 0 or xx >= m or yy >= n) { continue; }
			else
			{
				if (map[yy][xx] == 0 and vis[yy][xx] == 0)
				{
					vis[yy][xx] = 1;
					q.push({ yy,xx });
				}
				else if (map[yy][xx] == 1 and (ord[yy][xx] == 0 or ord[yy][xx] > ord[y][x] + 1))
				{
					ord[yy][xx] = ord[y][x] + 1;
					q.push({ yy,xx });
				}
			}
		}
	}
}

typedef pair <int, int> pii;
typedef queue <pii> qp;

int bfs_swan()
{
	qp q_save;
	q_save.push({ sy,sx });
	vis[sy][sx] = 1;
	
	int year = 0;
	while (true)
	{
		qp q_bfs;
		year++;
		while (not(q_save.empty()))
		{
			q_bfs.push({ q_save.front().first,q_save.front().second });
			q_save.pop();
		}
		
		while (not(q_bfs.empty()))
		{
			int y = q_bfs.front().first;
			int x = q_bfs.front().second;
			q_bfs.pop();

			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (yy < 0 or xx < 0 or xx >= m or yy >= n) continue;
				else
				{
					if (vis[yy][xx] == 0 and ord[yy][xx] <= year)
					{
						vis[yy][xx] = 1;
						if (vis[ey][ex] == 1) return year;
						q_bfs.push({ yy,xx });
						if (ord[yy][xx] == year) q_save.push({ yy,xx }); 
					}
				}
			}
		}
	}
}

void vis_reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1) { vis[i][j] = 0; }
		}
	}
}

void view()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (sy == i and sx == j) printf("L ");
			else if (ey == i and ex == j) printf("L ");
			else printf("%d ", ord[i][j]);
		}
		printf("\n");
	}
}

void error()
{
	for (int i = 0; i < 100000; i++) printf("0\n");
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	bool swan = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'X') { map[i][j] = 1; }
			else if (s[i][j] == 'L')
			{
				if (swan) { ey = i; ex = j; }
				else { sy = i; sx = j; swan = true; }
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0 and vis[i][j] == 0) { bfs_lake(i, j);  goto A; }
		}
	}

	A:
	// ord배열에 얼음이 녹을 순서를 미리 받아놓음
	// view();
	
	memset(vis, 0, sizeof(vis));
	printf("%d", bfs_swan());
}
