// 2020.05.24

#include <iostream>
using namespace std;

#define ll long long

int tree[1<<21], h = 1<<20;

void upd(ll val, int index, int nl, int nr, int g) {
    if (g < nl || nr < g) return;
    if (g <= nl && nr <= g) {
        tree[index] += val;
        return;
    }
    int mid = (nl+nr)/2;
    upd(val, index*2, nl, mid, g);
    upd(val, index*2+1, mid+1, nr, g);
    tree[index] = tree[index*2] + tree[index*2+1];
}

ll get(int index, int rank) {
    if (index >= h) return index - h + 1;
    if (tree[index*2] < rank) return get(index*2+1, rank - tree[index*2]);
    return get(index*2, rank);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;

    for (int i = 0, a, b, c ; i < q ; i++) {
        cin >> a >> b;

        if (a == 2) {
            cin >> c;
            upd(c, 1, 1, h, b);
        }
        else {
            int now = get(1, b);
            cout << now << '\n';        
            upd(-1, 1, 1, h, now);
        }
    }
}