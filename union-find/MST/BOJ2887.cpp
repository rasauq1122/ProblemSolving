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

int n, root[100000];
ll sum; 
pii xyz[3][100000];

int uf(int x) {
    if (x == root[x]) return x;
    return root[x] = uf(root[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0, x, y, z ; i < n ; i++) {
        cin >> x >> y >> z;
        xyz[0][i] = {x,i};
        xyz[1][i] = {y,i};
        xyz[2][i] = {z,i};
    }
    sort(xyz[0], xyz[0]+n), sort(xyz[1], xyz[1]+n), sort(xyz[2], xyz[2]+n);

    GPQ(piii) pq;
    for (int i = 1 ; i < n ; i++) {
        pq.push({abs(xyz[0][i].ff-xyz[0][i-1].ff),{xyz[0][i-1].ss, xyz[0][i].ss}});
        pq.push({abs(xyz[1][i].ff-xyz[1][i-1].ff),{xyz[1][i-1].ss, xyz[1][i].ss}});
        pq.push({abs(xyz[2][i].ff-xyz[2][i-1].ff),{xyz[2][i-1].ss, xyz[2][i].ss}});
    }

    for (int i = 0 ; i < n ; i++) root[i] = i;
    while (!pq.empty()) {
        int c = pq.top().ff, a = pq.top().ss.ff, b = pq.top().ss.ss;
        pq.pop();
        if (uf(a) == uf(b)) continue;
        sum += c;
        root[uf(a)] = uf(b);
    }
    cout << sum;
}