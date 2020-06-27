// 2020.05.03

#include <iostream>
#include <vector>
using namespace std;

#define pii pair <int, int>
#define ff first
#define ss second

struct uf {
    pii v[1000][1000];

    void init(int n, int m) {
        for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < m ; j++) v[i][j] = {i,j};
    }

    pii find(pii p) {
        int i = p.ff, j = p.ss;
        if (v[i][j] == make_pair(i,j)) return {i,j};
        return v[i][j] = find(v[i][j]);
    } 

    void merge(pii a, pii b) {
        pii p = find(a);
        v[a.ff][a.ss] = find(b);
    }

    bool connect(pii a, pii b) {
        return find(a) == find(b);
    }
};

pii next(char c, pii a) {
    int x = a.ff, y = a.ss;
    if (c == 'D') return {x+1,y};
    if (c == 'L') return {x,y-1};
    if (c == 'R') return {x,y+1};
    return {x-1,y};
}

bool root[1000][1000];

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    uf tree;
    tree.init(n,m);

    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++) {
            if (tree.connect({i,j}, next(s[j], {i,j}))) continue;
            tree.merge({i,j}, next(s[j], {i,j}));
        }
    }

    for (int i = 0, x, y ; i < n ; i++) for (int j = 0 ; j < m ; j++) {
        pii p = tree.find({i,j});
        x = p.ff, y = p.ss;
        if (root[x][y]) continue;
        root[x][y] = true;
        cnt++;
    }
    
    cout << cnt;
}