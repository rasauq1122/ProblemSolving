// 2020.06.30

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool map[50][50];
int n, m, k, cnt;
ll knw, vis, pty[50];

void dfs(int p) {
    vis |= 1LL<<p;
    for (int i = 0 ; i < n ; i++) if (!((1LL<<i) & vis) && map[p][i]) dfs(i);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0, a ; i < k ; i++) {
        cin >> a;
        knw |= 1LL<<(--a);
    }
    for (int i = 0, a ; i < m ; i++) {
        cin >> a;
        vector <int> v;
        for (int j = 0, b ; j < a ; j++) {
            cin >> b;
            v.push_back(--b);
            pty[i] |= 1LL<<b;
        }
        for (int j = 0 ; j < a ; j++) for (int k = j+1 ; k < a ; k++) {
            map[v[j]][v[k]] = 1;
            map[v[k]][v[j]] = 1;
        }
    }
    for (int i = 0 ; i < n ; i++) if (((1LL<<i) & knw) && !((1LL<<i) & vis)) dfs(i);

    for (int i = 0 ; i < m ; i++) if (!(vis & pty[i])) cnt++;
    cout << cnt << '\n';
}