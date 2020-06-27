// 2019.12.26

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct point{
    int x, y, p, q, i;
} PO;

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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    PO data[1000], jail;
    vector < PO > p;
    int n, m, cnt = 0;
    bool chk[1000], over = false;
    cin >> n >> jail.x >> jail.y;
    m = n;

    for (int i = 0 ; i < n ; i++) 
    {
        cin >> data[i].x >> data[i].y;
        data[i].i = i;
        p.push_back(data[i]);
    }

    while (p.size() > 2)
    {
        m = p.size();
        sort(p.begin(), p.end(), lowest);
        for (int i = 0 ; i < m ; i++)
        {
            p[i].p = p[i].x - p[0].x;
            p[i].q = p[i].y - p[0].y;
        }
        sort(p.begin(), p.end(), cmp);
        
        stack < PO > s;
        s.push(p[0]);
        s.push(p[1]);

        for (int i = 2 ; i < m ; i++)
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

        PO fir = p[0], sec;

        while(!s.empty())
        {
            sec = s.top();
            chk[sec.i] = true;
            s.pop(); 
            if (cp(fir, sec, jail) >= 0)
            {
                over = true;
                break;
            }
            fir = sec;
        }

        if (over) break;
        
        cnt++;
        p.clear();
        for (int i = 0 ; i < n ; i++) if (!chk[data[i].i]) p.push_back(data[i]); 
    }

    cout << cnt;
}