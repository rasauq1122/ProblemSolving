// 2020.07.02

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define piii pair<int,pii>
using namespace std;

int n, m, be, en;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    V(V(pii)) v(n+1);
    for (int i = 0, x, y, c ; i < m ; i++) {
        cin >> x >> y >> c;
        v[x].pb({y,c});
    }

    cin >> be >> en;
    V(int) vis(n+1, -1);
    V(int) pre(n+1);
    GPQ(piii) pq;
    pq.push({0,{-1,be}});
    while(!pq.empty()) {
        int cost = pq.top().ff;
        int pr = pq.top().ss.ff;
        int vtx = pq.top().ss.ss;
        pq.pop();
        if (vis[vtx] != -1) continue;
        vis[vtx] = cost;
        pre[vtx] = pr;
        for (int i = 0 ; i < v[vtx].size() ; i++) {
            pii next = v[vtx][i];
            if (vis[next.ff] != -1) continue;
            pq.push({cost + next.ss, {vtx, next.ff}});
        }
    }

    cout << vis[en] << '\n';
    S(int) s;
    for (int i = en ; i != -1 ; i = pre[i]) s.push(i);
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    } 
}