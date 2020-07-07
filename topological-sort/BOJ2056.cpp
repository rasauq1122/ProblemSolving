// 2020.07.07

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
#define IMAX ((1LL<<31)-1)
#define MS(T) memset(T, -1, sizeof(T))
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    V(int) cst(n+1), wai(n+1), in(n+1);
    V(V(int)) v(n+1);

    for (int i = 1, m ; i <= n ; i++) {
        cin >> cst[i] >> in[i];
        for (int j = 0, k ; j < in[i] ; j++) {
            cin >> k;
            v[k].pb(i);
        }
    }

    Q(int) q;
    for (int i = 1 ; i <= n ; i++) if (!in[i]) q.push(i); 
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0 ; i < v[x].size() ; i++)  {
            int nxt = v[x][i];
            if (in[nxt]) {
                wai[nxt] = max(wai[nxt], wai[x]+cst[x]);
                if (!--in[nxt]) q.push({nxt});
            }
        }
    }
    int da = 0;
    for (int i = 1 ; i <= n ; i++) da = max(da, wai[i]+cst[i]);
    cout << da;
}