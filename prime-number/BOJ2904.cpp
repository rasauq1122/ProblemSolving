// 2020.05.11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool not_prime[500001] = {1, 1, 0,};
int arr[100] = {};
vector < vector <int> > cnt;

int main() {

    vector <int> prime, prime_real;
    for (int i = 2 ; i < 500001 ; i++) {
        if (!not_prime[i]) {
            for (int j = i + i ; j < 500001 ; j += i) not_prime[j] = true;
            prime.push_back(0);
            prime_real.push_back(i);
        }
    }
    prime.push_back(0);

    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        cnt.push_back(prime);
    }

    int len = prime_real.size();
    for (int i = 0 ; i < n ; i++)  {
        for (int j = 0 ; j <= len ; j++) {
            if (j == len || prime_real[j] > arr[i]) {
                prime[len] = max(prime[len],j);
                break;
            }
            while (arr[i]%prime_real[j] == 0) {
                arr[i] /= prime_real[j];
                cnt[i][j]++;
                prime[j]++;
            }
        }
    }

    int ans = 1, count = 0;
    for (int i = 0 ; i < prime[len] ; i++) {
        int len2 = prime[i]/n;
        for (int j = 0 ; j < len2 ; j++) ans *= prime_real[i];         
        if (len2 > 0) for (int j = 0 ; j < n ; j++) if (cnt[j][i] < len2) count += len2-cnt[j][i];
    }

    cout << ans << ' ' << count;
}