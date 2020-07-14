// 2020.07.14

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
#define BIT(A,B) (!!((A)&(1<<(B))))
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
using namespace std;

struct uf {
    vector <int> v;

    uf(int n) : v(n+1) {
        for (int i = 1 ; i <= n ; i++) v[i] = i;
    }

    int find(int i) {
        if (v[i] == i) return i;
        return v[i] = find(v[i]);
    } 

    void merge(int a, int b) {
        v[find(a)] = find(b);
    }

    bool connect(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    uf tree(n+1);
    GPQ(piii) pq;
    for (int i = 1, x, y, z ; i <= m ; i++) {
        cin >> x >> y >> z;
        pq.push({z,{x,y}});
    } 

    while (!pq.empty()) {
        int cost = pq.top().ff, u = pq.top().ss.ff, v = pq.top().ss.ss;
        pq.pop();
        
        if (tree.connect(u,v)) continue;

        tree.merge(u,v);
        sum += cost;
    }

    cout << sum + (n-1)*(n-2)/2*k;
}