// 2019.12.31 
// partial-sum

#include <iostream>
#include <algorithm>
using namespace std;

#define BIG 2048

int paper[2*BIG][2*BIG], xx1, yy1, xx2, yy2;

int getX(int k, int i, int lo, int hi)
{
    if (hi < xx1 || xx2 < lo) return 0;
    if (xx1 <= lo && hi <= xx2) return paper[i][k];
    return max(getX(k,i*2,lo,(lo+hi)/2),getX(k,i*2+1,(lo+hi)/2+1,hi));
}

int getY(int i, int le, int ri)
{
    if (ri < yy1 || yy2 < le) return 0;
    if (yy1 <= le && ri <= yy2) return getX(i,1,0,BIG-1);
    return max(getY(i*2,le,(le+ri)/2),getY(i*2+1,(le+ri)/2+1,ri));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0, xx1, yy1, xx2, yy2 ; i < n ; i++)
    {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        paper[BIG+xx1][BIG+yy1]++;
        paper[BIG+xx1][BIG+yy2]--;
        paper[BIG+xx2][BIG+yy1]--;
        paper[BIG+xx2][BIG+yy2]++;
    }

    for (int i = 1 ; i <= 1500 ; i++) for (int j = 0 ; j <= 1500 ; j++) paper[BIG+i][BIG+j] += paper[BIG+i-1][BIG+j];
    for (int j = 1 ; j <= 1500 ; j++) for (int i = 0 ; i <= 1500 ; i++) paper[BIG+i][BIG+j] += paper[BIG+i][BIG+j-1]; 

    for (int j = BIG ; j < 2*BIG ; j++) for (int i = BIG-1 ; i > 0 ; i--) paper[i][j] = max(paper[i*2][j],paper[i*2+1][j]);
    for (int j = BIG-1 ; j > 0 ; j--) for (int i = 1 ; i < 2*BIG ; i++) paper[i][j] = max(paper[i][j*2],paper[i][j*2+1]);

    for ( ; m-- ; )
    {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        xx2--;
        yy2--;
        cout << getY(1,0,BIG-1) << '\n';
    }
}