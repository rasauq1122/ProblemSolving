// 2019.12.23

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a[100000], b[317], n, m, sq;

#define MAX 1000000001

int les(int a, int b)
{
    return (a<b ? a : b);
}

int main()
{
    scanf("%d %d",&n,&m);
    sq = (int) sqrt((double)n);
    for (int i = 0, j = 0, x ; i < n ; j++)
    {
        int st = i;
        b[j] = MAX;
        for (; i < st + sq ; i++)
        {
            if (i < n) scanf("%d",&x); else x = MAX;
            a[i] = x;
            b[j] = les(a[i],b[j]);
        }
    }

    for (int i = 0, x, y, min ; i < m ; i++)
    {
        min = MAX;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        if (x/sq == y/sq) for (int j = x ; j <= y ; j++) min = les(min,a[j]);
        else
        {
            for (int j = x ; j < (x/sq+1)*sq ; j++) min = les(min,a[j]);
            for (int j = (y/sq)*sq ; j <= y ; j++) min = les(min,a[j]);
            for (int j = x/sq + 1 ; j < y/sq ; j++) min = les(min,b[j]);
        }
        printf("%d\n",min);
    }
}