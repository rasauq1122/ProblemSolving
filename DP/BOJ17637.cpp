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
using namespace std;

int n, show[18];
int expe[18];
double dp[1000][7][7][7], rst;

int cal(int type) {
    if (type > 11) return 10000 + (type-11)*1000;
    if (type > 5) return 1000 + (type-5)*100;
    return type*100 + 100;
}

int type(int a, int b, int c) {
    if (a == b && b == c) return 11 + a;
    if (a == b || a == c) return 5 + a;
    if (b == c) return 5 + b;
    return max({a, b, c}) - 1;
}

double foo(int n, int a, int b, int c) {
    if (dp[n][a][b][c]) return dp[n][a][b][c];
    int now = cal(type(a,b,c));
    if (n == 0) return dp[n][a][b][c] = cal(type(a,b,c));

    // first, we need to decide re-roll is good for me.
    double sum = 0;
    for (int i = 1 ; i <= 6 ; i++) sum += foo(n-1, b, c, i);   
    if (sum <= 6*now) return dp[n][a][b][c] = now;
    return dp[n][a][b][c] = sum/6;
}

int main() {
    cin >> n;
    for (int i = 1 ; i <= 6 ; i++) for (int j = 1 ; j <= 6 ; j++) for (int k = 1 ; k <= 6 ; k++) foo(n-3, i, j, k);
    for (int i = 1 ; i <= 6 ; i++) for (int j = 1 ; j <= 6 ; j++) for (int k = 1 ; k <= 6 ; k++) rst += dp[n-3][i][j][k];
    printf("%.6lf", rst/216);
}