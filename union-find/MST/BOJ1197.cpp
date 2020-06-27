// 2020.05.01

#include <iostream>
#include <queue>
using namespace std;

#define priq priority_queue
#define edge pair < int , pair < int, int > >
#define ff first
#define ss second
#define cost ff
#define u ss.ff
#define v ss.ss

vector <int> root(10001);

int find(int n) {
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

void init(int n) {
    for (int i = 1 ; i <= n ; i++) root[i] = i;
}

void merge(int a, int b) { 
    root[find(b)] = find(a);
}

bool connect(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priq <edge, vector <edge>, greater <edge> > pq;
    int n, m, sum = 0;
    cin >> n >> m;

    init(n);

    for (int i = 0, x, y, c ; i < m ; i++) {
        cin >> x >> y >> c;
        pq.push({c,{x,y}});      
    }

    while (!pq.empty()) {
        int co = pq.top().cost, a = pq.top().u, b = pq.top().v;
        pq.pop();
        if (connect(a,b)) continue;
        sum += co;
        merge(a,b);
    }

    cout << sum;
} 