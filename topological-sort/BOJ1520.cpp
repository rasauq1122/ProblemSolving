// 2019.12.27

#include <iostream>
#include <queue>
#include <vector>
#define and &&
#define or ||
#define not !
using namespace std;

int li[500][500], cost[500][500] = {{1}}, in[500][500];

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < vector < vector < pair < int, int > > > > v(n, vector < vector < pair < int, int > > >(m));
	
	for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) cin >> li[i][j];
	for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++)
	{
		if (i+1 < n)
		{
			if (li[i][j] > li[i+1][j]) 
			{
				v[i][j].push_back({i+1,j});
				in[i+1][j]++;
			}
			else if (li[i][j] < li[i+1][j])
			{
				v[i+1][j].push_back({i,j});
				in[i][j]++;
			}
		}
		if (j+1 < m)
		{
			if (li[i][j] > li[i][j+1]) 
			{
				v[i][j].push_back({i,j+1});
				in[i][j+1]++;
			}
			else if (li[i][j] < li[i][j+1])
			{
				v[i][j+1].push_back({i,j});
				in[i][j]++;
			}
		}
	}
	
	queue < pair < int, int > > q;
	
	for (int i = 0, len ; i < n ; i++) for (int j = 0 ; j < m ; j++) if (!in[i][j] and not (i == 0 and j == 0)) q.push({i,j});
	
	while (!q.empty())
	{
	
		int x = q.front().first, y = q.front().second, len = v[x][y].size();
		q.pop();
		for (int k = 0, xx, yy ; k < len ; k++)
		{
			xx = v[x][y][k].first;
			yy = v[x][y][k].second;
			if (!--in[xx][yy]) if (!(xx == 0 and yy == 0)) q.push({xx,yy});
		}
	}
	
	q.push({0,0});
	
	while (!q.empty())
	{
		pair < int, int > now = q.front();
		q.pop();
		int x = now.first, y = now.second, len = v[x][y].size();
		for (int i = 0, xx, yy ; i < len ; i++)
		{
			xx = v[x][y][i].first;
			yy = v[x][y][i].second;
			cost[xx][yy] += cost[x][y];
			if (!--in[xx][yy]) q.push({xx,yy});
		}
	}

	cout << cost[n-1][m-1];
}