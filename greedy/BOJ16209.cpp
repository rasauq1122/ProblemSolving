// 2019.11.25

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define ss second
#define ll long long

pair <ll, ll> pp[500000], pm[500000];

ll foo(ll n)
{
    return n%2 ? (n-1)/2+1 : -(n/2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, lp, lm;
    priority_queue < ll > qp;
    priority_queue < ll, vector <ll>, greater <ll> > qm;
    
    cin >> n;
    for (int i = 0, x ; i < n ; i++)
    { 
        cin >> x;
        if (x > 0) qp.push(x);
        else qm.push(x);
    }

    lp = qp.size(), lm = qm.size();
    if (lp)
    {
        for (ll cnt = 0 ; ; cnt++) 
        {
            pp[cnt] = {foo(cnt),qp.top()};
            qp.pop();
            if (qp.empty()) break;
        }
    }

    if (lm)
    {
        for (ll cnt = 0 ; ; cnt++) 
        {
            pm[cnt] = {foo(cnt),qm.top()};
            qm.pop();
            if (qm.empty()) break;
        }
    }

    sort(pp,pp+lp);
    sort(pm,pm+lm);

    if (!lp) for (int i = 0 ; i < lm ; i++) cout << pm[i].ss << ' ';
    else if (!lm) for (int i = 0 ; i < lp ; i++) cout << pp[i].ss << ' ';
    else
    {
        ll m = max({pp[0].ss*pm[0].ss,pp[0].ss*pm[lm-1].ss,pp[lp-1].ss*pm[0].ss,pp[lp-1].ss*pm[lm-1].ss});
        if (m == pp[0].ss*pm[0].ss)
        {
            for (int i = 0 ; i < lm ; i++) cout << pm[lm-1-i].ss << ' ';
            for (int i = 0 ; i < lp ; i++) cout << pp[i].ss << ' ';
        }
        else if (m == pp[0].ss*pm[lm-1].ss)
        {
            for (int i = 0 ; i < lm ; i++) cout << pm[i].ss << ' ';
            for (int i = 0 ; i < lp ; i++) cout << pp[i].ss << ' ';
        }
        else if (m == pp[lp-1].ss*pm[0].ss)
        {
            for (int i = 0 ; i < lp ; i++) cout << pp[i].ss << ' ';
            for (int i = 0 ; i < lm ; i++) cout << pm[i].ss << ' ';
        }
        else
        {
            for (int i = 0 ; i < lp ; i++) cout << pp[i].ss << ' ';
            for (int i = 0 ; i < lm ; i++) cout << pm[lm-1-i].ss << ' ';
        }
        
    }
    
}