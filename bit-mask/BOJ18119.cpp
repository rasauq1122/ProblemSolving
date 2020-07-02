// 2020.07.02

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#define pii pair<int,int>
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
using namespace std;

int n, m, p;
V(int) v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        str s;
        cin >> s;
        int len = s.size(), k = 0;
        for (int j = 0 ; j < len ; j++) k |= 1<<s[j]-'a';
        v.pb(k);
    }
    
    for (int i = 0, k = (1<<26)-1, o ; i < m ; i++) {
        char c;
        int cnt = 0;
        cin >> o >> c;
        if (o == 2) k |= 1<<c-'a';
        else k -= 1<<c-'a';

        for (int j = 0 ; j < n ; j++) if ((k&v[j]) == v[j]) cnt++; 
        cout << cnt << '\n';
    }
}