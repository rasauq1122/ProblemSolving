// 2020.05.01

#include <iostream>
#include <vector>
using namespace std;

vector <int> root(1000001);

int find(int n) {
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
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
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1 ; i <= n ; i++) root[i] = i;

    for (int i = 0, x, a, b ; i < m ; i++) {
        cin >> x >> a >> b;
        if (x) {
            if (connect(a,b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else merge(a, b);
    }
}