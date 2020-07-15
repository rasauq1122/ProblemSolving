// 2020.07.15

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
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

int t;
double so;

int main() {
    cin >> t;
    for (int ti = 0, n ; ti < t ; ti++) {
        so = IMAX;
        cin >> n;
        V(pii) v;
        for (int i = 0, x, y ; i < n ; i++) {
            cin >> x >> y;
            v.pb({x,y});
        } 
        for (int i = 0 ; i < (1<<n) ; i++) {
            int cnt = 0, sumx = 0, sumy = 0;
            for (int j = 0 ; j < n ; j++) cnt += BIT(i,j);
            if (cnt != n/2) continue;
            for (int j = 0 ; j < n ; j++) {
                sumx += (1-2*BIT(i,j))*v[j].ff;
                sumy += (1-2*BIT(i,j))*v[j].ss;
            }
            so = min(so, sqrt(1LL*sumx*sumx+1LL*sumy*sumy));
        }
        printf("%.6f\n", so);
    } 
}