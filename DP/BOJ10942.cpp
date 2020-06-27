// 2019.11.19

#include <iostream>
#include <memory.h>
using namespace std;

int n, a[2000], dp[2000][2000], t;

int loop(int s, int e)
{
    if (s >= e) return dp[s][e] = 1;
    if (dp[s][e] != -1) return dp[s][e];
    if (a[s] != a[e]) return dp[s][e] = 0;
    return dp[s][e] = loop(s+1,e-1); 
}

int main()
{
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));

    scanf("%d",&t);
    for (int i = 0, s, e ; i < t ; i++)
    {
        scanf("%d %d",&s,&e);
        printf("%d\n",loop(s-1,e-1));
    }
}