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

int n, a = 0, b = 1, c = 2;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    V(ll) v(n);
    for (int i = 0 ; i < n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    for (int i = 0 ; i < n ; i++) for (int j = i+1, f, s, nc; j < n ; j++) {
        s = 0, f = n-1; 
        ll now = v[i]+v[j];
        while (f-s > 1) {
            int mid = (s+f)/2;
            if (v[mid] <= -now) s = mid;
            else f = mid;
        }

        ll so = 3000000001;
        for (int k = s-1 ; k <= f+1 ; k++) if (k >= 0 && k < n && k != i && k != j) {
            if (so > abs(now+v[k])) {
                so = abs(now+v[k]);
                nc = k;
            }
        }
        if (abs(v[a]+v[b]+v[c]) > abs(now+v[nc])) a = i, b = j, c = nc;
    }
    ll nv[3] = {v[a], v[b], v[c]};
    sort(nv, nv+3);
    cout << nv[0] << ' ' << nv[1] << ' ' << nv[2];
}