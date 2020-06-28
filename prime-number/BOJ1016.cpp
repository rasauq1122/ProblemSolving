// 2020.06.28

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long da, so;
    cin >> so >> da;
    
    bool np[1000000] = {1,1,0};
    int sq[1000001] = {};
    vector <long long> p;
    for (int i = 2 ; i < 1000000 ; i++) if (!np[i]) {
        long long s = 1LL*i*i;
        if (i < 1000) p.push_back(i*1LL);
        else if (so%s == 0) sq[0] = 1;
        else if ((so/s+1)*s <= da) sq[(so/s+1)*s-so] = 1;
        for (int j = 2*i ; j < 1000000 ; j += i) np[j] = 1;
    }

    int len = p.size();
    for (int i = 0 ; i < len ; i++) {
        long long s = p[i]*p[i];
        int j_s = s*(so/s);
        if (so%s) j_s += s;
        j_s -= so;
        for (int j = j_s ; j < da-so+1 ; j += s) sq[j] = 1;
    }
    
    int cnt = 0;
    for (int i = 0 ; i < da-so+1 ; i++) if (!sq[i]) cnt++;
    cout << cnt;
}