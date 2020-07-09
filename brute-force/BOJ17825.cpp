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

int dice[10], loc[4], da;
int score[32] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35};
int nxt[32], start[32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0 ; i < 10 ; i++) cin >> dice[i];
    for (int i = 0 ; i < 32 ; i++) {
        nxt[i] = 1;
        start[i] = 1;
    }
    nxt[20] = start[20] = 12;
    nxt[23] = start[23] = 6;
    nxt[25] = start[25] = 4;
    nxt[31] = start[31] = -11;
    start[5] = 16;
    start[10] = 14;
    start[15] = 11;
 
    for (int i = 0 ; i < (1<<20) ; i++) {
        bool ok = true;
        int now = 0;
        for (int j = 0 ; j < 4 ; j++) loc[j] = 0;
        for (int j = 0 ; j < 10 ; j++) {
            int sel = BIT(i,2*j+1)*2 + BIT(i,2*j);
            if (loc[sel] == 32) {
                ok = false;
                break;
            }
            loc[sel] += start[loc[sel]];
            for (int k = 1 ; k < dice[j] && loc[sel] != 32; k++) loc[sel] += nxt[loc[sel]];

            if (loc[sel] != 32) {
                now += score[loc[sel]];
                for (int k = 0 ; k < 4 ; k++) if (sel != k && loc[sel] == loc[k]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            if (now > da) k = i;
            da = max(da, now);
        }
    }
    cout << da;
}