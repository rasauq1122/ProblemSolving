// 2020.05.24

#include <iostream>
using namespace std;

int tree[1<<20], h=1, lazy[1<<20];

void pro(int index) {
    if (!lazy[index]) return;
    if (index < h) {
        lazy[index*2] ^= lazy[index];
        lazy[index*2+1] ^= lazy[index]; 
    }
    else tree[index] ^= lazy[index];
    lazy[index] = 0;
}

void upd(int val, int index, int nl, int nr, int gl, int gr) {
    pro(index);
    
    if (nr < gl || gr < nl) return;
    if (gl <= nl && nr <= gr) {
        lazy[index] ^= val;
        pro(index);
        return;
    }

    int mid = (nl+nr)/2;
    upd(val, index*2, nl, mid, gl, gr);
    upd(val, index*2+1, mid+1, nr, gl, gr);
    tree[index] = tree[index*2] ^ tree[index*2+1];
}

int get(int index, int nl, int nr, int gl, int gr) {
    pro(index);

    if (nr < gl || gr < nl) return 0;
    if (gl <= nl && nr <= gr) return tree[index];

    int mid = (nl+nr)/2;
    return get(index*2, nl, mid, gl, gr) ^ get(index*2+1, mid+1, nr, gl, gr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    while (h < n) h <<= 1;
    for (int i = 0 ; i < n ; i++) cin >> tree[h+i];
    for (int i = h-1 ; i > 0 ; i--) tree[i] = tree[i*2] ^ tree[i*2+1];
    cin >> m;

    for (int i = 0, a, b, c, d ; i < m ; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            upd(d, 1, 0, h-1, b, c);
        }
        else cout << get(1, 0, h-1, b, c) << '\n';
    }
}