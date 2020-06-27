// 2019.12.31

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int n, m, k, st, en, TM = 1;
vector <ll> v;

void big()
{
    while (n > TM) TM *= 2;
}

ll cal(int i)
{
    return v[2*i] + v[2*i+1];
}

void seg()
{
    for (int i = TM-1 ; i > 0 ; i--) v[i] = cal(i);
}

void update(int i, ll p)
{
    ll pre = cal(i/2);
    v[i] = p;
    ll now = cal(i/2);

    if (i == 1) return;

    if (pre != now) update(i/2,now);
}

ll get(int i, int le, int ri)
{
    if (ri < st || en < le) return 0;
    if (st <= le && ri <= en) return v[i];
    return get(i*2, le, (le+ri)/2) + get(i*2+1, (le+ri)/2 + 1, ri);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> k;

    big();
    v.resize(2*TM);

    for (int i = 0 ; i < n ; i++) cin >> v[TM+i];
    seg();

    for (int i = 0, a, b, c ; i < m + k ; i++)
    {
        cin >> a >> b >> c;
        if (a == 1) update(b-1+TM,1LL*c);
        else
        {
            st = b;
            en = c;
            cout << get(1,1,TM) << '\n';
        }
    }
}
