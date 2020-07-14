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
#define BITS(A,B,C) ((A>>B)&((1<<C-B+1)-1))
using namespace std;

int arr[3][3];

int btk(bool who) {

    for (int i = 0 ; i < 3 ; i++) if (arr[i][0]) {
        bool okay = true;
        for (int j = 1 ; j < 3 ; j++) if (arr[i][0] != arr[i][j]) okay = false;
        if (okay) return arr[i][0];
    }

    for (int i = 0 ; i < 3 ; i++) if (arr[0][i]) {
        bool okay = true;
        for (int j = 1 ; j < 3 ; j++) if (arr[0][i] != arr[j][i]) okay = false;
        if (okay) return arr[0][i];
    }

    if (arr[1][1]) {
        bool okay = true;
        for (int i = 0 ; i < 3 ; i++) if (arr[1][1] != arr[i][i]) okay = false;
        if (okay) return arr[1][1];

        okay = true;
        for (int i = 0 ; i < 3 ; i++) if (arr[1][1] != arr[i][2-i]) okay = false;
        if (okay) return arr[1][1];
    }

    bool okay = true;
    for (int i = 0 ; i < 3 ; i++) for (int j = 0 ; j < 3 ; j++) if (!arr[i][j]) okay = false;
    if (okay) return 3;

    bool chk = false;
    for (int i = 0 ; i < 3 ; i++) for (int j = 0 ; j < 3 ; j++) if (!arr[i][j]) {
        arr[i][j] = 1+who;
        int x = btk(!who);
        arr[i][j] = 0;
        if (x == who+1) return x;
        if (x == 3) chk = true;
    }

    return (chk ? 3 : !who+1);
}

int main() {
    for (int i = 0 ; i < 3 ; i++) for (int j = 0 ; j < 3 ; j++) cin >> arr[i][j];

    int x = 0, y = 0;
    for (int i = 0 ; i < 3 ; i++) for (int j = 0 ; j < 3 ; j++) if (arr[i][j]) {
        if (arr[i][j] == 1) x++;
        else y++;
    }

    bool seon = x != y;
    int ans = btk(seon);

    if (ans == 3) cout << 'D';
    else cout << (ans == seon+1 ? 'W' : 'L');    
}