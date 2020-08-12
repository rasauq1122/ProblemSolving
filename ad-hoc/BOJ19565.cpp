#include <iostream>
using namespace std;

int a[1001], b[1000001], n;

int main() {
    cin >> n;
    cout << n*n + 1 << '\n';
    for (int i = 1 ; i <= n*n ; i++) b[i] = (b[i-1]+a[b[i-1]]++)%n;
    for (int i = 0 ; i <= n*n ; i++) cout << b[i]+1 << ' '; 
}