// 2019.12.23

#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

int cnt[2000001], a[100000], ans[100000], apr[100000], aprS[1415], sq;

struct Query
{
    int idx, s, f;
} q[1000000];

void add(int i)
{   
    apr[cnt[i]]--;
    aprS[cnt[i]/sq]--;
    cnt[i]++;
    apr[cnt[i]]++;
    aprS[cnt[i]/sq]++;
}

void rem(int i)
{
    apr[cnt[i]]--;
    aprS[cnt[i]/sq]--;
    cnt[i]--;
    apr[cnt[i]]++;
    aprS[cnt[i]/sq]++;
}

bool mo(Query a, Query b)
{
    if (a.s/sq == b.s/sq) return a.f < b.f;
    return a.s/sq < b.s/sq;
}

int main()
{   
    while (1)
    { 
        int n, t;
        scanf("%d",&n);
        if (!n) break;
        scanf("%d",&t);
        memset(cnt, 0, sizeof(cnt));
        memset(apr, 0, sizeof(apr));
        memset(aprS, 0, sizeof(aprS));
        sq = (int) sqrt( (double) n );
        for (int i = 0 ; i < n ; i++) 
        {
            scanf("%d",&a[i]);
            a[i] += 1000000;
        }
        apr[0] = n;
        aprS[0] = n;
        for (int i = 0, x, y ; i < t ; i++)
        {
            scanf("%d %d",&x,&y);
            q[i].s = --x;
            q[i].f = --y;
            q[i].idx = i;
        }
    
        sort(q,q+t,mo);
        int x = q[0].s, y = q[0].f;
        
        for (int i = x ; i <= y ; i++) add(a[i]);

        for (int i = sq ; i >= 0 ; i--)
        {
            if (!aprS[i]) continue;
            for (int j = min(n, sq*(i+1)) ; j >= 0 ; j--)
            {
                if (apr[j])
                {
                    ans[q[0].idx] = j;
                    break;
                }
            }
            break;
        }

        for (int i = 1, xx, yy ; i < t ; i++)
        {
            xx = q[i].s;
            yy = q[i].f;
            while (xx < x)
            {   
                x--;
                add(a[x]);
            }
            while (yy > y)
            {
                y++;
                add(a[y]);
            }
            while (xx > x)
            {
                rem(a[x]);
                x++;
            }
            while (yy < y)
            {
                rem(a[y]);
                y--;
            }
            
            for (int j = sq ; j >= 0 ; j--)
            {
                if (!aprS[j]) continue;
                for (int k = min(n, sq*(j+1)) ; k >= 0 ; k--)
                {
                    if (apr[k])
                    {
                        ans[q[i].idx] = k;
                        break;
                    }
                }
                break;
            }
        }

        for (int i = 0 ; i < t ; i++) printf("%d\n",ans[i]);
    }
}