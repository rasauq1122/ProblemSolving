// 2020.07.16

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
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define endl '\n'
#define blk ' '
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

ll t, cnt;
int n, m, arr[1001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    cin >> n;
    for (int i = 1, x ; i <= n ; i++) {
        cin >> x;
        arr[i][0] = arr[i-1][0] + x;
    }

    cin >> m;
    for (int i = 1, x ; i <= m ; i++) {
        cin >> x;
        arr[i][1] = arr[i-1][1] + x;
    }

    V(ll) v, sh;
    for (int i = 0 ; i <= m ; i++) for (int j = i+1 ; j <= m ; j++) v.pb(arr[j][1] - arr[i][1]);
    sort(v.begin(), v.end());
    
    sh.pb(1);
    for (int i = 1 ; i < v.size() ; i++) {
        if (v[i-1] == v[i]) sh.pb(sh.back()+1);
        else sh.pb(1);
    }

    for (int i = 0 ; i <= n ; i++) for (int j = i+1 ; j <= n ; j++) {
        ll fnd = t - arr[j][0] + arr[i][0];
        int lo = 0, hi = v.size();
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (v[mid] <= fnd) lo = mid;
            else hi = mid;
        }
        if (v[lo] == fnd) cnt += sh[lo];
    }

    cout << cnt;
}