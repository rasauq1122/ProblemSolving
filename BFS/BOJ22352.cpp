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
#define fixed(a)        cout<<fixed;cout.precision(a);

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
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

#define IF()            freopen("a.in","r",stdin)
#define TF()            freopen("a.in","w",stdout)
#define OF()            freopen("a.out","w",stdout)

using namespace std;

int n, m;
int nap[2][30][30];
bool vis[30][30], chk = false;

bool isIn(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

bool bfs(int i, int j) {
    vis[i][j] = true;
    if (chk) return nap[0][i][j] == nap[1][i][j];

    queue <pii> q;
    int home = nap[0][i][j], away = nap[1][i][j];

    chk = home != away;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    q.push({i, j});
    while (!q.empty()) {
        pii now = q.front();
        int nx = now.ff, ny = now.ss;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            
            int xx = nx+dx[i], yy = ny+dy[i]; 
            if (isIn(xx, yy)) {
                if (vis[xx][yy]) {
                    continue;
                }

                if (nap[0][xx][yy] != home) {
                    continue;
                }

                if (nap[1][xx][yy] != away) {
                    return false;
                }

                q.push({xx, yy});
                vis[xx][yy] = true;
            }
        }
    }
    return true;
}

signed main() {
    FASTIO();
    cin >> n >> m;
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            for (int k = 0 ; k < m ; k++) {

                cin >> nap[i][j][k];
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            
            if (!vis[i][j]) {
                bool okay = bfs(i, j);
                if (!okay) {
                    return cout << "NO", 0;
                }
            }
        }
    }
    cout << "YES";
}