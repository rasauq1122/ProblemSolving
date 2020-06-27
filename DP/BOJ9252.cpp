// 2020.05.24

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

#define pis pair<int,string>
#define ff first
#define ss second

int dp[1001][1001];
string dps[1001][1001];
string s1, s2;

pis sol(int i, int j) {
    if (dp[i][j] != -1) return {dp[i][j], dps[i][j]};
    if (i == 0 || j == 0) return {dp[i][j] = 0, dps[i][j] = ""};
    
    pis p = max(sol(i,j-1), sol(i-1,j));
    if (s1[i-1] == s2[j-1]) {
        pis now = sol(i-1,j-1);
        p = max(p, {now.ff+1, now.ss+s1[i-1]});
    }
    return {dp[i][j] = p.ff, dps[i][j] = p.ss};
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin >> s1 >> s2;
    pis now = sol(s1.size(), s2.size());
    cout << now.ff << '\n';
    if (now.ff) cout << now.ss;
}