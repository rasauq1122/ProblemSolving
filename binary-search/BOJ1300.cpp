// 2020.05.02

#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
ll n, k;

bool yes(ll p) {
    ll sum = 0;
    for (ll i = 1 ; i <= n ; i++) {
        ll cnt = min(p/i,n);
        if (cnt) sum += cnt;
        else break;
    }
    return sum < k;
}

int main() {
    cin >> n >> k;
    ll s = 0, f = n*n; 
    while(f-s > 1){
        ll mid = (s+f)/2;
        if(yes(mid)) s = mid;
        else f = mid;
    }
    cout << f;
}   