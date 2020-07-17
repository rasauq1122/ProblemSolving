// 2020.07.17

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define blk ' '
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define IMAX ((1LL<<31)-1)
#define LMAX (((1LL<<62)-1)*2+1)
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define rep(A,B,C) for(int A=B;A<C;A++)
#define per(A,B,C) for(int A=C;A>=B;A--) 
using namespace std;

int n, arr[10][10], bs[10][10], dx[4] = {1,1,-1,-1}, dy[4] = {1,-1,1,-1}, da;
void btkX(int,int);

bool safe(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void btkY(int k, int chk) {
    if (k == n) {
        int cnt = 0;
        for (int i = 0 ; i <= 2*n-2; i++) cnt += BIT(chk,i);
        da = max(da, cnt);
        return;
    }
    bool ok = false;
    for (int i = 0, j = k ; safe(i,j) ; i++, j++) if (arr[i][j] && !BIT(chk,i+j)) {
        btkX(k, chk|(1<<i+j));
        ok = true;
    }
    if (!ok) btkX(k, chk);
}

void btkX(int k, int chk) {
    bool ok = false;
    for (int i = k, j = 0 ; safe(i,j) ; i++, j++) if (arr[i][j] && !BIT(chk,i+j)) {
        btkY(k+1, chk|(1<<i+j));
        ok = true;
    }
    if (!ok) btkY(k+1, chk);
}

int main() {
    IOSFAST();    
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> arr[i][j];
    btkX(0, 0);
    cout << da;
}   