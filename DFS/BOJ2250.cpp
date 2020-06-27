// 2019.11.05

#include <iostream>
#include <queue>
using namespace std;

int n, tree[10001][2] = {}, xy[10001][2] = {}, x = 1, root[10001] = {};

void dfs(int node, int y)
{
    if (tree[node][0] != -1) dfs(tree[node][0],y+1);

    if (xy[y][0] > x) xy[y][0] = x;
    if (xy[y][1] < x) xy[y][1] = x;
    x++;

    if (tree[node][1] != -1) dfs(tree[node][1],y+1);
}

int main()
{
    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++)
    {
        int data, le, ri;
        scanf("%d %d %d",&data,&le,&ri);
        tree[data][0] = le;
        tree[data][1] = ri;
        if (le != -1) root[le] = 1;
        if (ri != -1) root[ri] = 1;
    }

    for (int i = 1; i <= 10000 ; i++)
    {
        xy[i][0] = 10001;
        xy[i][1] = 0;
    }

    int key;
    for (int i = 1 ; i <= n ; i++) if (root[i] == 0) key = i;

    dfs(key,1);

    int max = 0, maxY = 0;
    for (int i = 1 ; i < 10000 ; i++)
    {
        if (xy[i][1] - xy[i][0] + 1 >= 0 && xy[i][1] - xy[i][0] + 1 > max)
        {
            maxY = i;
            max = xy[i][1] - xy[i][0] + 1;
        }
    }

    printf("%d %d",maxY,max);
}