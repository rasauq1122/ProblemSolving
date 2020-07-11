// 2020.07.11

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

int n, k;
int dp[201][201];

int foo(int m, int k) {
    if (!m) return 1;
    if (!k) return 0;
    if (dp[m][k] != -1) return dp[m][k];
    
    int sum = 0;
    for (int i = 0 ; i <= min(n,m) ; i++) {
        sum += foo(m-i,k-1);
        sum %= 1000000000;
    }
    return dp[m][k] = sum; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    MS(dp);
    
    cout << foo(n,k);
}