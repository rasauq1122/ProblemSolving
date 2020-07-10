// 2020.07.10

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
using namespace std;

int n, m, arr[10][10], vis[10][10], dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, cnt = 0, ans = IMAX;
V(V(pii)) v;

bool safe(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

void bfs(int ix, int iy, int num) {
    vis[ix][iy] = num;
    Q(pii) q;
    q.push({ix,iy});
    
    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int xx = x + dx[i], yy = y + dy[i];

            if (!safe(xx,yy) || vis[xx][yy]) continue;
            if (arr[xx][yy]) {
                vis[xx][yy] = num;
                q.push({xx, yy});
            } else vis[xx][yy] = -num;
        }
    }
}

void btk(int k, int cs) {
    if (k == (1<<cnt)-1) {
        ans = min(ans, cs);
        return;
    }
    for (int i = 1 ; i <= cnt ; i++) if (BIT(k,i-1)) 
        for (int j = 0 ; j < v[i].size() ; j++) if (!BIT(k,v[i][j].ff-1)) btk(k+(1<<v[i][j].ff-1), cs + v[i][j].ss);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) cin >> arr[i][j];
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) if (arr[i][j] && !vis[i][j]) bfs(i,j,++cnt);  

    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) printf("%2d ",vis[i][j]);
    //     cout << '\n';
    // }

    v = V(V(pii))(cnt+1);
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) if (vis[i][j] < 0) for (int k = 0 ; k < 4 ; k++) {
        int fx = i + dx[k], fy = j + dy[k], bx = i + dx[(k+2)%4], by = j + dy[(k+2)%4];
        if (!safe(fx,fy) || !safe(bx,by)) continue;
        if (vis[bx][by] <= 0 || vis[fx][fy] > 0) continue;
        
        int st = vis[bx][by], c = 2;
        while (safe(fx+dx[k], fy+dy[k]) && vis[fx+dx[k]][fy+dy[k]] <= 0) {
            fx += dx[k];
            fy += dy[k];
            c++;
        }

        if (safe(fx+dx[k], fy+dy[k]) && vis[fx+dx[k]][fy+dy[k]] != st) v[st].pb({vis[fx+dx[k]][fy+dy[k]], c});
    }

    // for (int i = 1 ; i <= cnt ; i++) for (int j = 0 ; j < v[i].size() ; j++) cout << i << " to " << v[i][j].ff << " : " << v[i][j].ss << '\n';
    btk(1, 0);
    cout << (ans == IMAX ? -1 : ans);
}   