// 2019.11.05

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, sum = 0;
    priority_queue <int> pq;
    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++)
    {
        int x;
        scanf("%d",&x);
        pq.push(x*(-1));
    }

    while(pq.size() > 1)
    {
        int now = pq.top();
        pq.pop();
        now += pq.top();
        pq.pop();
        pq.push(now);
        sum += now;
    }

    printf("%d",sum*(-1));
}