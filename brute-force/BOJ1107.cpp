// 2019.08.27

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool error[10];

bool check(int n)
{
    string s = to_string(n);
    int len = s.size();
    for (int i = 0 ; i < len ; i++) if (error[s[i]-'0']) return false;
    return true;
}

int int_len(int n)
{
    return to_string(n).size();
}

int main()
{
    int n, k, only_click, decrease = 0, increase = 0;
    bool d_okay = true;
    cin >> n >> k;
    for (int i = 0, x ; i < k ; cin >> x, error[x] = true, i++);
    
    only_click = abs(100-n);

    if (k == 10) increase = 500000;
    else for (int x = n ; !check(x) && x <= 999999 ; x++) increase++;
    increase += int_len(n+increase);

    for (int x = n ; !check(x) && x >= 0 ; --x < 0 ? d_okay = false : d_okay = true) decrease++;
    decrease += int_len(n-decrease);
    if (!d_okay) decrease = 500000;

    cout << min({only_click, increase, decrease});
}