// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define endl '\n'
#define blk ' '
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define int long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>
#define IMAX ((1LL<<31)-1)
#define LMAX (((1LL<<62)-1)*2+1)
#define MS(T) memset(T, -1, sizeof(T))
#define ZS(T) memset(T, 0, sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW1(A,IX,EX) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define mod(A,B) ((A+B)%B)
using namespace std;

int n, m, k, arr[400000], h = 1;

int upd(int x) {
    arr[x] = arr[x*2]|arr[x*2+1];
    if (x > 1) upd(x/2);
}

int get(int ix, int iy, int nx, int ny, int idx) {
    if (iy < nx || ny < ix) return 0;
    if (ix <= nx && ny <= iy) return arr[idx];
    return get(ix, iy, nx, (nx+ny)/2, 2*idx)|get(ix, iy, (nx+ny)/2+1, ny, 2*idx+1); 
}

signed main() {
    IOSFAST();
    str s;
    cin >> s;
    n = s.size();
    while (h < n) h <<= 1;
    rep(i, 0, n) arr[i+h] = 1<<s[i]-'a';
    per(i, 1, h) arr[i] = arr[2*i]|arr[2*i+1];
    TC() {
        int a, b;
        cin >> a >> b;
        if (a == 2) {
            int c, d, cnt = 0;
            cin >> c;
            d = get(b, c, 1, h, 1);
            rep(i, 0, 'z'-'a'+1) cnt += BIT(d,i);
            cout << cnt << endl;
        } else {
            char c;
            cin >> c;
            arr[b-1+h] = 1<<c-'a';
            upd((b-1+h)/2);
        }
    }
}   