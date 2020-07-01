// 2020.07.01

#include <iostream>
using namespace std;

bool tri[3*(1<<10)][6*(1<<10)];
int n, k;

void loop(int x, int y, int k) {
    if (k == 0) {
        for (int i = 0 ; i < 5 ; i++) tri[x][y+i] = 1;
        tri[x-1][y+1] = 1;
        tri[x-1][y+3] = 1;
        tri[x-2][y+2] = 1;
        return;
    }
    loop(x, y, k-1);
    loop(x, y+6*(1<<k-1), k-1);
    loop(x-3*(1<<k-1), y+3*(1<<k-1), k-1);
}

int main() {
    cin >> n;
    int a = n/3;
    while (a >>= 1) k++;
    loop(n-1, 0, k);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 2*n ; j++) {
            if (tri[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}