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
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) ((A>>B)&((1LL<<C-B+1)-1))
#define endl '\n'
#define blk ' '
#define SHOW(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=IX;NI<=EX;NI++){for(int NJ=IY;NJ<=EY;NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
using namespace std;

int n, m, k, arr[4000001];

int insert(int x) {
    if (x == arr[x]) return arr[x] = x+1;
    return arr[x] = insert(arr[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    MS(arr);
    for (int i = 0, x ; i < m ; i++) {
        cin >> x;
        arr[x] = x;
    }
    for (int i = n, x = -1 ; i >= 0 ; i--) {
        if (arr[i] == -1) arr[i] = x;
        else x = arr[i];
    }
    for (int i = 0, x ; i < k ; i++) {
        cin >> x;
        cout << insert(x+1)-1 << endl;
    }
}   