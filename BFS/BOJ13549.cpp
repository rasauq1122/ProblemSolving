// 2020.07.06

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

int s, e, arr[100001];

void bfs() {
    Q(int) q;
    q.push(s);
    arr[s] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0, xx ; i < 3 ; i++) { 
            switch (i) {
            case 0:
                xx = x + 1;
                break;
            case 1:
                xx = x - 1;
                break;
            case 2:
                xx = 2*x;
                break;
            }
            if (xx < 0 || xx > 100000) continue;
            if ((arr[xx] == 0) || (arr[xx] > arr[x] + (i != 2))) {
                arr[xx] = arr[x] + (i != 2);
                q.push(xx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> e;
    bfs();
    cout << arr[e]-1;
}