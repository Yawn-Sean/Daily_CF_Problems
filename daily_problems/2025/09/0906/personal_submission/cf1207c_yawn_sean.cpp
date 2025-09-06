#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long inf = 1e16;

    int t;
    cin >> t;

    while (t --) {
        int n, a, b;
        string s;

        cin >> n >> a >> b >> s;

        long long dp0 = b, dp1 = inf;
        for (auto &c: s) {
            if (c == '1')
                dp0 = inf, dp1 = dp1 + a + 2 * b;
            else {
                long long ndp0 = min(dp0 + a + b, dp1 + 2 * a + b);
                long long ndp1 = min(dp1 + a + 2 * b, dp0 + 2 * a + 2 * b);
                dp0 = ndp0, dp1 = ndp1;
            }
        }

        cout << dp0 << '\n';
    }

    return 0;
}