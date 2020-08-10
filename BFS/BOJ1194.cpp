// 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define endl '\n'
#define blk ' '
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define int long long
#define str string
#define V(T) vector<T>
#define pb push_back
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>
#define IMAX ((1LL<<31)-1)
#define LMAX (((1LL<<62)-1)*2+1)
#define MS(T) memset(T,-1,sizeof(T))
#define ZS(T) memset(T,0,sizeof(T))
#define BIT(A,B) (!!((A)&(1LL<<(B))))
#define BITS(A,B,C) (((A)>>(B))&((1LL<<(C)-(B)+1)-1))
#define SHOW1(A,IX,EX) {for(int NI=(IX);NI<(EX);NI++){cout<<A[NI]<<' ';}cout<<'\n';}
#define SHOW2(A,IX,EX,IY,EY) {cout<<'\n';for(int NI=(IX);NI<(EX);NI++){for(int NJ=(IY);NJ<(EY);NJ++){cout<<A[NI][NJ]<<' ';}cout<<'\n';}}
#define IOSFAST() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define ST(V) sort(V.begin(),V.end())
#define PR(V) V.erase(unique(V.begin(),V.end()),V.end())
#define FIN() freopen("input.txt","r",stdin)
#define FOUT() freopen("output.txt","w",stdout)
#define rep(A,B,C) for(int A=(B);A<(C);A++)
#define repc(A,B,C) for(int A=(B);A<=(C);A++)
#define per(A,B,C) for(int A=(C)-1;A>=(B);A--)
#define lb(V,K) lower_bound(V.begin(),V.end(),K)-V.begin()
#define dd(a,b) !((a)%(b))
#define sc(x) int x;cin>>x
#define sc2(x,y) int x,y;cin>>x>>y
#define sc3(x,y,z) int x,y,z;cin>>x>>y>>z
#define scs(s) str s;cin>>s
#define BIG 1000000007
using namespace std;

int n, m, k, h=1, cnt, da, so = IMAX;
int arr[50][50], vis[1<<6][50][50], sx, sy, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void bfs() {
    Q(piii) q;
    q.push({0,{sx,sy}});
    vis[0][sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().ss.ff, y = q.front().ss.ss, key = q.front().ff;
        q.pop();
        rep(i, 0, 4) {
            int xx = x + dx[i], yy = y + dy[i], kkey = key;
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (arr[xx][yy] == 2) continue;
            if ('a' <= arr[xx][yy] && arr[xx][yy] <= 'f') kkey |= 1<<arr[xx][yy]-'a';
            else if ('A' <= arr[xx][yy] && arr[xx][yy] <= 'F' && !(kkey & (1<<arr[xx][yy]-'A'))) continue; 
            if (!(!vis[kkey][xx][yy] || vis[key][x][y] + 1 < vis[kkey][xx][yy])) continue;
            vis[kkey][xx][yy] = vis[key][x][y] + 1;
            q.push({kkey,{xx,yy}});
        }
    }
}

signed main() {
    IOSFAST();
    cin >> n >> m;
    rep(i, 0, n) {
        scs(s);
        rep(j, 0, m) {
            if (s[j] == '.') arr[i][j] = 0;
            else if (s[j] == '0') arr[i][j] = 0, sx = i, sy = j;
            else if (s[j] == '1') arr[i][j] = 1;
            else if (s[j] == '#') arr[i][j] = 2;
            else arr[i][j] = s[j];
        }
    }
    bfs();
    rep(i, 0, n) rep(j, 0, m) if (arr[i][j] == 1) {
        rep(k, 0, 1<<6) if (vis[k][i][j]) so = min(so, vis[k][i][j]);
    }
    cout << (so == IMAX ? -1 : so-1);
}