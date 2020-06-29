// 2020.06.29

#include <iostream>
#include <algorithm>
using namespace std;

int board[500][500], x, y, da, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool visit[500][500];

bool in(int nx, int ny) {
    return nx >= 0 && nx < x && ny >= 0 && ny < y;
}

void btk(int nx, int ny, int stp, int sco) {
    if (stp == 4) {
        da = max(da, sco);
        return;
    }
    visit[nx][ny] = 1;
    
    for (int i = 0 ; i < 4 ; i++) 
        if (in(nx+dx[i], ny+dy[i])) 
            if (!visit[nx+dx[i]][ny+dy[i]]) 
                btk(nx+dx[i], ny+dy[i], stp+1, sco+board[nx+dx[i]][ny+dy[i]]);
    
    if (stp == 2) 
        for (int i = 0 ; i < 2 ; i++) 
            for (int j = 2 ; j < 4 ; j++)
                if (in(nx+dx[i], ny+dy[i]) && in(nx+dx[j],ny+dy[j]))
                    if (!visit[nx+dx[i]][ny+dy[i]] && !visit[nx+dx[j]][ny+dy[j]])
                        btk(nx, ny, stp+2, sco+board[nx+dx[i]][ny+dy[i]]+board[nx+dx[j]][ny+dy[j]]);

    visit[nx][ny] = 0; 
}

int main() {
    cin >> x >> y;
    for (int i = 0 ; i < x ; i++) for (int j = 0 ; j < y ; j++) cin >> board[i][j];
    for (int i = 0 ; i < x ; i++) for (int j = 0 ; j < y ; j++) btk(i, j, 1, board[i][j]);
    cout << da;
}