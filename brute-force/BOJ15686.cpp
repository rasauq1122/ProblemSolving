// 2020.06.29

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second
#define BIG ((1LL<<31) - 1)

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < pii > h, c;
    vector < vector < int > > d;
    for (int i = 0 ; i < n ; i++) for (int j = 0, a ; j < n ; j++) {
        cin >> a;
        if (a == 1) {
            h.push_back({i,j});
            d.push_back(vector <int>());
        } else if (a == 2) c.push_back({i,j});
    }

    int len = d.size(), len2 = c.size();
    for (int i = 0 ; i < len ; i++) for (int j = 0 ; j < len2 ; j++) d[i].push_back(dis(h[i].ff, h[i].ss, c[j].ff, c[j].ss));

    int da = BIG;
    for (int i = 0 ; i < (1<<len2); i++) {
        int cnt = 0;
        for (int j = 0 ; j < len2 ; j++) if (i & (1<<j)) cnt++;
        if (cnt != m) continue;

        int sum = 0;
        for (int j = 0 ; j < len ; j++) {
            int now = BIG;
            for (int k = 0 ; k < len2 ; k++) if (i & (1<<k)) now = min(now, d[j][k]);
            sum += now;
        }

        da = min(da, sum);
    } 
    cout << da;
}