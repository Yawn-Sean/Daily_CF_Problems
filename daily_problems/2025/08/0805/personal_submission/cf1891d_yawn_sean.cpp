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

    int t, mod = 1e9 + 7;
    cin >> t;

    while (t --) {
        long long l, r;
        cin >> l >> r;

        r ++;
        long long xl = 2, xr = 4;
        int ans = 0;

        for (int fx = 2; fx < 60; fx ++) {
            xl <<= 1, xr <<= 1;

            long long vl = max(l, xl), vr = min(r, xr);
            if (vl >= vr) continue;

            long long nl = 1, nr = fx;

            for (int v = 1; v < 60; v ++) {
                nl = min(nl, vr / fx + 5) * fx;
                nr = min(nr, vr / fx + 5) * fx;

                if (nl >= vr) break;
                long long cnt = max(0ll, min(vr, nr) - max(vl, nl));
                ans += cnt % mod * v % mod;

                if (ans >= mod) ans -= mod;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}