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
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define rep(A,B,C) for(int A=B;A<C;A++)
#define per(A,B,C) for(int A=C;A>=B;A--) 
#define mod(A,B) ((A+B)%B)
using namespace std;

int n, m, k, arr[4][4000];
ll cnt;

int main() {
    IOSFAST();    
    cin >> n;
    rep(i, 0, n) cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
    V(int) v1, v2;
    rep(i, 0, n) rep(j, 0, n) v1.pb(arr[0][i]+arr[1][j]);
    rep(i, 0, n) rep(j, 0, n) v2.pb(arr[2][i]+arr[3][j]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0, j = v2.size()-1 ; i < v1.size() && j >= 0 ;) {
        if (v1[i] + v2[j] == 0) {
            ll cnt1 = 1, cnt2 = 1;
            while (i+1 < v1.size() && v1[i] == v1[i+1]) cnt1++, i++;
            while (j-1 >= 0 && v2[j-1] == v2[j]) cnt2++, j--;
            cnt += cnt1*cnt2;
        }
        if (i < v1.size() && v1[i] + v2[j] <= 0) i++;
        else j--;
    }

    cout << cnt;
}   