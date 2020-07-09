// 2020.04.10

#include <iostream>
#include <vector>
using namespace std;

bool garo[15];

int cnt, n;

bool isOnLine(pair <int,int> p1, pair <int,int> p2)
{
    return abs(p1.first - p2.first) == abs(p1.second - p2.second);
}

void btk(vector <int> v)
{
    int len = v.size();
    for (int i = 0 ; i < len-1 ; i++) if (isOnLine({i,v[i]},{len-1,v[len-1]})) return;
    
    if (len == n) {
        cnt++;
        return;
    }

    for (int i = 0 ; i < n ; i++) if (!garo[i]) {
        garo[i] = true;
        v.push_back(i);
        btk(v);
        garo[i] = false;
        v.pop_back();
    }
}

int main() {
    cin >> n;
    vector <int> v;
    btk(v);
    cout << cnt;
}