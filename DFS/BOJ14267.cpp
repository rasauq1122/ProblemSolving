// 2020.03.19

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector < vector <int> > graph(100001);
    vector < int > weight(100001);
    int n, k;

    cin >> n >> k;

    for (int i = 1, x ; i <= n ; i++)
    {
        cin >> x;
        if (x > 0) graph[x].push_back(i); 
    }

    for (int i = 1, x, y ; i <= k ; i++)
    {
        cin >> x >> y;
        weight[x] += y;
    }

    queue < int > q;
    q.push(1);
    
    while (!q.empty())
    {
        int now_num = q.front(), len = graph[now_num].size();
        q.pop();
    
        for (int i = 0 ; i < len ; i++)
        {
            weight[graph[now_num][i]] += weight[now_num];
            q.push(graph[now_num][i]);
        }
    }

    for (int i = 1 ; i <= n ; i++) cout << weight[i] << ' ';
}