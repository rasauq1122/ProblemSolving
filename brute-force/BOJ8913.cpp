// 2019.11.13

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map <string,int> m;

bool loop(string s)
{
    // printf("== %s\n",s.c_str());
    int len = s.size();
    if (m.count(s)) return m[s];
    if (len == 0) return true;
    if (len == 1) return false;

    int n = 0, k = 0;
    s = s + 'c';
    bool ok = false;
    for (int i = 0; i < len ; i++)
    {
        k++;
        if (s[i] != s[i+1])
        {
            // printf("====1 %s\n",s.substr(0,n).c_str());
            // printf("====2 %s\n",s.substr(n+k,len-n-k).c_str());
            if (k != 1) ok |= loop(s.substr(0,n)+s.substr(n+k,len-n-k));
            k = 0;
            n = i+1;
        }
    }
    m[s.substr(0,len)] = ok;
    return ok;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    for (int i = 0 ; i < t ; i++)
    {
        string s;
        cin >> s;
        cout << loop(s) << '\n';
    }
}