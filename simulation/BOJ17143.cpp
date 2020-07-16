// 2020.07.16

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

int r, c, m, shk[10001][5], arr[100][100], sum, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> m;
    for (int i = 0, nr, nc, ns, nd, nz ; i < m ; i++) {
        cin >> nr >> nc >> ns >> nd >> nz;
        nr--, nc--;
        if (nd == 2) nd = 3;
        else if (nd == 3) nd = 2;
        shk[nz][0] = nr, shk[nz][1] = nc, shk[nz][2] = ns, shk[nz][3] = nd-1;
        arr[nr][nc] = nz;
    }

    for (int i = 0 ; i < c ; i++) {
        for (int j = 0 ; j < r ; j++) if (arr[j][i]) {
            sum += arr[j][i], arr[j][i] = 0;
            break;
        }
        V(bool) vis(10001);
        int narr[100][100] = {};
        for (int x = 0 ; x < r ; x++) for (int y = 0 ; y < c ; y++) if (arr[x][y] && !vis[arr[x][y]]) {
            int nz = arr[x][y], md = shk[nz][3], del = shk[nz][2]%(2*(md%2 ? c : r)-2);
            vis[nz] = true, arr[x][y] = 0;
            
            int nx = x, ny = y;
            for (int t = 0 ; t < del ; t++) {
                int xx = nx + dx[md], yy = ny + dy[md];
                if (xx < 0 || xx >= r || yy < 0 || yy >= c) {
                    md = (shk[nz][3] = (shk[nz][3]+2)%4);
                    xx = nx + dx[md], yy = ny + dy[md];
                } 
                nx = xx, ny = yy;
            } 

            narr[nx][ny] = max(nz, narr[nx][ny]);
        }       
        for (int i = 0 ; i < r ; i++) for (int j = 0 ; j < c ; j++) arr[i][j] = narr[i][j];
    }
    cout << sum;
}