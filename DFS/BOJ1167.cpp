// 2020.06.30

#include <iostream>
#include <vector>
using namespace std;

#define ss second
#define ff first

vector < vector < pair < int, int > > > v(100001);
bool vis[100001];
int da = 0, n;

void dfs(int a) {
    vis[a] = 1;
    int len = v[a].size();
    for (int i = 0 ; i < len ; i++) {
        while (vis[v[a][i].ff]) {
            v[a][i] = v[a][--len];
            v[a].pop_back();
            if (i == len) return;
        }
        dfs(v[a][i].ff);
    }
}

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
    cin >> n;
    for (int i = 0, x ; i < n ; i++) {
        cin >> x;
        for (int y, c ; ; ) {
            cin >> y;
            if (y == -1) break;
            cin >> c;
            v[x].push_back({y,c});
        }
    }
     
    dfs(1);    
    int rst = sdfs(1);
    cout << (rst > da ? rst : da);
}