// 2019.11.05

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool graph[26][26] = {}, vis[26] = {};
    int abc, n, m, rst = 0;
    
    cin >> abc >> n;
    for (int i = 0 ; i < n ; i++)
    {
        char to, from;
        cin >> from >> to;
        graph[from-'A'][to-'A'] = true;
    }

    stack <int> s;

    for (int i = 0 ; i < abc ; i++)
    {
        bool ok = true;
        for (int j = 0 ; j < abc ; j++)
        {
            if (graph[j][i]) ok = false;
            if (!ok) break;
        }
        if (ok) s.push(i);
    }

    // printf("  ");
    // for (int i = 0 ; i < abc ; i++) printf("%c ",i+'A');
    
    // for (int i = 0 ; i < abc ; i++) 
    // {
    //     printf("\n");
    //     printf("%c ",i+'A');
    //     for (int j = 0 ; j < abc ; j++) printf("%d ",graph[i][j]);
    // }

    cin >> m;
    for (int i = 0 ; i < m ; i++)
    {
        char from;
        cin >> from;
        for (int j = 0 ; j < abc ; j++) 
        {
            graph[from-'A'][j] = false;
            graph[j][from-'A'] = false;
        }
    }

    // printf("\n\n  ");
    // for (int i = 0 ; i < abc ; i++) printf("%c ",i+'A');
    
    // for (int i = 0 ; i < abc ; i++) 
    // {
    //     printf("\n");
    //     printf("%c ",i+'A');
    //     for (int j = 0 ; j < abc ; j++) printf("%d ",graph[i][j]);
    // }

    while(!s.empty())
    {
        int now = s.top();
        // printf("deb : now %d\n",now);
        s.pop();
        for (int i = 0 ; i < abc ; i++) 
        {
            if(graph[now][i] && !vis[i])
            {
                vis[i] = true;
                s.push(i);
                // printf("deb : pus %d\n",i);
                rst++;
            }
        }
    }

    printf("%d",rst);
}