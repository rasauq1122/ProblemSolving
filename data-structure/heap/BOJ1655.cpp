// 2019.11.05

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue <int, vector <int>, greater<int>> ri;
    priority_queue <int, vector <int>, less<int>> le;

    int n;
    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++)
    {
        int x;
        scanf("%d",&x);
        if (i > 1)
        {
            if (x > ri.top()) ri.push(x);
            else le.push(x);

            if (le.size() > ri.size() + 1)
            {
                ri.push(le.top());
                le.pop();
            }
            else if (le.size() + 1 < ri.size())
            {
                le.push(ri.top());
                ri.pop();
            }
        }
        else
        {
            le.push(x);
            if (i)
            {
                ri.push(le.top());
                le.pop();
            }
        }

        if (le.size() < ri.size()) printf("%d\n",ri.top());
        else printf("%d\n",le.top());
    }
}