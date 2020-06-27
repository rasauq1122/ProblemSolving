// 2019.11.14

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a, b, t, w[50000], s[50000];
pair <int,int> d[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> t;

    for (int i = 0 ; i < a ; i++) cin >> w[i];
    for (int i = 0 ; i < b ; i++) cin >> s[i];
    for (int i = 0 ; i < t ; i++) cin >> d[i].first >> d[i].second;

    sort(w,w+a);
    sort(s,s+b);
    sort(d,d+t);

    int le = 1, ri = t;

    while (le <= ri)
    {
        int key = (le+ri)/2, n = 0;
        priority_queue <int> pq;

        for (int i = 0 ; i < a ; i++)
        {
            while (n < t && d[n].first < w[i])
            {
                pq.push(d[n].second);
                n++;
            }

            for (int j = 0 ; j < key && !pq.empty() ; j++) pq.pop();
        }

        while (n < t)
        {
            pq.push(d[n].second);
            n++;
        }

        for (int i = b-1 ; i >= 0; i--)
        {
            if (pq.top() >= s[i]) break;
            for (int j = 0 ; j < key && !pq.empty() ; j++) pq.pop();
        }

        if (pq.empty()) ri = key-1;
        else le = key+1;
    }

    cout << (t < le ? -1 : le);
}