// 2020.05.31

#include <iostream>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second

ll tree[1<<18], h = 1, elem = 0;
pii lazy[1<<18];

pii add(pii a, pii b) {
    return {a.ff+b.ff, a.ss+b.ss};
}

void pro(int index, int nl, int nr) {
    if (lazy[index] == make_pair(0*1LL,0*1LL)) return;
    int len = nr-nl+1;
    pii now = lazy[index];
    if (index < h) {
        pii le = lazy[index*2];
        pii ri = lazy[index*2+1];

        lazy[index*2] = add(le,now);
        lazy[index*2+1] = add(ri,{now.ff+now.ss*(len/2),now.ss});
    }
    tree[index] += len*(len-1)*now.ss/2 + len*now.ff;
    lazy[index] = {0,0};
}

void upd(int index, int val, int nl, int nr, int gl, int gr) {
    pro(index, nl, nr);
    if (gr < nl || nr < gl)  return;
    if (gl <= nl && nr <= gr) {
        lazy[index] = add(lazy[index], {val,1});
        pro(index, nl, nr);
        elem += nr-nl+1;
        return;
    }
    int mid = (nl+nr)/2;
    upd(index*2, val, nl, mid, gl, gr);
    upd(index*2+1, 1+elem, mid+1, nr, gl, gr);
    tree[index] = tree[index*2] + tree[index*2+1];
}

ll get(int index, int nl, int nr, int gl, int gr) {
    pro(index, nl, nr);
    if (gr < nl || nr < gl) return 0;
    if (gl <= nl && nr <= gr) return tree[index];

    int mid = (nl+nr)/2;
    return get(index*2, nl, mid, gl, gr) + get(index*2+1, mid+1, nr, gl, gr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    while (h < n) h <<= 1;
    for (int i = 0 ; i < n ; i++) cin >> tree[i+h];
    for (int i = h-1 ; i >= 1 ; i--) tree[i] = tree[2*i]+tree[2*i+1];
    
    cin >> k;
    for (int i = 0, a, b, c ; i < k ; i++) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c;
            elem = 0;
            upd(1,1,1,h,b,c);
        }
        else cout << get(1,1,h,b,b) << '\n';
    }
}