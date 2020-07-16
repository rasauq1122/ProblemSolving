// 2020.07.16

#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define piii pair<double,pii>
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

int n, root[100];
double arr[100][2], sum;

double dis(int ax, int ay, int bx, int by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int uf(int x) {
    if (x == root[x]) return x;
    return root[x] = uf(root[x]);
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i][0] >> arr[i][1];

    GPQ(piii) pq;
    for (int i = 0 ; i < n ; i++) for (int j = i+1 ; j < n ; j++) pq.push({dis(arr[i][0],arr[i][1],arr[j][0],arr[j][1]),{i,j}});
    for (int i = 0 ; i < n ; i++) root[i] = i;
    while (!pq.empty()) {
        double cost = pq.top().ff;
        int a = pq.top().ss.ff, b = pq.top().ss.ss;
        pq.pop();

        if (uf(a) == uf(b)) continue;

        sum += cost;
        root[uf(a)] = uf(b); 
    }
    printf("%.2f",sum);
}  