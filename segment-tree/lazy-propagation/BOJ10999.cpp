// 2020.05.23

#include <iostream>
using namespace std;

#define ll long long
ll tree[1+(1<<21)], lazy[1+(1<<21)];
int h = 1;

void pro(int index, int nowL, int nowR) {                 // nowL과 nowR의 값은 index에 대해 일대일 대응 + 자기 자신의 값만 변함
    if (!lazy[index]) return;                             // lazy가 없으면 갱신할 필요가 없다
    if (index < h) {                                      // lazy를 child node에게 전달
        lazy[index*2] += lazy[index];                     
        lazy[index*2+1] += lazy[index];                 
    }
    tree[index] += lazy[index]*(nowR - nowL + 1);         // lazy를 '자기자신에게만' 반영하고 초기화 
    lazy[index] = 0;
}

void upd(ll val, int index, int nowL, int nowR, int goL, int goR) {
    pro(index, nowL, nowR);                               // 방문했으니 갱신해볼까?
    if (goR < nowL || nowR < goL) return;                 // 범위 초과 했으므로 무시
    if (goL <= nowL && nowR <= goR) {                     // 범위 안 -> lazy만 갱신하고 종료
        lazy[index] += val;
        pro(index, nowL, nowR);
        return;
    }

    upd(val, index*2, nowL, (nowL+nowR)/2, goL, goR);     // 이도저도 아니면 반으로 갈라짐
    upd(val, index*2+1, (nowL+nowR)/2+1, nowR, goL, goR);
    tree[index] = tree[index*2] + tree[index*2+1];        // 자기 자식들에 대해서 모두 upd가 완료된 후 합침
}

ll get(int index, int nowL, int nowR, int goL, int goR) {
    pro(index, nowL, nowR);                               // 방문했으니 갱신해볼까?
    if (goR < nowL || nowR < goL) return 0;  
    if (goL <= nowL && nowR <= goR) return tree[index];
    return get(index*2, nowL, (nowL+nowR)/2, goL, goR) + get(index*2+1, (nowL+nowR)/2+1, nowR, goL, goR);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    while (h < n) h <<= 1;

    for (ll i = 0 ; i < n ; i++) cin >> tree[h + i];
    for (ll i = h-1 ; i >= 1 ; i--) tree[i] = tree[i*2] + tree[i*2+1];

    for (ll i = 0, a, b, c, d ; i < m + k ; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            upd(d, 1, 1, h, b, c);
        }
        else cout << get(1, 1, h, b, c) << '\n'; 
    }
}