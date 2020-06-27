// 2019.12.30

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string w, s, new_s = "";
    cin >> w >> s;

    deque <char> le, ri;
    int n, cnt = 0, l = -1, r = s.size(), m = w.size();
    bool ok;

    cin >> n;

    for (char c ; cnt < n ; cnt++)
    {
        cin >> c;
        ok = false;
        
        if (l + 1 < r)
        {
            if (c == 'L')
            {
                while (l+1 < r)
                {
                    le.push_back(s[++l]);
                    if (le.size() < m) ok = false;
                    else
                    {
                        ok = true;
                        for (int i = 0, len = le.size() ; i < m ; i++) if (le[len-m+i] != w[i])
                        {
                            ok = false;
                            break;
                        }  
                    }
                    
                    if (ok) 
                    {
                        for (int i = 0 ; i < m ; i++) le.pop_back();
                        break;
                    }
                }
            }
            else
            {
                while (l+1 < r)
                {
                    ri.push_front(s[--r]);
                    if (ri.size() < m) ok = false;
                    else
                    {
                        ok = true;
                        for (int i = 0 ; i < m ; i++) if (ri[i] != w[i]) 
                        {
                            ok = false; 
                            break;
                        }
                    }

                    if (ok) 
                    {
                        for (int i = 0 ; i < m ; i++) ri.pop_front();
                        break;
                    }
                }
            }
            
        }

        if (l + 1 == r)
        {
            if (ok) cnt++;
            break;
        }
    }
    
    for (; !le.empty() && cnt < n ; cnt++)
    {
        ok = false;
        int cnt2 = 0;
        while (!le.empty() && cnt2++ < m)
        {
            ri.push_front(le.back());
            le.pop_back();
            if (ri.size() < m) ok = false;
            else
            {
                ok = true;
                for (int i = 0 ; i < m ; i++) if (ri[i] != w[i]) 
                {
                    ok = false; 
                    break;
                }
            }
            if (ok)
            {
                for (int i = 0 ; i < m ; i++) ri.pop_front();
                break;
            }
        }
        
        if (!ok) break;
    }

    while(!le.empty())
    {
        new_s += le.front();
        le.pop_front();
    }

    for (int i = l+1 ; i < r ; i++) new_s += s[i];

    while(!ri.empty())
    {
        new_s += ri.front();
        ri.pop_front();
    }

    cout << cnt << '\n';
    cout << new_s + '\n';
    cout << (new_s.find(w) == -1 ? "Perfect!" : "You Lose!");
}