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

int n, m, arr[8][8];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, sum;
bool vis[8][8], can[6][4] = {{}, {1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,0}, {1,1,1,1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    V(piii) v;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) {
        cin >> arr[i][j];
        if (arr[i][j] != 0 && arr[i][j] != 6) v.pb({arr[i][j],{i,j}});
        if (arr[i][j]) sum++;
    }

    Q(pii) q;
    int len = v.size(), so = n*m - sum;
    for (int i = 0 ; i < (1<<2*len) ; i++) {
        int cnt = n*m - sum;
        for (int j = 0 ; j < len ; j++) {
            for (int k = 0, p = BIT(i,2*j+1)*2+BIT(i,2*j) ; k < 4 ; k++, p++) {
                if (p == 4) p = 0;
                if (!can[v[j].ff][p]) continue;
                for (int x = v[j].ss.ff, y = v[j].ss.ss ; ; x += dx[k], y += dy[k]) {
                    if (x < 0 || y < 0 || x >= n || y >= m) break;
                    if (arr[x][y] == 6) break;
                    if (!arr[x][y]) {
                        arr[x][y] = 7;
                        q.push({x,y});
                        cnt--;
                    }
                }
            } 
        }   
        while (!q.empty()) {
            arr[q.front().ff][q.front().ss] = 0;
            q.pop();
        }    
        so = min(so, cnt);
    }
    cout << so;
}