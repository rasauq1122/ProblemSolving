// 2020.05.23

#include <iostream>
using namespace std;

#define ll long long

ll tree[1<<21], h = 1;

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

ll get(int index, int nl, int nr, int gl, int gr) {
    if (gr < nl || nr < gl) return 0;
    if (gl <= nl && nr <= gr) return tree[index];

    int mid = (nl+nr)/2;
    return get(index*2, nl, mid, gl, gr) + get(index*2+1, mid+1, nr, gl, gr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    while (h < n) h <<= 1;

    for (int i = 0, a, b, c ; i < q ; i++) {
        cin >> a >> b >> c;

        if (a == 1) upd(c, 1, 1, h, b);
        else cout << get(1, 1, h, b, c) << '\n';
    }
}