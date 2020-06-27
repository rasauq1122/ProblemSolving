// 2019.11.11

#include <iostream>
#include <algorithm>
using namespace std;

int tree[100000][3] = {}, n, dat[100000] = {}, mns = 0;
bool who[100000] = {};

void dfs(int n, int m)
{
    if (n == -1) mns += m%2;
    else
    {
        dfs(tree[n][1],m);
        dfs(tree[n][2],m+tree[n][0]);
    }
}

int main()
{  
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> dat[i];
    for (int i = 0 ; i < n-1 ; i++)
    {
        char x;
        cin >> x >> tree[i][1] >> tree[i][2];
        if (x == '+') tree[i][0] = 0;
        else tree[i][0] = 1;

        for (int j = 1 ; j < 3; j++)
        {
            tree[i][j] = tree[i][j] > n ? tree[i][j]-n-1 : -1;
            if (tree[i][j] != -1) who[tree[i][j]] = true;
        }
    }

    int root;
    for (int i = 0 ; i < n-1 ; i++)
    {
        if (!who[i])
        {
            root = i;
            break;
        }
    }  

    sort(dat, dat+n);
    dfs(root, 0);

    int sum = 0;
    for (int i = 0 ; i < n ; i++) sum += dat[i] * ((mns-- > 0) ? -1 : 1); 

    cout << sum;
}