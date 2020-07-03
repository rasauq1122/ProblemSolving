// 2020.07.03

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
#define piii pair<pii, int>
using namespace std;

int n, map[50][50], cnt;

void btk(int x, int y, int k) {
    if (k-1 > n) return;
    map[x][y] = k;
    for (int i = 0 ; i < 3 ; i++) {
        int xx = x, yy = y;
        if (i == 0) {
            if (x%2 == y%2) xx--;
            else xx++;
        } else if (i == 1) yy++;
        else yy--;

        if (map[xx][yy] == map[x][y]-1) continue;
        if (map[xx][yy]) {
            if (map[x][y]-1 == n) cnt++;
            continue;
        }
        btk(xx,yy,k+1);
    }
    map[x][y] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    map[25][25] = 1;
    btk(24, 25, 2);
    cout << cnt;
}