#include <bits/stdc++.h>

#define prt(V)          {for(int NI=0;NI<(V).size();NI++){cout<<(V[NI])<<' ';}cout<<'\n';}
#define prt2(V)         {for(int NI=0;NI<(V).size();NI++){for(int NJ=0;NJ<(V[NI]).size();NJ++){cout<<V[NI][NJ]<<' ';}cout<<'\n';}}

#define pf(x)           cout<<(x)
#define pfb(x)          cout<<(x)<<' '
#define pf1(x)          cout<<(x)<<'\n'
#define pf2(x,y)        cout<<(x)<<' '<<(y)<<'\n'
#define pf3(x,y,z)      cout<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define pf4(x,y,z,w)    cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define pf5(x,y,z,w,u)  cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define bpf1(x)         cout<<' '<<(x)<<'\n'
#define bpf2(x,y)       cout<<' '<<(x)<<' '<<(y)<<'\n'
#define bpf3(x,y,z)     cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<'\n'
#define bpf4(x,y,z,w)   cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<'\n'
#define bpf5(x,y,z,w,u) cout<<' '<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<(u)<<'\n'

#define TC()            int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO()        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl            '\n'
#define blk             ' '
#define pii             pair<int,int>
#define ff              first
#define ss              second
#define pb              push_back
#define vi              vector<int>
#define wi              vector<vector<int>>
#define all(v)          (v).begin(), (v).end()
#define INF             ((1LL<<31)-1)
#define int             long long
#define MOD             1000000007

using namespace std;

int n, m;
int arr[100][100], sx, sy, ex, ey;
int vis[100][100];

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void bfs() {
    queue <pii> q;
    q.push({sx,sy});

    vis[sx][sy] = 0;
    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int xx = x;
            int yy = y;

            while (true) {
                xx += dx[i];
                yy += dy[i];

                if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                    break;
                }

                if (vis[xx][yy] &&
                    vis[xx][yy] <= vis[x][y] + 1) {
                    continue;
                }

                if (arr[xx][yy]) {
                    break;
                }

                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
}

signed main() {
    FASTIO();
    
    cin >> m >> n;
    
    bool chk = false;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        
        for (int j = 0 ; j < m ; j++) {
            if (s[j] == '*') arr[i][j] = 1;
            else {
                arr[i][j] = 0;
                
                if (s[j] == 'C') {
                    if (!chk) sx = i, sy = j, chk = true;
                    else ex = i, ey = j;
                }
            }   
        }
    }

    bfs();
    cout << vis[ex][ey]-1;
}