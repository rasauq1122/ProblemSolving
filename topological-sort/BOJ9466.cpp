// 2020.07.18

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
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define VV(T,N,M) V(V(T))(N,V(T)(M))
#define ST(V) sort(V.begin(),V.end())
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define per(A,B,C) for(int A=(C);A>=(B);A--)
#define mod(A,B) ((A+B)%B)
using namespace std;

int n, m, k;

int main() {
    IOSFAST();
    TC() {
        int n, cnt = 0;
        
        cin >> n;
        V(int) v(n+1), in(n+1);
        rep(i, 1, n+1) cin >> v[i], in[v[i]]++;
        
        Q(int) q;
        rep(i, 1, n+1) if (!in[i]) q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (!--in[v[x]]) q.push(v[x]);
        } 

        rep(i, 1, n+1) cnt += !in[i];
        cout << cnt << endl; 
    }
}   