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
#define BIT(A,B) !!((A)&(1<<(B)))
using namespace std;

int n, l, arr[2][100][100], cnt;
bool chk[2][100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> l;
    for (int i = 0 ; i < n ; i++) for (int j = 0, x ; j < n ; j++) {
        cin >> x;
        arr[0][i][j] = x;
        arr[1][j][i] = x;
    }

    for (int cs = 0 ; cs < 2 ; cs++) {
        for (int i = 0 ; i < n ; i++) {
            bool okay = true;
            int now = arr[cs][i][0];
            for (int j = 1 ; j < n ; j++) {
                if (abs(now-arr[cs][i][j]) > 1) {
                    okay = false; 
                    break;
                }
                if (arr[cs][i][j] > now) for (int k = 0 ; k < l ; k++) {
                    if (j-1-k < 0 || chk[cs][i][j-1-k]) {
                        okay = false; 
                        break;
                    }
                    chk[cs][i][j-1-k] = true; 
                } else if (arr[cs][i][j] < now) {
                    for (int k = 0 ; k < l ; k++) {
                        if (j+k >= n || arr[cs][i][j] != arr[cs][i][j+k]) {
                            okay = false;
                            break;
                        }
                        chk[cs][i][j+k] = true;
                    }
                    j += l-1;
                }
                now = arr[cs][i][j];
            }
            cnt += okay;
        }
    }
    cout << cnt;
}