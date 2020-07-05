// 2020.07.04

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

ll n, k, d, arr[10000][3];

bool yes(ll p) {
    ll cnt = 0;
    for (int i = 0 ; i < k ; i++) if (p >= arr[i][0]) cnt += (min(p, arr[i][1])-arr[i][0])/arr[i][2] + 1;
    return d > cnt; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> d;
    for (int i = 0 ; i < k ; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    ll s = 1, f = n;
    while (f-s > 1) {
        ll mid = (f+s)/2;
        if (yes(mid)) s = mid;
        else f = mid;
    }
    cout << f;
}