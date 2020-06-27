// 2019.12.26

#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

ll cp(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2 - x2*y1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll x[10000], y[10000], n, sum = 0;
    cin >> n;

    for (int i = 0 ; i < n ; i++) cin >> x[i] >> y[i];
    for (int i = 1 ; i < n ; i++)
    {
        x[i] = x[i] - x[0];
        y[i] = y[i] - y[0];
    }
    for (int i = 1 ; i < n-1 ; i++) sum += cp(x[i],y[i],x[i+1],y[i+1]);
    sum = abs(sum);
    cout << sum/2 << '.' << (sum%2 ? 5 : 0);
}   