// 2020.07.09

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

int n, k, loc[11][2], pos[11], map[13][13], dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
S(int) s[13][13];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) for (int j = 1 ; j <= n ; j++) cin >> map[i][j];

    for (int i = 1, x ; i <= k ; i++) {
        cin >> loc[i][0] >> loc[i][1] >> x;
        switch (x) {
            case 1: pos[i] = 0; break;
            case 2: pos[i] = 2; break;
            case 3: pos[i] = 1; break;
            case 4: pos[i] = 3; break;
        }
        s[loc[i][0]][loc[i][1]].push(i);
    } 

    for (int t = 1 ; t <= 1000 ; t++) {
        for (int p = 1 ; p <= k ; p++) {
            int x = loc[p][0], y = loc[p][1];
            int xx = x + dx[pos[p]], yy = y + dy[pos[p]];
            if (xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] == 2) pos[p] = (pos[p]+2)%4;
            
            xx = x + dx[pos[p]], yy = y + dy[pos[p]];
            if (xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] == 2) continue;

            if (map[xx][yy]) {
                Q(int) tmp;
                while (true) {
                    int q = s[x][y].top();
                    tmp.push(q);
                    s[x][y].pop();
                    if (q == p) break; 
                }
                while (!tmp.empty()) {
                    int now = tmp.front();
                    loc[now][0] = xx;
                    loc[now][1] = yy;
                    tmp.pop();
                    s[xx][yy].push(now);
                }
            } else {
                S(int) tmp;
                while (true) {
                    tmp.push(s[x][y].top());
                    s[x][y].pop();
                    if (tmp.top() == p) break; 
                }
                while (!tmp.empty()) {
                    int now = tmp.top();
                    loc[now][0] = xx;
                    loc[now][1] = yy;
                    tmp.pop();
                    s[xx][yy].push(now);
                }
            }

            if (s[xx][yy].size() > 3) return cout << t, 0;
        }
    }

    cout << -1;
}