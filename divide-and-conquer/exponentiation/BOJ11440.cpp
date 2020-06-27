// 2020.05.14
// math (especially number theory)

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define BIG 1000000007
#define DIV5 400000003
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

    pii fib() {
        matrix multed = mult(matrix(1,1,1,0));
        return {(a[1][0] + a[1][1]), (multed.a[0][0]+multed.a[0][1])};
    }
};

matrix mult(matrix a, ll n) {
    if (n == 0) return matrix(1,0,0,1);
    if (n%2) return a.mult(mult(a,n-1));
    matrix now = mult(a,n/2);
    return now.mult(now);
}

int main() {
    ll n;
    cin >> n;
    if (n == 0) return cout << 0, 0;
    
    matrix a = matrix(1,1,1,0);
    if (n%2) {
        pii fibs = mult(a,4*(n/2)+3).fib();
        int now = ((((1LL*4*fibs.ff)%BIG-fibs.ss+1)%BIG)*DIV5)%BIG;
        if (now < 0) now += BIG;
        cout << now;
    }
    else {
        pii fibs = mult(a,4*((n-1)/2)+3).fib();
        cout << ((((1LL*fibs.ff)+fibs.ss-1)%BIG)*DIV5)%BIG;
    }
}