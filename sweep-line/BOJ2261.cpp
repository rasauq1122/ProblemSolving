// 2019.11.13

#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

int dis(pii a, pii b)
{
    return (a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss);
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    pii a[100000] = {};
    set < pii > s;

    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i].ff >> a[i].ss;

    sort(a,a+n);
    s.insert({a[0].ss,a[0].ff});
    s.insert({a[1].ss,a[1].ff});

    int k = 0, ans = dis(a[0],a[1]);
    for (int i = 2 ; i < n ; i++)
    {
        pii now = a[i];
        while (k < i)
        {
            int dx = now.ff-a[k].ff;
            if (dx*dx > ans) 
            {
                s.erase({a[k].ss,a[k].ff});
                k++;
            }
            else break;
        }

        int d = (int)(sqrt((double)ans))+1;

        pii le = {now.ss-d,-100000};
        pii ri = {now.ss+d,100000};

        auto st = s.lower_bound(le);
        auto en = s.upper_bound(ri);

        for (auto j = st ; j != en ; j++) if (dis(*j,{a[i].ss,a[i].ff}) < ans) ans = dis(*j,{a[i].ss,a[i].ff});
        s.insert({a[i].ss,a[i].ff});
    }

    cout << ans;
}