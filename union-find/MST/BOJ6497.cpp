// 2020.05.03

#include <iostream>
#include <queue>
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

#define pii pair<int,int>
#define edge pair<int,pii>
#define ff first
#define ss second

int main() {
    while (true) {
        int n, e, sum = 0;
        cin >> n >> e;
        uf tree(n);
        if (n == 0 && e == 0) break;
        priority_queue <edge, vector<edge>, greater<edge> > pq;
        for (int i = 1, x, y, z ; i <= e ; i++) {
            cin >> x >> y >> z;
            pq.push({z,{x,y}});
        } 

        while (!pq.empty()) {
            int cost = pq.top().ff, u = pq.top().ss.ff, v = pq.top().ss.ss;
            pq.pop();
            
            if (tree.connect(u,v)) {
                sum += cost;
                continue;
            }

            tree.merge(u,v);
        }

        cout << sum << '\n';
    }
}