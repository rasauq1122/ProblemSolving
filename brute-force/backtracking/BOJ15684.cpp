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
#define BIT(A,B) !!((A)&(1<<(B)))
using namespace std;

int n, m, h, so = 4;
bool arr[11][31];

pii i2p(int i) {
    return make_pair(i/h+1, i%h+1);
}

int p2i(pii p) {
    return (p.ff-1)*h + p.ss-1;
}

void btk(int x, int y, int k) {
    arr[x][y] = 1;
    bool okay = true;
    for (int i = 1 ; i <= n ; i++) {
        int st = i;
        for (int j = 1 ; j <= h ; j++) {
            if (arr[st][j]) st++;
            else if (arr[st-1][j]) st--;
        }   
        if (st != i) {
            okay = false;
            break;
        } 
    }
    if (okay) {
        so = min(so, k);
        arr[x][y] = 0;
        return;
    }

    int i = p2i({x,y})+1;
    if (k < 3) for (; i < (n-1)*h ; i++) {
        pii p = i2p(i);
        int x = p.ff, y = p.ss;
        if (!arr[x-1][y]&&!arr[x][y]&&!arr[x+1][y]) btk(x,y,k+1);
    }
    arr[x][y] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> h;
    for (int i = 0, x, y ; i < m ; i++) {
        cin >> x >> y;
        arr[y][x] = 1;
    }
    btk(0,0,0);
    cout << (so == 4 ? -1 : so);
}