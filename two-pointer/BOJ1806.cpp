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

int n, s, arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];

    int so = 100001;
    for (int i = 0, j = 0, sum = arr[0] ; ; ) {
        bool chk = sum < s;
        while (i < j && sum >= s) sum -= arr[i++];
        if (!chk) {
            if (sum >= s) return cout << 1, 0;
            sum += arr[--i];
            so = min(so, j - i + 1);
        }
        if (j == n-1) break;
        sum += arr[++j];
    }
    cout << (so == 100001 ? 0 : so);   
}