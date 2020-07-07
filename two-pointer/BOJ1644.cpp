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

int n, np[4000001] = {1, 1, }, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    V(int) v;
    for (int i = 2 ; i <= 4000000 ; i++) if (!np[i]) {
        v.pb(i);
        for (int j = 2*i ; j <= 4000000 ; j += i) np[j] = 1;
    }

    for (int i = 0, j = 0, sum = v[i] ; ; ) {
        if (sum > n) {
            if (i == j) break;
            else sum -= v[i++];
        } else if (sum < n) {
            if (j == v.size()-1) break;
            else sum += v[++j];
        } else {
            cnt++;
            if (j == v.size()-1 || i == j) break;
            sum -= v[i++];
        }
    }
    cout << cnt;
}