// 2020.05.24

#include <iostream>
using namespace std;

int spa[200001][19];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> spa[i][0];
    for (int i = 1 ; i < 19 ; i++) for (int j = 1 ; j <= n ; j++) spa[j][i] = spa[spa[j][i-1]][i-1];

    cin >> m;
    for (int i = 0, a, b ; i < m ; i++) {
        cin >> a >> b; 
        for (int j = 0 ; j < 19 ; j++) if (a & (1<<j)) b = spa[b][j];
        cout << b << '\n';  
    }
}