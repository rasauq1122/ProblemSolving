// 2019.12.24

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, in[501] = {}, data[501];
		bool okay = true, g[501][501] = {};
		cin >> n;
		for (int i = 1 ; i <= n ; i++) cin >> data[i];
		
		for (int i = 1 ; i <= n-1 ; i++)
		{
			for (int j = i+1 ; j <= n ; j++)
			{
				g[data[i]][data[j]] = true;
				in[data[j]]++;
			}
		}
		
		cin >> m;
		for (int i = 0, x, y ; i < m ; i++)
		{
			cin >> x >> y;
			if (g[x][y])
			{
				g[x][y] = false;
				g[y][x] = true;
				in[y]--;
				in[x]++;
			}
			else
			{
				g[x][y] = true;
				g[y][x] = false;
				in[y]++;
				in[x]--;
			}
		}
		
		queue <int> qi, qo;
		for (int i = 1 ; i <= n ; i++) if (!in[i]) qi.push(i);
		
		while (!qi.empty())
		{
			int now = qi.front();
			if (qi.size() != 1)
			{
				okay = false;
				break;
			}
			qi.pop();
			qo.push(now);
			
			for (int i = 1 ; i <= n ; i ++) if (g[now][i] && !--in[i]) qi.push(i);
		}
		
		if (!okay) cout << "?";
		if (okay && qo.size() < n) 
		{
			cout << "IMPOSSIBLE";
			okay = false;	
		}
		
		while (okay && !qo.empty()) 
		{
			cout << qo.front() << " ";
			qo.pop();
		}
		
		cout << "\n";
	}
}