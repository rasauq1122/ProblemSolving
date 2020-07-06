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

int n, in[100001], post[100001], arr[100001];

void make(int is, int ie, int ps, int pe) {
    if (is > ie) return;
    cout << post[pe] << ' ';
    int k = arr[post[pe]];
    make(is, k-1, ps, ps - is + k-1); 
    make(k+1, ie, ps - is + k, pe - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> in[i];
        arr[in[i]] = i;
    }
    for (int i = 1 ; i <= n ; i++) cin >> post[i];
    make(1, n, 1, n);
}