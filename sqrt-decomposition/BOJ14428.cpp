// 2019.12.29
// can be solved by segment-tree

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n, m, a[100400], a_sq[400], a_sq2[400], sq;

int ec(int n)
{
    return (n-1)/sq+1;
}

int dc(int n)
{
    return (n-1)*sq+1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    sq = (int) sqrt((double) n);
    int len = ec(n);
    for (int i = 1, j = 1 ; j <= len ; j++) for (int k = 0 ; k < sq ; k++) if (i <= n)
    {
        cin >> a[i];
        if (a_sq[j] == 0 || a[i] < a_sq[j]) 
        {
            a_sq[j] = a[i];
            a_sq2[j] = i; 
        }
        i++;
    } 
    
    cin >> m;
    for (int c, i, j, l = 0 ; l < m ; l++)
    {
        cin >> c >> i >> j;
        if (c == 1)
        {
            int st = ec(i);
            a[i] = j;
            a_sq[st] = 1000000001;
            for (int k = dc(st), len = min(k+sq-1, n) ;  k <= len ; k++) if (a[k] < a_sq[st]) 
            {
                a_sq[st] = a[k];
                a_sq2[st] = k;
            }
        }
        else
        {
            int res = 1000000001, res2 = 0, st = ec(i), en = ec(j);
            if (st == en) for (int k = i ; k <= j ; k++)
            {
                if (res > a[k])
                {
                    res = a[k];
                    res2 = k;
                }
            } 
            else
            {   
                for (int k = i, len = dc(st+1) ; k < len ; k++) if (res > a[k])
                {
                    res = a[k];
                    res2 = k;
                } 
                for (int k = st+1 ; k <= en-1 ; k++) if (res > a_sq[k])
                {
                    res = a_sq[k];
                    res2 = a_sq2[k];
                }
                for (int k = dc(en) , len = j ; k <= len ; k++) if (res > a[k])
                {
                   res = a[k];
                   res2 = k;     
                }  
            }   
            cout << res2 << '\n';
        }
        
    }
}