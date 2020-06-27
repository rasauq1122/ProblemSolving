// 2020.11.05

#include <iostream>
using namespace std;

#define and &&
#define or ||

int main()
{
    int n, m;
    int aa[1000000][2] = {};
    long long k, rst = 0;
    scanf("%d %d %lld",&n,&m,&k);
    for (int i = 0 ; i < n ; i++) scanf("%d",&aa[i][0]);
    for (int i = 0 ; i < m ; i++)
    {
        int x, y;
        cin >> x >> y;
        if ((x == 1 and y == n) or (x == n and y == 1)) aa[n-1][1] = 1;
        else if (x > y) aa[y-1][1] = 1;
        else aa[x-1][1] = 1;
    }
    if (m > 1)
    {
        int cnt = 0, end;
        while (!aa[cnt][1]) cnt++;
        end = cnt;
        cnt++;

        int min = 1000001;
        while (true)
        {
            if (cnt == n) cnt = 0;
            if (aa[cnt][0] < min) min = aa[cnt][0];
            if (aa[cnt][1]) 
            {
                rst += min;
                min = 1000001;
                if (cnt == end) break;
            }
            cnt++;
        }
    }
    else rst = 0;

    // for (int i = 0 ; i < 2*n ; i++)
    // {
    //     if (i%2)
    //     {
    //         if (brd[i]) printf("T ");
    //         else printf("F ");
    //     }
    //     else printf("%d ",brd[i]);
    // }
    // printf("\n");
	// printf("%d",rst);
    if (rst <= k) printf("YES");
    else printf("NO");
}