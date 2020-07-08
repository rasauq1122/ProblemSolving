// 2020.07.08

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
#define UNIST "UNIST"
using namespace std;

int n, dp[100000][6];
str arr[100000];
bool chk[100000][5][5];

int foo(int n, int p) {
    if (dp[n][p] != -1) return dp[n][p];
    if (!p) return dp[n][p] = 1;
    if (!n) return dp[n][p] = chk[n][0][p-1];

    int sum = foo(n-1, p);
    for (int k = p-1 ; k >= 0 ; k--) if (chk[n][k][p-1]) {
        sum += foo(n-1, k);
        sum %= 1000000007;
    }
    return dp[n][p] = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    MS(dp);

    for (int i = 0, k ; i < n ; i++) {
        switch (arr[i][0]) {
            case 'U': k = 0; break;
            case 'N': k = 1; break;
            case 'I': k = 2; break;
            case 'S': k = 3; break;
            case 'T': k = 4; break;
            default: k = -1; break;
        }
        if (k == -1) continue;
        chk[i][k][k] = 1;
        int siz = arr[i].size();
        int len = min(5, siz);
        for (int j = k+1, l = 1 ; l < len ; j++, l++) {
            if (arr[i][l] == UNIST[j]) chk[i][k][j] = 1;
            else break;
        }
    }

    cout << foo(n-1, 5);
}