// 2020.07.16

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
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
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define endl '\n'
#define blk ' '
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

int dp[2500][2500], dp2[2500][2500];
str s;

int foo(int st, int en) {
    if (st >= en) return dp[st][en] = true;
    if (dp[st][en] != -1) return dp[st][en];
    return dp[st][en] = (s[st] == s[en] && foo(st+1, en-1));
}

int bar(int st, int en) {
    if (foo(st,en)) return 1;
    if (dp2[st][en] != -1) return dp2[st][en];
    
    int so = IMAX;
    for (int i = st ; i < en ; i++) if (foo(i+1,en)) so = min(so, bar(st,i)+1);
    return dp2[st][en] = so;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    MS(dp), MS(dp2);
    cout << bar(0,s.size()-1);
}