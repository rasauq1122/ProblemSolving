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

ll a[10], b[10][10], k = 1, ans[10], mem[10];
str s;

int main() {
    IOSFAST();
    cin >> s;

    rep(i, 1, 10) a[i] = a[i-1]*10 + k, k *= 10;
    
    k = 1;
    rep(i, 1, 10) {
        rep(j, 0, 10) {
            if (j) b[i][j] = a[i-1]*9 + k;
            else b[i][j] = a[i-1]*9;
        }
        k *= 10;
    }

    rep(i, 0, s.size()) rep(j, 0, 10) ans[j] += b[i][j];

    k = 1;
    rep(i, 0, s.size()-1) k *= 10;

    int p = s[0]-'0', q = 0;
    rep(i, 0, 10) ans[i] += (p-1)*(a[s.size()-1]);
    rep(i, 1, p) ans[i] += k;
    mem[p]++;
    
    while (k /= 10) {
        int p = s[++q]-'0';
        rep(i, 0, 10) ans[i] += mem[i]*p*k;
        rep(i, 0, 10) ans[i] += p*(a[s.size()-1-q]);
        rep(i, 0, p) ans[i] += k;
        mem[p]++;
    }
    
    rep(i, 0, s.size()) ans[s[i]-'0']++;
    rep(i, 0, 10) cout << ans[i] << blk;
}   