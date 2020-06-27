// 2019.12.26

#include <iostream>
using namespace std;

int main()
{
    long long x[3], y[3], dx[2], dy[2], res;
    for (int i = 0 ; i < 3 ; i++) cin >> x[i] >> y[i];
    for (int i = 0 ; i < 2 ; i++) dx[i] = x[i+1] - x[i];
    for (int i = 0 ; i < 2 ; i++) dy[i] = y[i+1] - y[i];

    res = dx[0]*dy[1] - dx[1]*dy[0];
    if (res > 0) printf("1");
    else if (res < 0) printf("-1");
    else printf("0");
}