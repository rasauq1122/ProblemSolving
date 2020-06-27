// 2019.12.24

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, in[501] = {}, data[501] = {}, wait[501] = {}, ans[501] = {};
	cin >> n;
	vector < vector < int > > v(n+1);
	
	for (int i = 1, x ; i <= n ; i++)
	{	
		cin >> data[i] >> x;
		while (x != -1)
		{
			v[x].push_back(i);
			cin >> x;
			in[i]++;
		}
	}
	
	queue < int > q;
	for (int i = 1 ; i <= n ; i++) if (!in[i]) q.push(i);
	
	while (!q.empty())
	{
		int now = q.front(), len = v[now].size();
		q.pop();
		ans[now] = data[now] + wait[now];
		
		for (int i = 0 ; i < len ; i++) 
		{
			wait[v[now][i]] = ans[now] > wait[v[now][i]] ? ans[now] : wait[v[now][i]];
			if (!--in[v[now][i]]) q.push(v[now][i]);	
		}
	}
	
	for (int i = 1 ; i <= n ; i++) printf("%d\n",ans[i]);
}