// 2020.07.09

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

int n, so = IMAX;
bool arr[15][15];

void btk(int x, int y, V(int) v) {
    
    for (int i = x ; i < 10 ; i++) for (int j = (i == x ? y : 0); j < 10 ; j++) if (arr[i][j]) {
        int k = 0;
        for ( ; k < 5 ; k++) {
            bool okay = true;
            for (int dx = 0 ; dx < k ; dx++) okay &= arr[i+dx][j+k];
            okay &= arr[i+k][j+k];
            for (int dy = 0 ; dy < k ; dy++) okay &= arr[i+k][j+dy];

            if (!okay) break;

            for (int dx = 0 ; dx < k ; dx++) arr[i+dx][j+k] = 0;
            arr[i+k][j+k] = 0;
            for (int dy = 0 ; dy < k ; dy++) arr[i+k][j+dy] = 0;

            if (v[k]) {
                v[k]--;
                btk(x, y + k + 1, v);
                v[k]++;
            }
        }
        for (int dx = 0 ; dx < k ; dx++) for (int dy = 0 ; dy < k ; dy++) arr[i+dx][j+dy] = 1;
        return;
    }

    int cnt = 25;
    for (int i = 0 ; i < 5 ; i++) cnt -= v[i];
    so = min(so, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    V(int) v = {5,5,5,5,5};
    for (int i = 0 ; i < 10 ; i++) for (int j = 0 ; j < 10 ; j++) cin >> arr[i][j];
    btk(0, 0, v);
    cout << (so == IMAX ? -1 : so);
}