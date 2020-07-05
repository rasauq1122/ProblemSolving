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

int n, arr[100000], a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    b = n-1;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    if ((arr[0] > 0) == (arr[n-1] > 0)) {
        if (arr[0] > 0) return cout << arr[0] << ' ' << arr[1], 0;
        else return cout << arr[n-2] << ' ' << arr[n-1], 0;
    }
    for (int i = 0, s, f, p ; i < n ; i++) {
        s = 0, f = n-1;
        while (f-s > 1) {
            int mid = (s+f)/2;
            if (arr[mid] <= -arr[i]) s = mid;
            else f = mid;
        }
        if (abs(arr[i]+arr[f]) > abs(arr[i]+arr[s])) p = s;
        else p = f;

        if (i == f) p = s;
        else if (i == s) p = f;

        if (abs(arr[a]+arr[b]) > abs(arr[i]+arr[p])) {
            a = i;
            b = p;
        }
    }
    cout << arr[min(a,b)] << ' ' << arr[max(a,b)];
}