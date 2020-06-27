// 2019.12.26

#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef struct point{
    int x, y, p, q, i;
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
    
    PO data[1000];
    vector < PO > p;
    int chk[1000], n, m, cnt = 0;
    cin >> n;
    m = n;

    for (int i = 0 ; i < n ; i++) 
    {
        cin >> data[i].x >> data[i].y;
        data[i].i = i;
        p.push_back(data[i]);
    }

    while (p.size() > 2)
    {
        cnt++;
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

        vector < PO > p2;
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

        if (s.size() == 2) break;

        while(!s.empty())
        {
            chk[s.top().i] = cnt;
            s.pop(); 
        }

        p.clear();
        for (int i = 0 ; i < n ; i++) if (!chk[data[i].i]) p.push_back(data[i]); 
    }

    for (int i = 0 ; i < n ; i++) cout << chk[i] << ' '; 
}