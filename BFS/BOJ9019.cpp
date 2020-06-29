// 2020.06.29

#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int back[10000];
char way[10000];

void bfs(int a, int b) {
    queue <int> q;
    way[a] = '?';
    q.push(a); 
    while (!q.empty()) {
        int f = q.front();
        if (back[b] != -1) break;
        q.pop();
        int s = (f == 0) ? 9999 : f-1;
        int d = 2*f % 10000;
        
        int n[4] = {f/1000, f/100 - f/1000*10, f/10 - f/100*10, f - f/10*10};
        int l = n[1]*1000 + n[2]*100 + n[3]*10 + n[0];
        int r = n[3]*1000 + n[0]*100 + n[1]*10 + n[2];
        
        int p[4] = {s, d, l, r};
        char c[4] = {'S', 'D', 'L', 'R'};

        for (int i = 0 ; i < 4; i++) if (back[p[i]] == -1 && p[i] != a) {
            q.push(p[i]);
            back[p[i]] = f;
            way[p[i]] = c[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        memset(back, -1, sizeof(back));
        bfs(a, b);

        string s = "";
        for (int p = b ; way[p] != '?' ; p = back[p]) s += way[p];
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}