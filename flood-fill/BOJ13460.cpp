// 2019.10.09

#include <iostream>
#include <queue>
#include <utility>
#define not !
#define and &&
#define or ||
using namespace std;

bool debug = false;

int map[11][11] = {};
int vis[11][11][11][11] = {};
int n, m, xR, yR, xB, yB, ex, ey;
string s[11] = {};
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int bfs()
{
	queue < pair < pair < int, int >, pair < int, int > > > q;
	q.push({ {xR,yR},{xB,yB} });
	vis[xR][yR][xB][yB] = 1;

	while (not(q.empty()))
	{
		int rx = q.front().first.first;
		int ry = q.front().first.second;
		int bx = q.front().second.first;
		int by = q.front().second.second;
		q.pop();
		if (debug) { printf("start : %d %d %d %d\n", rx, ry, bx, by); }

		for (int i = 0; i < 4; i++)
		{
			int rxx = rx, ryy = ry, bxx = bx, byy = by;
			if (debug) { printf("loop %d\n", i); }

			bool rcm = true, bcm = true, rg = false, bg = false;
			while (rcm or bcm)
			{
				if (debug) { printf("now : %d %d %d %d\n", rxx, ryy, bxx, byy); }
				if (not(rg))
				{
					rcm = map[rxx + dx[i]][ryy + dy[i]] == 0 and (not(rxx + dx[i] == bxx and ryy + dy[i] == byy) or bg);
					if (debug) printf(" rcm : %d %d\n", map[rxx + dx[i]][ryy + dy[i]] == 0, not(rxx + dx[i] == bxx and ryy + dy[i] == byy));
					if (rcm)
					{
						rxx += dx[i];
						ryy += dy[i];
						if (rxx == ex and ryy == ey) { rg = true; }
					}
				}
				else { rcm = false; }
				if (not(bg))
				{
					bcm = map[bxx + dx[i]][byy + dy[i]] == 0 and (not(bxx + dx[i] == rxx and byy + dy[i] == ryy) or rg);
					if (debug) printf(" bcm : %d %d\n", map[bxx + dx[i]][byy + dy[i]] == 0, not(bxx + dx[i] == rxx and byy + dy[i] == ryy));
					if (bcm)
					{
						bxx += dx[i];
						byy += dy[i];
						if (bxx == ex and byy == ey) { bg = true; }
					}
				}
				else { bcm = false; }

				if (bg) { break; }
			}
			if (rg and not(bg)) { return vis[rx][ry][bx][by]; }
			if (vis[rxx][ryy][bxx][byy] == 0 and not(bg) and vis[rx][ry][bx][by] <= 9)
			{
				q.push({ {rxx,ryy},{bxx,byy} });
				vis[rxx][ryy][bxx][byy] = vis[rx][ry][bx][by] + 1;
				if (debug) printf("%d : %d %d %d %d\n", vis[rxx][ryy][bxx][byy], rxx, ryy, bxx, byy);
			}
		}
	}

	return -1;
}
void view()
{
	for (int i = 0; i <= m; i++)
	{
		if (i == 0) { printf("  "); }
		else
		{
			printf("%d ", i - 1);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < m; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> s[i]; }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '#') { map[i][j] = 1; }
			else if (s[i][j] == 'R') { xR = i; yR = j; }
			else if (s[i][j] == 'B') { xB = i; yB = j; }
			else if (s[i][j] == 'O') { ex = i; ey = j; }
		}
	}

	//view();

	printf("%d", bfs());
}