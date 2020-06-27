// 2020.04.30

#include <iostream>
#include <vector>
using namespace std;

#define ss second
#define ff first

vector < vector < pair < int, int > > > v(10001);
int da = 0;

int sdfs(int i) {
    int len = v[i].size();
    if (len == 0) return 0;
    if (len == 1) return v[i][0].ss + sdfs(v[i][0].ff);

    int da1 = 0, da2 = 0;
    for (int ii = 0  ; ii < len ; ii++) {
        int now = v[i][ii].ss + sdfs(v[i][ii].ff);
        if (now > da1) {
            da2 = da1;
            da1 = now;
        }
        else if (now > da2) da2 = now;
    }
    
    if (da1+da2 > da) da = da1+da2;
    return da1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, x, y, c ; i < n-1 ; i++) {
        cin >> x >> y >> c;
        v[x].push_back({y,c});
    }
    
    int rst = sdfs(1);
    cout << (rst > da ? rst : da);
}