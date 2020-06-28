// 2020.06.28

#include <iostream>
#include <map>
#define ll long long
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        map < ll, int > m; 
        int k, siz = 0;
        cin >> k;
        
        for (int i = 0, n ; i < k ; i++) {
            char c;
            cin >> c >> n;
            if (c == 'I') {
                if (m.count(n)) m[n]++;
                else m[n] = 1;
                siz++;
            } else if (siz) {
                if (siz == 1) m.clear();
                else {
                    if (n == -1) {
                        m[m.begin()->first]--;
                        if (!m[m.begin()->first]) m.erase(m.begin());
                    } else {
                        m[(--m.end())->first]--;
                        if (!m[(--m.end())->first]) m.erase(--m.end());
                    }
                }
                siz--;
            }
        }

        if (siz) cout << (--m.end())->first << ' ' << m.begin()->first << '\n';
        else cout << "EMPTY\n";
    }
}