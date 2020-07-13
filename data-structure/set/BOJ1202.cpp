// 2020.07.13

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#include <set>
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
using namespace std;

int n, k;
ll sum;
pii jew[300000];

bool cmp(pii a, pii b) {
    if (a.ff > b.ff) return 1;
    if (a.ff < b.ff) return 0;
    if (a.ss >= b.ss) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0, x, y ; i < n ; i++) {
        cin >> x >> y;
        jew[i] = {y,x};
    } 

    sort(jew, jew+n, cmp);

    multiset<int> mts;
    for (int i = 0, x ; i < k ; i++) {
        cin >> x;
        mts.insert(x);
    }
    
    for (int i = 0 ; i < n ; i++) {
        auto it = mts.lower_bound(jew[i].ss);
        if (it != mts.end()) {
            sum += jew[i].ff;
            mts.erase(it);
        }  
    }

    cout << sum;
}