// 2020.07.05

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

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int ti = 0, n; ti < t ; ti++) {
        cin >> n;
        V(ll) v(n);
        for (int i = 0 ; i < n ; i++) cin >> v[i];
        v.pb(0);
        sort(v.begin(), v.end());
        V(ll) ps(n+1);
        for (int i = 1 ; i <= n ; i++) ps[i] = ps[i-1] + v[i];

        ll sum = 0;
        for (int i = 1 ; i <= n ; i++) {
            ll so = 10000*4000+1;
            for (int j = i, k = 0 ; j <= n ; j++, k++) so = min(so, v[j]*i - (ps[j]-ps[k]));
            sum += so;
        }
        cout << sum << '\n';
    }
}