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

int n, m, k, arr[10000], mc, zc, oc, pc, ms, ps;

signed main() {
    IOSFAST();
    cin >> n;
    rep(i, 0, n) {
        cin >> arr[i];
        if (arr[i] < 0) mc++;
        else if (!arr[i]) zc++;
        else if (arr[i] == 1) oc++; 
        else pc++;
    }
    
    sort(arr, arr+n);
    if (mc) {
        if (mc == 1) ms = (zc ? 0 : arr[0]);
        else {
            for (int i = 0 ; i < mc-mc%2 ; i += 2) ms += arr[i]*arr[i+1];
            if (mc%2 && !zc) ms += arr[mc-1];
        }
    }
    sort(arr, arr+n, greater<int>());
    if (pc) {
        if (pc == 1) ps = arr[0];
        else {
            for (int i = 0 ; i < pc-pc%2 ; i += 2) ps += arr[i]*arr[i+1];
            if (pc%2) ps += arr[pc-1];
        }
    }
    cout << ms+oc+ps;
}   