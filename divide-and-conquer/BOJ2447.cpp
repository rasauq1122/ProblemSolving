#include <bits/stdc++.h>

#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define pf0()           cout<<'\n'
#define pf1(x)          cout<<' '<<(x)<<'\n'
#define pf2(x,y)        cout<<' '<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)      cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)    cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)  cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define TC()            int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO()        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl            '\n'
#define blk             ' '
#define pii             pair<int,int>
#define ff              first
#define ss              second
#define vi              vector<int>
#define vp              vector<pair<int,int>>
#define wi              vector<vector<int>>
#define wp              vector<vector<pair<int,int>>>
#define pb              push_back
#define bp              pop_back
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

using namespace std;

int n, k;
bool arr[6561][6561];

int pow3(int k) {
    int rtn = 1;
    for (int i = 0 ; i < k ; i++) {
        rtn *= 3;
    }
    return rtn;
}

void dnq(int x, int y, int k) {
    if (k == 0) {
        arr[x][y] = 1;
        return;
    }
    dnq(x, y, k-1);
    dnq(x+pow3(k-1), y, k-1);
    dnq(x+2*pow3(k-1), y, k-1);
    dnq(x, y+pow3(k-1), k-1);
    dnq(x+2*pow3(k-1), y+pow3(k-1), k-1);
    dnq(x, y+2*pow3(k-1), k-1);
    dnq(x+pow3(k-1), y+2*pow3(k-1), k-1);
    dnq(x+2*pow3(k-1), y+2*pow3(k-1), k-1);
}

signed main() {
    FASTIO();
    cin >> n;
    for (int i = n ; i > 1 ; i /= 3) k++;
    dnq(0, 0, k);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (arr[i][j]) cout << '*';
            else cout << blk;
        }
        cout << endl;
    }
}