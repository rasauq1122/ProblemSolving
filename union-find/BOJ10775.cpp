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
using namespace std;

int g, p, nxt[100001], cnt;

int insert(int n) {
    if (!n) return -1;
    if (nxt[n] == -1) return nxt[n] = n-1;
    return nxt[n] = insert(nxt[n]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> g >> p;
    memset(nxt, -1, sizeof(nxt));
    bool go = true;
    for (int i = 0, x ; i < p ; i++) {
        cin >> x;
        if (!go) continue;
        if (insert(x) != -1) cnt++;
        else go = false;
    }
    cout << cnt;
}