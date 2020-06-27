// 2020.05.09

#include <iostream>
using namespace std;

struct matrix{
    int mat[5][5] = {}, size;

    matrix() {}
    matrix(int si) {
        for (int i = 0 ; i < si ; i++) for (int j = 0 ; j < si ; j++) cin >> mat[i][j];
        size = si;
    }

    matrix mult(matrix other) {
        matrix now;
        now.size = size;
        for (int i = 0 ; i < size ; i++) for (int j = 0 ; j < size ; j++) for (int k = 0 ; k < size ; k++) {
            now.mat[i][j] += mat[i][k]*other.mat[k][j];
            now.mat[i][j] %= 1000;
        }
        return now;
    }

    matrix mod() {
        matrix now;
        now.size = size;
        for (int i = 0 ; i < size ; i++) for (int j = 0 ; j < size ; j++) now.mat[i][j] = mat[i][j]%1000;
        return now;
    }

    void print() {
        for (int i = 0 ; i < size ; i++) {
            for (int j = 0 ; j < size ; j++) cout << mat[i][j] << ' ';
            cout << '\n';
        }
    }
};

matrix mult(matrix a, long long pow) {
    if (pow == 1) return a.mod();
    
    if (pow%2) return a.mult(mult(a,pow-1));
    matrix now = mult(a,pow/2);
    return now.mult(now);
}

int main() {
    int mat[5][5], n;
    long long b;

    cin >> n >> b;
    matrix a(n);
    mult(a,b).print();
}