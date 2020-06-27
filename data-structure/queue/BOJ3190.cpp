// 2020.03.31

#include <queue>
#include <iostream>
using namespace std;

bool apple[100][100], snake[100][100];
int n, k, l, dir, delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, head[2], tick;
queue < pair <int, int> > q_snake, q_command;

int main()
{
    cin >> n >> k;
    for (int i = 0, x, y ; i < k ; i++)
    {
        cin >> x >> y;
        apple[x-1][y-1] = true;
    }

    cin >> l;
    for (int i = 0, x; i < l ; i++)
    {
        char c;
        cin >> x >> c;
        q_command.push({x,c-'A'});
    }

    q_snake.push({0, 0});
    snake[0][0] = true;
    while (true)
    {
        tick++;
        for (int i = 0 ; i < 2 ; i++) head[i] += delta[dir][i];

        for (int i = 0 ; i < 2 ; i++) if (head[i] < 0 || n <= head[i])
        {
            cout << tick;
            return 0;
        }

        if (snake[head[0]][head[1]])
        {
            cout << tick;
            return 0;
        }

        q_snake.push({head[0], head[1]});
        snake[head[0]][head[1]] = true;
        if (apple[head[0]][head[1]]) apple[head[0]][head[1]] = false;
        else 
        {
            snake[q_snake.front().first][q_snake.front().second] = false;
            q_snake.pop();
        }
        if (tick == q_command.front().first)
        {
            if (q_command.front().second == 'L'-'A') dir--;
            else dir++;
            
            if (dir > 3) dir = 0;
            if (dir < 0) dir = 3;
            q_command.pop();
        }
    }
}  