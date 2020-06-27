// 2019.12.23

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int alpha(string s)
{
    switch (s.size())
    {
        case 1:
        return s[0] - 'A';
        
        case 2:
        return (s[0] - 'A' + 1)*26 + s[1] - 'A';

        case 3:
        return (s[0] - 'A' + 1)*26*26 + (s[1] - 'A' + 1)*26 + s[2] - 'A';
    }
    return -1;
}

pair <int, int> mkpr(string s)
{
    int len = s.size();
    for (int i = 0 ; i < len ; i++) if ('0' <= s[i] && s[i] <= '9') return {stoi(s.substr(i))-1,alpha(s.substr(0,i))};
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> c >> r;
        vector < vector < int > > dat(r, vector <int> (c,0)), in(r, vector <int> (c,0));
        vector < vector < vector < pair < int, int > > > > g(r, vector < vector < pair <int, int > > > (c));
        for (int i = 0 ; i < r ; i++)
        {
            for (int j = 0 ; j < c ; j++)
            {
                string s;
                cin >> s;
                if (s[0] == '=')
                {
                    s = s.substr(1) + "+";
                    int len = s.size();
                    for (int k = 0, cnt = 0 ; cnt < len ; cnt++ )
                    {
                        if (s[k] == '+')
                        {
                            pair <int, int> now = mkpr(s.substr(0,k));
                            s = s.substr(k+1);
                            k = 0;
                            g[now.first][now.second].push_back({i,j});
                            in[i][j]++;
                        }
                        else k++;
                    }
                }
                else dat[i][j] = stoi(s);
            }
        }

        queue < pair < int, int > > q;
        for (int i = 0; i < r ; i++) for (int j = 0 ; j < c ; j++) if (!in[i][j]) q.push({i,j});
        while (!q.empty())
        {
            pair <int, int> now = q.front();
            q.pop();
            int len = g[now.first][now.second].size();
            for (int i = 0 ; i < len ; i++)
            {
                pair <int, int> john = g[now.first][now.second][i];
                dat[john.first][john.second] += dat[now.first][now.second];
                // printf(">> %d %d <- %d %d : %d <- %d\n",john.first, john.second, now.first, now.second, dat[john.first][john.second], dat[now.first][now.second]);
                if (!--in[john.first][john.second]) q.push(john);
            }
        }

        for (int i = 0 ; i < r ; i++)
        {
            for (int j = 0 ; j < c ; j++) cout << dat[i][j] << ' ';
            cout << "\n";
        } 
    }
}