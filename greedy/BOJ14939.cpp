// 2020.07.26

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
#define ll long long
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
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define mod(A,B) ((A+B)%B)
using namespace std;

bool arr[12][12];
int dx[5] = {0,1,1,1,2}, dy[5] = {0,-1,0,1,0}, so = IMAX;
str s[10];

int main() {
    rep(i, 0, 10) cin >> s[i];
    rep(i, 0, 10) rep(j, 0, 10) arr[i+1][j+1] = (s[i][j] == 'O');

    rep(k, 0, 1<<10) {
        bool tst[12][12] = {}, okay = true;
        int cnt = 0;
        rep(i, 0, 10) tst[0][i+1] = BIT(k,i);
        rep(i, 0, 10) rep(j, 0, 10) tst[i+1][j+1] = arr[i+1][j+1];

        rep(i, 0, 10) rep(j, 1, 11) if (tst[i][j]) {
            cnt++;
            rep(p, 0, 5) tst[i+dx[p]][j+dy[p]] = !tst[i+dx[p]][j+dy[p]];
        }
        rep(i, 1, 11) rep(j, 1, 11) okay &= !tst[i][j];
        if (okay) so = min(so, cnt);
    }   
    cout << (so == IMAX ? -1 : so);
}
   