#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int M = 100000;

long long inv[M + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inv[1] = 1;
    for (int i = 2; i <= M; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        for (int k = 1; k <= n; ++k) {
            ans = (ans + (n + 1) % MOD * inv[k + 1]) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}
