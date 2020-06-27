// 2019.11.16

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#define and &&
#define or ||
using namespace std;

bool isIn(int i, int j, int k)
{
    return  j <= i and i <= j+k;
}

int abs(int n)
{
    return n < 0 ? -n : n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, l, h[100002] = {}, cnt = 0; 
    pair <int,int> a[100000] = {};
    cin >> m >> n >> l;
    for (int i = 1 ; i <= m ; i++) cin >> h[i];
    for (int i = 0 ; i < n ; i++) cin >> a[i].first >> a[i].second;

    sort(h+1,h+m+1);
    sort(a,a+n);
    h[0] = -1000000000;
    h[m+1] = 2000000000;
    for (int i = 0, j = 1 ; i < n ; i++)
    {
        int k = a[i].first, q = a[i].second;

        while (h[j] < k) j++;
        if ((isIn(k,h[j-1],l) or isIn(k,h[j]-l,l)) and q <= l and (abs(k-h[j-1])+q <= l or abs(k-h[j])+q <= l)) cnt++;
    }

    cout << cnt;
}