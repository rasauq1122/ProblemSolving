// 

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

int n, k, arr[100001], sum;

int uf(int x) {
    if (x == arr[x]) return x;
    return arr[x] = uf(arr[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) arr[i] = i; 

    GPQ(piii) pq;
    for (int i = 0, x, y, z ; i < k ; i++) {
        cin >> x >> y >> z;
        pq.push({z,{x,y}});
    }

    int x;
    while (!pq.empty()) {
        int cost = pq.top().ff;
        int a = pq.top().ss.ff;
        int b = pq.top().ss.ss;
        pq.pop();
        if (uf(a) == uf(b)) continue;
        arr[uf(a)] = uf(b);
        sum += cost;
        x = cost;
    }
    cout << sum - x;
}