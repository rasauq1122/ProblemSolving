// 2020.07.06

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
    for (int i = 0 ; i < t ; i++) {
        ll n;
        cin >> n;
        ll s = 1, f = 141421356;
        while (f-s > 1) {
            ll mid = (f+s)/2;
            if (mid*(mid+1)/2 <= n) s = mid;
            else f = mid;
        }
        cout << s << '\n';
    }
}