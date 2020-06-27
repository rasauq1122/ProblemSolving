// 2019.12.23

#include <algorithm>
#include <iostream>
using namespace std;

long long cnt[1000001], a[100000], sum, sq = 1000, ans[100000];

struct Query
{
    long long idx, s, f;
} q[1000000];

void add(long long i)
{
    sum += i*(cnt[i]*2 + 1);
    cnt[i]++;
}

void rem(long long i)
{
    sum -= i*(cnt[i]*2 - 1);
    cnt[i]--;
}

bool mo(Query a, Query b)
{
    if (a.s/sq == b.s/sq) return a.f < b.f;
    return a.s/sq < b.s/sq;
}

int main()
{
    long long n, t;
    scanf("%lld %lld",&n,&t);
    for (long long i = 0 ; i < n ; i++) scanf("%lld",&a[i]);
    for (long long i = 0, x, y ; i < t ; i++)
    {
        scanf("%lld %lld",&x,&y);
        q[i].s = --x;
        q[i].f = --y;
        q[i].idx = i;
    }

    sort(q,q+t,mo);
    long long x = q[0].s, y = q[0].f;
    
    for (long long i = x ; i <= y ; i++) add(a[i]);
    ans[q[0].idx] = sum;

    for (long long i = 1, xx, yy ; i < t ; i++)
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
        ans[q[i].idx] = sum;
    }

    for (long long i = 0 ; i < t ; i++) printf("%lld\n",ans[i]);
}