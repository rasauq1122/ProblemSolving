// 2019.12.26

#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct point{
    int x, y, p, q;
} PO;

#define PI 3.141592

bool lowest(PO a, PO b)
{
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

bool cmp(PO a, PO b)
{
    if (1LL*a.q*b.p != 1LL*a.p*b.q) return 1LL*a.q*b.p < 1LL*a.p*b.q;
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

long long cp(PO a, PO b, PO c)
{
    return 1LL*(b.x - a.x)*(c.y - a.y) - 1LL*(b.y - a.y)*(c.x - a.x);
}

double len(PO a, PO b)
{
    return sqrt(1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    PO p[10000], p2[10001];
    int n, r;
    
    cin >> n >> r;

    for (int i = 0 ; i < n ; i++) cin >> p[i].x >> p[i].y;

    sort(p, p+n, lowest);
    for (int i = 0 ; i < n ; i++)
    {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }

    sort(p, p+n, cmp);
    stack < PO > s;
    s.push(p[0]);
    s.push(p[1]);

    for (int i = 2 ; i < n ; i++)
    {
        PO first, second;
        first = s.top();
        s.pop();
        second = s.top();
        
        long long now = cp(second, first, p[i]);
        if (now >= 0)
        {
            if (now > 0) s.push(first);
            s.push(p[i]);
        }
        else i--;
    }

    int cnt = s.size();

    while (!s.empty()) 
    {
        p2[s.size()-1] = s.top();
        s.pop();
    }
    p2[cnt] = p[0];

    double sum = 2*PI*r;
    for (int i = 0 ; i < cnt ; i++) sum += len(p2[i],p2[i+1]);
    cout << floor(0.5+sum);
}