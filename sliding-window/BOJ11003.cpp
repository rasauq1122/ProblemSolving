// 2019.11.27

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    deque <int> dq;
    deque < pair < int, int > > dq2;
    cin >> n >> m >> x;
    dq.push_front(x);
    printf("%d ",dq.back());

    for (int i = 1, st = 0; i < n ; i++)
    {
        cin >> x;
        dq.push_front(x);
        
        while (!dq2.empty() && dq2.front().first > x) dq2.pop_front();
        dq2.push_front({x,i});

        if (dq.back() > dq2.back().first || dq.size() > m)
        {
            int ck = dq2.back().second;
            for (int i = 0 ; i < ck - st ; i++) dq.pop_back();
            dq2.pop_back();
            st = ck;
        }
        
        printf("%d ",dq.back());
    }
}