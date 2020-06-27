// 2019.12.30

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector < vector < int > > tree(300001);
vector < pair < int, int > > list;
int cnt;

void inorder(int x, int i)
{
    if (tree[x].size() <= i) return;
    inorder(x+1,2*i);
    list.push_back({tree[x][i],++cnt});
    inorder(x+1,2*i+1);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    tree[0].push_back(1);
    for (int i = 2, x ; i <= n ; i++)
    {
        cin >> x;
        if (tree[x-1].size()*2 <= tree[x].size())
        {

            cout << "-1";
            return 0;
        }
        tree[x].push_back(i);
    }

    inorder(0,0);
    sort(list.begin(),list.end());
    
    for (int i = 0 ; i < n ; i++) cout << list[i].second << ' ';
}