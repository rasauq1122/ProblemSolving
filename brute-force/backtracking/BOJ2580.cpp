// 2020.07.14

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define ll long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define IMAX ((1LL<<31)-1)
#define MS(T) memset(T, -1, sizeof(T))
#define BIT(A,B) (!!((A)&(1<<(B))))
using namespace std;

bool okay = false;
int row[9], col[9], are[9];
str s[9], ans[9];

void btk(int ix, int iy) {
    if (okay) return;
    for (int i = ix ; i < 9 ; i++) for (int j = (i == ix ? iy : 0) ; j < 9 ; j++) if (s[i][j] == '0') {
        int k = row[i]|col[j]|are[3*(i/3)+j/3];
        for (int q = 0 ; q < 9 ; q++) if (!BIT(k,q)) {
            row[i] += 1<<q;
            col[j] += 1<<q;
            are[3*(i/3)+j/3] += 1<<q;
            s[i][j] = '1'+q;
            btk(i, j+1);
            row[i] -= 1<<q;
            col[j] -= 1<<q;
            are[3*(i/3)+j/3] -= 1<<q;
            s[i][j] = '0';
        }
        return;
    }

    if (!okay) {
        for (int i = 0 ; i < 9 ; i++) ans[i] = s[i];
        okay = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0 ; i < 9 ; i++) { 
        int x;
        str p = "";
        for (int j = 0 ; j < 9 ; j++) {
            cin >> x;
            p += x+'0';
        }
        s[i] = p;
    }
    for (int i = 0 ; i < 9 ; i++) for (int j = 0 ; j < 9 ; j++) if (s[i][j]-'0') {
        row[i] += 1<<s[i][j]-'1';
        col[j] += 1<<s[i][j]-'1';
        are[j/3+3*(i/3)] += 1<<s[i][j]-'1';
    }

    btk(0,0);
    for (int i = 0 ; i < 9 ; i++, cout << '\n') for (int j = 0 ; j < 9 ; j++) cout << ans[i][j] << ' ';
}