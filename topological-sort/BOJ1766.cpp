// 2019.12.24

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m, in[32001] = {};
	cin >> n >> m;
	vector < vector < int > > v(n+1);
	for (int i = 0, x, y ; i < m ; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		in[y]++;
	}
	
	priority_queue < int , vector < int > , greater < int > > q;
	queue <int> q_print;
	for (int i = 1 ; i <= n ; i++) if (!in[i]) q.push(i); 
	
	while (!q.empty())
	{
		int now = q.top();
		q.pop();
		q_print.push(now);
		int len = v[now].size();
		for (int i = 0 ; i < len ; i++) if (!--in[v[now][i]]) q.push(v[now][i]);
	}
	
	while (!q_print.empty())
	{
		cout << q_print.front() << ' ';
		q_print.pop();
	}

}