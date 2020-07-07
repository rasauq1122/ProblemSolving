// 

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

int n, rgb[1000][3], dp[3][1000][3], so = 1000*1000+1;

int foo(int lst, int ptr, int now) {
    if (dp[lst][ptr][now] != -1) return dp[lst][ptr][now];
    if (ptr == 0) {
        if (lst == now) return dp[lst][ptr][now] = 1000*1000+1;
        return dp[lst][ptr][now] = rgb[ptr][now];
    }
    
    int so = 1000*1000+1;
    for (int i = 0 ; i < 3 ; i++) if (i != now) so = min(so, foo(lst,ptr-1,i));
    return dp[lst][ptr][now] = so + rgb[ptr][now]; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0 ; i < n ; i++) cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    cout << min({foo(0,n-1,0), foo(1,n-1,1), foo(2,n-1,2)});
}