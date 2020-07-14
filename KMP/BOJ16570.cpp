// 

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
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
using namespace std;

int n, arr[1000000], k[1000000], mm[1000001], da = 0;

int main() {
    cin >> n;
    for (int i = n-1 ; i >= 0 ; i--) cin >> arr[i];
    
    for (int i = 1, j = 0 ; i < n ; i++) {
        while (j > 0 && arr[i] != arr[j]) j = k[j-1];
        if (arr[i] == arr[j]) k[i] = ++j;
    }

    for (int i = 0 ; i < n ; i++) {
        mm[k[i]]++;
        da = max(k[i], da);
    }

    if (!da) return cout << -1, 0;
    cout << da << ' ' << mm[da];
}