// 2019.12.24

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, st, en, cnt = 0, in[10001] = {}, wait[10001] = {}, ans[10001] = {};
	bool chk[10001][10001] = {};
	cin >> n >> m;
	
	vector < vector < pair < int, int > > > v(n+1), v2(n+1);
	for (int i = 0, x, y, z ; i < m ; i++)
	{
		cin >> x >> y >> z;
		v[x].push_back({y,z});
		v2[y].push_back({x,z});
		in[y]++;
	}

	cin >> st >> en;
	queue < int > q;
	q.push(st);
	
	while (!q.empty())
	{
		int now = q.front(), len = v[now].size();
		q.pop();
		ans[now] = wait[now];
		for (int i = 0, goal, cost ; i < len ; i++)
		{
			goal = v[now][i].first;
			cost = v[now][i].second;
			wait[goal] = (wait[goal] < ans[now] + cost) ? (ans[now] + cost) : wait[goal];
			if (!--in[goal]) q.push(goal);
		}
	}
	
	q.push(en);
	
	while (!q.empty())
	{
		int now = q.front(), len = v2[now].size();
		q.pop();
		for (int i = 0, goal, cost ; i < len ; i++)
		{
			goal = v2[now][i].first;
			cost = v2[now][i].second;
			if (!chk[now][i] && ans[now] == cost + ans[goal]) 
			{
				chk[now][i] = true;
				q.push(goal);
				cnt++;
			}
		}
	}
	
	cout << ans[en] << '\n' << cnt;
}