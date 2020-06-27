// 2020.05.03

#include <iostream>
#include <vector>
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
    int n, m;
    cin >> n >> m;
    uf tree(n);

    for (int i = 1 ; i <= n ; i++) for (int j = 1 ; j <= n ; j++) {
        bool cn;
        cin >> cn;
        if (!cn) continue;
        if (tree.connect(i,j)) continue;
        tree.merge(i,j);
    } 

    vector <int> v(m);
    for (int i = 0, x ; i < m ; i++) cin >> v[i];

    for (int i = 0 ; i < m-1 ; i++) if (!tree.connect(v[i],v[i+1])) {
        cout << "NO";
        return 0;
    }   

    cout << "YES";
}