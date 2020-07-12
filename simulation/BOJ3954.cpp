// 2020.07.12

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
#define pil pair<int,ll>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int ti = 0 ; ti < t ; ti++) {
        str s, in;
        int sm, sc, si, cs = 0;
        cin >> sm >> sc >> si >> s >> in;
        V(int) m(sm), jump(sc);
        
        S(int) st;
        for (int i = 0 ; i < sc ; i++) {
            if (s[i] == '[') st.push(i);
            else if (s[i] == ']') {
                int x = st.top();
                jump[x] = i, jump[i] = x;
                st.pop();
            }
        }

        ll t = 0;
        bool loop = false;
        S(pil) lp;
        lp.push({0,0});
        for (int i = 0, j = 0 ; i < sc ; i++, t++) {
            switch (s[i]) {
                case '-':
                    if (m[cs] == 0) m[cs] = 255;
                    else m[cs]--; 
                    break;
                case '+':
                    m[cs]++;
                    m[cs] %= 256;
                    break;
                case '<':
                    if (cs == 0) cs = sm-1;
                    else cs--;
                    break;
                case '>':
                    cs++;
                    cs %= sm;
                    break;
                case '[':
                    if (!m[cs]) i = jump[i];
                    break;
                case ']':
                    if (m[cs]) {
                        if (lp.top().ff != i) lp.push({i,t});
                        else if (t - lp.top().ss > 50000000) loop = true;
                        i = jump[i];
                    } else if (lp.top().ff == i) lp.pop();
                    break;
                case '.':
                    break;
                case ',':
                    if (j == si) m[cs] = 255;
                    else m[cs] = in[j++];
                    break;
            }
            if (loop) break;
        }

        if (loop) cout << "Loops " << jump[lp.top().ff] << ' ' << lp.top().ff << '\n';
        else cout << "Terminates\n";
    }
}