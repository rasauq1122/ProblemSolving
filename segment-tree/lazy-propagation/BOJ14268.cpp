// 2020.05.24

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[1<<21], lazy[1<<21], h = 1, seg[1000001][2], cnt = 1;
vector < vector < int > > company(1000001, vector <int>(0));

int dfs(int index) {
    seg[index][0] = cnt++;
    int rtn = seg[index][0], len = company[index].size();
    for (int i = 0 ; i < len ; i++) rtn = max(rtn, dfs(company[index][i]));
    seg[index][1] = rtn;
    return rtn;
}

void pro(int index) {
    if (!lazy[index]) return;
    if (index < h) {
        lazy[index*2] += lazy[index];
        lazy[index*2+1] += lazy[index];
    }
    tree[index] += lazy[index];
    lazy[index] = 0;
}

void upd(int val, int index, int nl, int nr, int gl, int gr) {
    pro(index);
    if (gr < nl || nr < gl) return;
    if (gl <= nl && nr <= gr) {
        lazy[index] += val;
        pro(index);
        return;
    }

    int mid = (nl+nr)/2;
    upd(val, index*2, nl, mid, gl, gr);
    upd(val, index*2+1, mid+1, nr, gl, gr);
}

int get(int index, int nl, int nr, int g) {
    pro(index);
    if (g < nl || nr < g) return 0;
    if (g <= nl && nr <= g) return tree[index];

    int mid = (nl+nr)/2;
    return get(index*2, nl, mid, g) + get(index*2+1, mid+1, nr, g);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, a;  
    cin >> n >> q;
    while (h < n) h <<= 1;
    
    cin >> a;
    for (int i = 2, a ; i <= n ; i++) {
        cin >> a;
        company[a].push_back(i);
    }

    dfs(1);
    for (int i = 0, a, b, c ; i < q ; i++) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c;
            upd(c, 1, 1, h, seg[b][0], seg[b][1]);
        }
        else cout << get(1, 1, h, seg[b][0]) << '\n';
    }
}       