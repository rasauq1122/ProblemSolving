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

int n, m, k, ps[5201][5201];
bool arr[5200][5200];
str s[5200];

int c2i(char c) {
    if (c >= 'A') return c-'A'+10;
    else return c-'0';
}

int getPS(int x1, int y1, int x2, int y2) {
    return ps[x1][y1] - ps[x1][y2] - ps[x2][y1] + ps[x2][y2];
}

signed main() {
    IOSFAST();
    cin >> n;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) per(j, 0, n/4) per(k, 4*j, 4*j+4) arr[i][k] = BIT(c2i(s[i][j]),(4*j+3-k));
    rep(i, 0, n) rep(j, 0, n) ps[i+1][j+1] = ps[i+1][j] + arr[i][j];
    rep(j, 0, n) rep(i, 0, n) ps[i+1][j+1] += ps[i][j+1];
    per(k, 2, n+1) if(!(n%k)) {
        bool okay = true;
        rep(i, 1, (n/k)+1) rep(j, 1, (n/k)+1) {
            int sum = getPS(k*i,k*j,k*(i-1),k*(j-1));
            if (sum != 0 && sum != k*k) okay = false;
        }
        if (okay) return cout << k << endl, 0;
    }
    cout << 1;
}   