// 2020.07.07

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#include <map>
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

int n, m, arr[100][2], dp[101][10000];
V(V(int)) v(101), ps(101, V(int)(101,-1));

int foo(int n, int m) { 
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0) {
        if (m) return -IMAX;
        return ps[n][v[n].size()];
    }
    
    int da = 0;
    for (int i = 0 ; i*n <= m && i <= v[n].size() ; i++) da = max(da, foo(n-1,m-i*n) + ps[n][i]);
    return dp[n][m] = da;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) cin >> arr[i][0];
    for (int i = 0 ; i < n ; i++) cin >> arr[i][1];
    for (int i = 0 ; i < n ; i++) v[arr[i][1]].pb(arr[i][0]);
    for (int i = 0 ; i <= 100 ; i++) sort(v[i].begin(), v[i].end(), greater<int>());
    for (int i = 0 ; i <= 100 ; i++) ps[i][0] = 0;
    for (int i = 0 ; i <= 100 ; i++) for (int j = 1 ; j <= v[i].size() ; j++) ps[i][j] = ps[i][j-1] + v[i][j-1];

    MS(dp);
    for (int i = 0 ; i <= 10000 ; i++) if (foo(100,i) >= m) return cout << i, 0;
}