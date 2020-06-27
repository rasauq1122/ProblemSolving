// 2020.05.14
// math (especially number theory)

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define BIG 1000000007
struct matrix {
    int a[2][2] = {{1,0},{0,1}};
    matrix(int a11, int a12, int a21, int a22) {
        a[0][0] = a11;
        a[0][1] = a12;
        a[1][0] = a21;
        a[1][1] = a22;
    }

    matrix mult(matrix other) {
        return matrix(((1LL * a[0][0] * other.a[0][0])%BIG + (1LL * a[0][1] * other.a[1][0])%BIG)%BIG,
                      ((1LL * a[0][0] * other.a[0][1])%BIG + (1LL * a[0][1] * other.a[1][1])%BIG)%BIG,
                      ((1LL * a[1][0] * other.a[0][0])%BIG + (1LL * a[1][1] * other.a[1][0])%BIG)%BIG,
                      ((1LL * a[1][0] * other.a[0][1])%BIG + (1LL * a[1][1] * other.a[1][1])%BIG)%BIG);
    }

    int fib() {
        return (a[0][0] + a[0][1])%BIG;
    }
};

matrix mult(matrix a, ll n) {
    if (n == 1) return a;
    if (n%2) return a.mult(mult(a,n-1));
    matrix now = mult(a,n/2);
    return now.mult(now);
}

int main() {
    ll n;
    cin >> n;
    if (n%2) n++;
    if (n == 2) return cout << 1, 0;
    cout << mult(matrix(1,1,1,0),n-2).fib();
}