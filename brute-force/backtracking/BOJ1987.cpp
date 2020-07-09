// 2020.04.14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, graph[20][20], best_score, dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
bool abc[26];
void btk(int x, int y, int score) {
    abc[graph[x][y]] = true;
    best_score = max(++score, best_score);

    for (int i = 0, xx, yy ; i < 4 ; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
        if (!abc[graph[xx][yy]]) btk(xx, yy, score);
    }

    score--;
    abc[graph[x][y]] = false;
}

int main() {
    cin >> r >> c;
    for (int i = 0 ; i < r ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < c ; j++) graph[i][j] = s[j]-'A';
    }
    
    btk(0,0,0);
    cout << best_score;
}