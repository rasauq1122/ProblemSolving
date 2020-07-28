// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
#include <string>
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
#define POW(A) ((A)*(A))
using namespace std;

int r1, r2, c1, c2, dir, k = 1, x, y, dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}, da;
str arr[50][5];

bool in(int a, int b) {
    return r1 <= a && a <= r2 && c1 <= b && b <= c2;
}

signed main() {
    cin >> r1 >> c1 >> r2 >> c2;
    rep(i, 1, POW(2*5001-1)+1) {
        if (in(x,y)) arr[x-r1][y-c1] = to_string(i), da = max(da,(int)arr[x-r1][y-c1].size());
        if (i == POW(k)) {
            y++, dir = 0, k += 2;
            continue;
        } else if (abs(x)==abs(y)) dir = mod(dir+1,4);
        x += dx[dir], y += dy[dir];
    }
    rep(i, 0, r2-r1+1) {
        rep(j, 0, c2-c1+1) {
            rep(k, 0, da-arr[i][j].size()) cout << blk;
            cout << arr[i][j] << blk;
        }
        cout << endl;
    }
}       