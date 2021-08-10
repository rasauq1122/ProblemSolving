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
#define itos            to_string
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

#define IF()            freopen("input.txt","r",stdin)
#define TF()            freopen("input.txt","w",stdout)
#define OF()            freopen("output.txt","w",stdout)

using namespace std;

signed main() {
    FASTIO();
	TC() {
		int n;
		cin >> n;
		if (n%2) {
			cout << 'c';
		}
		for (int i = 0 ; i < n-n%2 ; i++) {
			if ((n-1)/2 == i) cout << 'b';
			else cout << 'a';
		}
		cout << endl;
	}
}