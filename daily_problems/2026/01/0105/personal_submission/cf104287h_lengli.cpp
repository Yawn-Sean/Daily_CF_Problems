#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXD = 100000;

inline long long norm(long long x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> pow2(MAXD + 1);
    pow2[0] = 1;
    for (int i = 1; i <= MAXD; i++) {
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    }

    long long inv2 = (MOD + 1) / 2;

    int T;
    cin >> T;

    while (T--) {
        int d;
        cin >> d;

        long long total = pow2[d] - 1;
        total = norm(total);

        long long cur = total;
        long long edges = 1;
        long long ans = 0;

        while (--d) {
            cur = norm(cur - 1);
            cur = cur * inv2 % MOD;

            edges = (edges << 1) % MOD;

            long long other = norm(total - cur);
            ans = (ans + cur * other % MOD * edges) % MOD;
        }

        cout << (ans << 1) % MOD << '\n';
    }

    return 0;
}
