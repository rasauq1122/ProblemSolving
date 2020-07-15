// 2020.07.15

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
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
#define endl '\n'
#define blk ' '
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

ll a, b, sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    
    for (ll i = 0, na, nb ; (1LL<<i) <= b ; i++) {
        na = (BIT(a,i) ? ((a>>i)<<i) : (((a>>i)|1)<<i));
        nb = (BIT(b,i) ? b|((1LL<<i+1)-1) : ((b>>i)<<i)-1);
        sum += (nb-(1LL<<i)-na+1)/2 + (1LL<<i) - max(0LL,a-na) - max(0LL,nb-b);
    }

    cout << sum;
}