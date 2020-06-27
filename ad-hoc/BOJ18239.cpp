// 2019.12.30

#include <iostream>
using namespace std;

#define SW(a,b) printf("reverse %d %d\n",a,b)
#define PP SW(1,n);SW(1,n)

int main()
{
    int n, k;
    cin >> n >> k;

    if (n == 2)
    {
        printf("YES\n");
        SW(1,n);
        PP;
        PP;
    }
    else if (n == 3) printf("NO");
    else if (n == k+1)
    {
        printf("YES\n");
        SW(2,n-1);
        SW(2,n);
        SW(1,2);
        PP;
    }
    else if (k == 1)
    {
        printf("YES\n");
        SW(2,n-1);
        SW(1,n-1);
        SW(n-1,n);
        PP;
    }
    else
    {
        printf("YES\n");
        SW(1,k);
        SW(k+1,n);
        SW(1,n);
        PP;
    }
    
}