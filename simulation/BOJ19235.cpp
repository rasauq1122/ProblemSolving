// 2020.06.27

#include <iostream>
#include <algorithm>
using namespace std;

int score, sum, blk[2][3][4];

void add(bool isblue, int x, int y, int t) {
    if (isblue) {
        if (t == 2) t = 3;
        else if (t == 3) t = 2;
        y = x;
    }

    sum++;
    if (t == 1) blk[isblue][0][y] += 1<<(blk[isblue][2][y]++);
    else if (t == 2) {
        int hei = max(blk[isblue][2][y], blk[isblue][2][y+1]);
        blk[isblue][0][y] += 1<<hei;
        blk[isblue][0][y+1] += 1<<hei;
        blk[isblue][1][y] += 1<<hei;
        blk[isblue][2][y] = blk[isblue][2][y+1] = hei+1;
    } else {
        blk[isblue][0][y] += 1<<(blk[isblue][2][y]++);
        blk[isblue][0][y] += 1<<(blk[isblue][2][y]++);
    }
    if (t > 1) sum++;
}

void del(bool isblue) {
    while (true) {
        int checker = blk[isblue][0][0] & blk[isblue][0][1] & blk[isblue][0][2] & blk[isblue][0][3];
        if (!checker) break;

        for (int i = 3 ; i >= 0 ; i--) if (checker & (1<<i)) { 
            score++;
            sum -= 4;
            for (int j = 0 ; j < 4 ; j++) {
                blk[isblue][0][j] -= 1<<i;
                if (blk[isblue][1][j] & (1<<i)) blk[isblue][1][j] -= 1<<i;
            }
        }

        for (int i = 0 ; i < 4 ; i++) blk[isblue][2][i] = 0;
        
        int new_blk[2][4] = {};
        for (int i = 0 ; i < 6 ; i++) for (int j = 0 ; j < 4 ; j++) if (blk[isblue][0][j] & (1<<i)) {
            if (blk[isblue][1][j] & (1<<i)) {
                int h = max(blk[isblue][2][j], blk[isblue][2][j+1]);
                new_blk[0][j] += 1<<h;
                new_blk[0][j+1] += 1<<h;
                new_blk[1][j] += 1<<h;
                blk[isblue][2][j] = blk[isblue][2][j+1] = h+1;
                j++;
            }
            else new_blk[0][j] += 1<<(blk[isblue][2][j]++);
        }

        for (int i = 0 ; i < 4 ; i++) {
            blk[isblue][0][i] = new_blk[0][i];
            blk[isblue][1][i] = new_blk[1][i];
        }
    }
}

void cut(bool isblue) {
    int over = 0;
    for (int i = 0 ; i < 4 ; i++) for (int j = 4 ; j < 6 ; j++) if (blk[isblue][0][i] & (1<<j)) over = j-3;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < over ; j++) sum -= !!(blk[isblue][0][i]&(1<<j));
        blk[isblue][0][i] >>= over;
        blk[isblue][1][i] >>= over;
        blk[isblue][2][i] = max(0, blk[isblue][2][i]-over);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, x, y, t ; i < n ; i++) {
        cin >> t >> x >> y;
        for (int j = 0 ; j < 2 ; j++) {
            add(j, x, y, t);
            del(j);
            cut(j);
        }
    }

    cout << score << '\n' << sum;
}