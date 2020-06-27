// 2020.05.24

#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

vector < vector < pii > > tree(40001);
int dis[40001][16], par[40001][16], dep[40001];

void dfs(int index) {
    int len = tree[index].size();
    for (int i = 0 ; i < len ; i++) {
        pii next = tree[index][i];
        if (!par[next.ff][0]) {
            par[next.ff][0] = index;
            dep[next.ff] = dep[index]+1;
            dis[next.ff][0] = next.ss;
            dfs(next.ff);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int i = 0, a, b, c ; i < n-1 ; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    par[1][0] = 1;
    dfs(1);

    for (int i = 1 ; i < 16 ; i++) for (int j = 1 ; j <= n ; j++) {
        par[j][i] = par[par[j][i-1]][i-1];
        dis[j][i] = dis[j][i-1] + dis[par[j][i-1]][i-1];
    }

    cin >> m;
    for (int i = 0, a, b, gap, gap_dis, lca_dis ; i < m ; i++) {
        cin >> a >> b;
        gap_dis = 0;
        lca_dis = 0;
        if (dep[a] < dep[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        gap = dep[a] - dep[b];
        for (int i = 0 ; i < 16 ; i++) if ((1<<i) & gap) {
            gap_dis += dis[a][i];
            a = par[a][i];
        }

        if (a == b) {
            cout << gap_dis << '\n';
            continue;
        }

        for (int i = 15 ; i >= 0 ; i--) {
            if (par[a][i] == par[b][i]) continue;
            lca_dis += dis[a][i] + dis[b][i];
            a = par[a][i];
            b = par[b][i];
        }

        cout << gap_dis + lca_dis + dis[a][0] + dis[b][0] << '\n';
    }
} 