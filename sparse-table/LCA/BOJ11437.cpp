// 2020.05.24

#include <iostream>
#include <vector>
using namespace std;

vector < vector < int > > tree(50001);
int par[50001][16], dep[50001];

void dfs(int index) {
    int len = tree[index].size();
    for (int i = 0 ; i < len ; i++) if (!par[tree[index][i]][0]) {
        dep[tree[index][i]] = dep[index]+1;
        par[tree[index][i]][0] = index; 
        dfs(tree[index][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0, a, b ; i < n-1 ; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        
    }

    par[1][0] = 1;
    dfs(1);
    
    for (int j = 1 ; j < 16 ; j++) for (int i = 1 ; i <= n ; i++) par[i][j] = par[par[i][j-1]][j-1];
    
    cin >> m;
    for (int i = 0, a, b, gap ; i < m ; i++) {
        cin >> a >> b;
        if (dep[a] > dep[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        gap = dep[b] - dep[a];
        for (int i = 0 ; i < 16 ; i++) if (gap & (1<<i)) b = par[b][i];

        if (a == b) {
            cout << a << '\n';
            continue;
        }

        for (int i = 15 ; i >= 0 ; i--) {
            if (par[a][i] == par[b][i]) continue;
            a = par[a][i];
            b = par[b][i];
        }

        cout << par[a][0] << '\n';
    }
}