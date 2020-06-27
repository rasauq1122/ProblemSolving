// 2020.05.30

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

int n;
stack < pii > s;
long long da;

void push(int e) {
    if (s.top().ff > e) {
        int cnt = 0;
        for (; s.top().ff > e ; s.pop()) {
            da = max(da, 1LL*s.top().ff*(s.top().ss+cnt));
            cnt += s.top().ss;
        }
        s.push({e,cnt});
    }
    s.push({e,1});
}

int main() {
    s.push({0,1});
    while (true) {
        da = 0;
        cin >> n;
        if (n == 0) return 0;
        for (int i = 1, a ; i <= n ; i++) {
            cin >> a;
            push(a);
        }    
        push(0);
        cout << da << '\n';
    }
}