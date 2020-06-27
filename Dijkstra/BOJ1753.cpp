// 2020.04.10

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define pii pair <int,int>

vector < vector <pii> > graph(20005);
int dist[20005];

int main()
{
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 0, go, end, cost ; i < m ; i++) {
        cin >> go >> end >> cost;
        graph[go].push_back({end, cost});
    }

    priority_queue < pii, vector<pii>, greater<pii> > pq;
    pq.push({0,start});
    memset(dist, -1, sizeof(dist));

    while (!pq.empty()) {
        int now = pq.top().second, cost = pq.top().first, len = graph[now].size();
        pq.pop();
        if (dist[now] != -1) continue;
        dist[now] = cost;

        for (int i = 0 ; i < len ; i++) if(dist[graph[now][i].first] == -1) pq.push({cost+graph[now][i].second, graph[now][i].first});
    }

    for (int i = 1; i <= n ; i++) if (dist[i] == -1) cout << "INF\n"; else cout << dist[i] << "\n";
}   