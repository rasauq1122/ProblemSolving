// 2020.03.19

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int graph[100][100], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, h, w;
bool key['Z'-'A'+1], visit[100][100], started[100][100], new_key;
queue < pair <int, int> > q;
pair <int, int> start_node[2*(100+100-2)];

void make_start()
{
    int x = 0, y = 0, mod = 0;
    for (int i = 0 ; i < 2*(h+w-2) ; i++)
    {   
        start_node[i] = {x,y};
        if (!mod)
        {
            if (++x == h-1) mod = 1; 
        }
        else if (mod == 1)
        {
            if (++y == w-1) mod = 2;
        }
        else if (mod == 2)
        {
            if (--x == 0) mod = 3;
        }
        else
        {
            if (--y == 0) mod = 0;
        }
    }
}

int bfs(int start_x, int start_y)
{
    memset(visit, 0, sizeof(visit));
    q.push({start_x, start_y});
    visit[start_x][start_y] = true;

    int score = 0;

    while(!q.empty())
    {
        int now_x = q.front().first, now_y = q.front().second;
        q.pop();
        if (graph[now_x][now_y] == -2)
        {
            score++;
            graph[now_x][now_y] = 0;
        }
        else if ('a' <= graph[now_x][now_y] && graph[now_x][now_y] <= 'z')
        {
            if (!key[graph[now_x][now_y]-'a'])
            {
                key[graph[now_x][now_y]-'a'] = true;
                new_key = true;
            }
            graph[now_x][now_y] = 0;
        }
        else if ('A' <= graph[now_x][now_y] && graph[now_x][now_y] <= 'Z') graph[now_x][now_y] = 0;

        started[now_x][now_y] = true;

        for (int i = 0 ; i < 4 ; i++)
        {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
            if (visit[next_x][next_y] || graph[next_x][next_y] == -1 || (('A' <= graph[next_x][next_y] && graph[next_x][next_y] <= 'Z') && !key[graph[next_x][next_y]-'A'])) continue;
            q.push({next_x, next_y});
            visit[next_x][next_y] = true;
        }
    }

    return score;
}

int gogo()
{
    memset(started, 0, sizeof(started));
    int start_x, start_y, score = 0, max_loop = 2*(h+w-2);
    bool is_all_block;
    for (int i = 0 ; i < max_loop ; i++)
    {
        new_key = false;
        if (!i) is_all_block = true;

        start_x = start_node[i].first;
        start_y = start_node[i].second;
        
        int now_start = graph[start_x][start_y];
        bool can_go_here = ((now_start == -2 || now_start == 0 || ('a' <= now_start && now_start <= 'z')) && !started[start_x][start_y])
                           || (('A' <= now_start && now_start <= 'Z') && key[now_start-'A']);

        is_all_block &= !can_go_here;

        if (can_go_here) score += bfs(start_x, start_y);
        if (new_key) memset(started, 0, sizeof(started));
        if (i == max_loop - 1 && !is_all_block) i = -1; 
    }

    return score;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(key, 0, sizeof(key));
        string s;
        cin >> h >> w;
        make_start();
        for (int i = 0 ; i < h ; i++)
        {
            cin >> s;
            for (int j = 0 ; j < w ; j++)
            {
                if (s[j] == '*') graph[i][j] = -1;
                else if (s[j] == '$') graph[i][j] = -2;
                else graph[i][j] = s[j] == '.' ? 0 : s[j];
            }
        }
        cin >> s;
        if (s != "0")
        {
            int len = s.size();
            for (int i = 0 ; i < len ; key[s[i]-'a'] = true, i++);
        }
        cout << gogo() << '\n'; 
    }
}