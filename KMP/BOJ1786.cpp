// 2020.07.01

#include <iostream>
#include <string.h>
using namespace std;

char t[1000002], p[1000002];
int k[1000002], cnt, idx[1000002];

int main() {
    fgets(t, 1000002, stdin);
    fgets(p, 1000002, stdin);
    t[strlen(t)-1] = 0;
    p[strlen(p)-1] = 0;

    int len1 = strlen(t), len2 = strlen(p);
    for (int i = 1, j = 0 ; i < len2 ; i++) {
        while (j > 0 && p[i] != p[j]) j = k[j-1];
        if (p[i] == p[j]) k[i] = ++j;
    }

    for (int i = 0, j = 0 ; i < len1 ; i++) {
        while (j > 0 && t[i] != p[j]) j = k[j-1];
        if (t[i] == p[j]) {
            if (++j == len2) {
                idx[cnt++] = i-len2+2;
                j = k[j-1];
            }
        }
    }
    
    cout << cnt << '\n';
    for (int i = 0 ; i < cnt ; i++) cout << idx[i] << ' ';
}