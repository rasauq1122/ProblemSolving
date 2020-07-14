// 2020.07.14

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define piii pair<int,pii>
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
#define IMAX ((1LL<<31)-1)
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1<<(B))))
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
using namespace std;

int n, m, arr[100][100], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool vis[100][100][2];

bool bfs(int lim) {
    if (lim < arr[0][0]) return false;

    Q(piii) q;
    memset(vis, 0, sizeof(vis));
    q.push({0,{0,1}});
    vis[0][0][1] = 1;

    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss.ff;
        bool j = q.front().ss.ss;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (vis[xx][yy][j]) continue;
            if (lim < arr[xx][yy]) continue;
            q.push({xx,{yy,j}});
            vis[xx][yy][j] = 1;
        }
        if (j) for (int i = 0 ; i < 4 ; i++) {
            int xx = x + 2*dx[i], yy = y + 2*dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (vis[xx][yy][0]) continue;
            if (lim < arr[xx][yy]) continue;
            q.push({xx,{yy,0}});
            vis[xx][yy][0] = 1;
        }
    }

    return vis[n-1][m-1][0] || vis[n-1][m-1][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) cin >> arr[i][j];

    int lo = arr[0][0]-1, hi = (1e+9);
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        if (bfs(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}