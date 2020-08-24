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
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007
 
using namespace std;
 
wi mult(wi a, wi b) {
    wi rtn(3, vi(3));
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                rtn[i][j] += (a[i][k]*b[k][j])%MOD;
                rtn[i][j] %= MOD;  
            }
        }
    }
    return rtn;
}

wi pow(wi a, int b) {
    if (b == 0) {
        wi rtn = {{1,0,0}, {0,1,0}, {0,0,1}};
        return rtn;
    }

    if (b%2) {
        return mult(a, pow(a, b-1));
    }
    else {
        wi sqrt = pow(a, b/2);
        return mult(sqrt, sqrt);
    }
}

signed main() {
    FASTIO();
    
    wi v = {{0,1,1}, {1,0,1}, {1,1,1}};

    int n;
    cin >> n;
    wi mat = pow(v, n-1);
    
    int sum = 0;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            sum += mat[i][j];
            sum %= MOD;
        }
    }

    cout << sum;
}