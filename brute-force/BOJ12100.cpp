// 2020.07.15

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
#define ED <<'\n'
#define BK <<' '
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

int n, arr[20][20], da;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;

    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) cin >> arr[i][j];
    
    int ws[20][20];
    for (int k = 0 ; k < (1<<10) ; k++) {
        for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) ws[i][j] = arr[i][j];
        Q(int) q;
        for (int b = 0 ; b < 5 ; b++) {
            int md = BITS(k,2*b,2*b+1);
            if (md < 2) {
                for (int i = 0 ; i < n ; i++) {
                    int x = 0;
                    for (int j = (md ? 0 : n-1) ; 0 <= j && j < n ; (md ? j++ : j--)) if (ws[i][j]) {
                        if (!x) x = ws[i][j];
                        else if (x == ws[i][j]) {
                            q.push(x*2);
                            x = 0;
                        } else {    
                            q.push(x);
                            x = ws[i][j];
                        }
                    }
                    if (x) q.push(x);
                    for (int j = 0 ; j < n ; j++) ws[i][j] = 0;
                    for (int j = (md ? 0 : n-1) ; !q.empty() ; (md ? j++ : j--)) {
                        int p = q.front();
                        q.pop();
                        ws[i][j] = p;
                    }
                }
            } else {
                for (int i = 0 ; i < n ; i++) {
                    int x = 0;
                    for (int j = (md == 2 ? 0 : n-1) ; 0 <= j && j < n ; (md == 2 ? j++ : j--)) if (ws[j][i]) {
                        if (!x) x = ws[j][i];
                        else if (x == ws[j][i]) {
                            q.push(x*2);
                            x = 0;
                        } else {    
                            q.push(x);
                            x = ws[j][i];
                        }
                    }
                    if (x) q.push(x);
                    for (int j = 0 ; j < n ; j++) ws[j][i] = 0;
                    for (int j = (md == 2 ? 0 : n-1) ; !q.empty() ; (md == 2 ? j++ : j--)) {
                        int p = q.front();
                        q.pop();
                        ws[j][i] = p;
                    }
                }
            }
        }
        for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) da = max(da, ws[i][j]);
    }
    cout << da;
}