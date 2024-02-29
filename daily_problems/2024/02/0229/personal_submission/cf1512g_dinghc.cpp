#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int N = 10000001;
int lpf[N], ans[N];

void sieve_lpf() {
    lpf[0] = lpf[1] = 1;

    for (int i = 2; i < N; i++) {
        if (lpf[i] == 0) {
            if (N / i > i) {
                for (int j = i * i; j < N; j += i) {
                    if (lpf[j] == 0) lpf[j] = i;
                }
            }
            lpf[i] = i;
        }
    }
}

int d(int n) {
    int res = 1;
    while (lpf[n] > 1) {
        int p = lpf[n];
        int s = 0;
        while (n % p == 0) {
            n /= p;
            s = s * p + p;
        }
        res *= s + 1;
    }
    return res;
}

int main() {
    // prepare least prime factors
    sieve_lpf();

    memset(ans, -1, sizeof ans);
    // prepare d(n) for all n
    for (int k = 1; k < N; k++) {
        int sigma = d(k);
        if (sigma < N && ans[sigma] == -1) ans[sigma] = k;
    }

    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        cout << ans[c] << "\n";
    }
    return 0;
}
