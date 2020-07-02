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
using namespace std;

int r, c, t, a1, a2, b, map[50][50], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, add[50][50];

pii next1(pii a) {
    if (a.ff == a1 && a.ss != 0) return make_pair(a.ff, a.ss-1);
    if (a.ss == 0 && a.ff != 0) return make_pair(a.ff-1, a.ss);
    if (a.ff == 0 && a.ss != c-1) return make_pair(a.ff, a.ss+1);
    return make_pair(a.ff+1, a.ss);
}

pii next2(pii a) {
    if (a.ff == a2 && a.ss != 0) return make_pair(a.ff, a.ss-1);
    if (a.ss == 0 && a.ff != r-1) return make_pair(a.ff+1, a.ss);
    if (a.ff == r-1 && a.ss != c-1) return make_pair(a.ff, a.ss+1);
    return make_pair(a.ff-1, a.ss);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> t;
    bool chk = false;
    for (int i = 0 ; i < r ; i++) for (int j = 0 ; j < c ; j++) {
        cin >> map[i][j];
        if (map[i][j] == -1 && !chk) {
            chk = true;
            a1 = i;
            a2 = i+1;
            b = j;
        }
    }

    Q(pii) q;
    for (int ti = 0 ; ti < t ; ti++) {
        for (int i = 0 ; i < r ; i++) for (int j = 0 ; j < c ; j++) if (map[i][j] > 0) q.push({i,j});
        memset(add, 0, sizeof(add));
        while (!q.empty()) {
            int x = q.front().ff;
            int y = q.front().ss;
            int d = map[x][y]/5;
            q.pop();
            for (int i = 0 ; i < 4 ; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
                if (map[xx][yy] == -1) continue;
                add[xx][yy] += d;
                map[x][y] -= d;
            }
        }
        for (int i = 0 ; i < r ; i++) for (int j = 0 ; j < c ; j++) map[i][j] += add[i][j];
        for (pii now = make_pair(a1, b) ; ; ) {
            pii next = next1(now);
            if (map[now.ff][now.ss] != -1) {
                if (map[next.ff][next.ss] != -1) map[now.ff][now.ss] = map[next.ff][next.ss];
                else map[now.ff][now.ss] = 0;
            }
            now = next;
            if (map[next.ff][next.ss] == -1) break;
        }
        for (pii now = make_pair(a2, b) ; ; ) {
            pii next = next2(now);
            if (map[now.ff][now.ss] != -1) {
                if (map[next.ff][next.ss] != -1) map[now.ff][now.ss] = map[next.ff][next.ss];
                else map[now.ff][now.ss] = 0;
            }
            now = next;
            if (map[next.ff][next.ss] == -1) break;
        }
    }
    int sum = 0;
    for (int i = 0 ; i < r ; i++) for (int j = 0 ; j < c ; j++) if (map[i][j] > 0) sum += map[i][j];
    cout << sum;
}