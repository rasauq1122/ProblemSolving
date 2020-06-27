// 2020.03.14

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int m2i(int m)
{
    if (m == 2) return 28;
    else if ((m <= 7) == (m%2)) return 31;
    else return 30;
}

int c2i(int m, int d)
{
    int res = 0;
    for (int i = 1 ; i < m ; i++) res += m2i(i);
    return res + d;
}

int main()
{
    int n, arr[100000][2], len = 0;
    scanf("%d",&n);
    vector < pair <int, int> > v;
    
    for (int i = 0, m_s, d_s, m_e, d_e, s, e ; i < n ; i++)
    {
        scanf("%d %d %d %d",&m_s, &d_s, &m_e, &d_e);
        s = c2i(m_s,d_s);
        e = c2i(m_e,d_e);
        if (s < c2i(3,1)) s = c2i(3,1);
        if (e > c2i(12,1)) e = c2i(12,1);
        if (s < e) v.push_back({s,e});
    }

    if (!v.size())
    {
        printf("0");
        return 0;
    }

    sort(v.begin(),v.end());
    
    arr[0][0] = v[0].first;
    arr[0][1] = v[0].second;

    for (int i = 1 ; i < n ; i++)
    {
        if (v[i] == make_pair(arr[len][0], arr[len][1])) continue;
        
        len++;
        arr[len][0] = v[i].first;
        arr[len][1] = v[i].second;
    }
    len++;
    
    if (arr[0][0] != c2i(3,1))
    {
        printf("0");
        return 0;
    }

    int now = 0, now_end = 0, now_best, cnt = 1;
    for (; arr[now][0] == c2i(3,1) ; now++) now_end = arr[now][1] > now_end ? arr[now][1] : now_end;
    for (now_best = arr[now][1] >= now_end ? arr[now][1] : -1; now_end != c2i(12,1) && now < len ; now++)
    {
        if (arr[now][0] > now_end)
        {
            if (now_best == -1)
            {
                printf("0");
                return 0;
            }
            now_end = now_best;
            now_best = arr[now][1] >= now_end ? arr[now][1] : -1;
            cnt++;
        }
        else now_best = arr[now][1] >= now_end && arr[now][1] > now_best ? arr[now][1] : now_best;
    }

    if (now_end != c2i(12, 1))
    {
        if (now_best == -1)
        {
            printf("0");
            return 0;
        }
        now_end = now_best;
        cnt++;

        if (now_end != c2i(12, 1))
        {
            printf("0");
            return 0;
        }
    }

    printf("%d",cnt);
}