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

    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    if (t0 == t1 && t0 == t2) cout << x1 << ' ' << x2;
    else if (t0 == t1) cout << x1 << ' ' << 0;
    else if (t0 == t2) cout << 0 << ' ' << x2;
    else {
        int ans1 = 0, ans2 = x2;

        for (int i = 1; i <= x1; i ++) {
            long long t = (1ll * (t0 - t1) * i + t2 - t0 - 1) / (t2 - t0);
            if (t > x2) continue;
            if (1ll * t * ans1 <= 1ll * ans2 * i) ans1 = i, ans2 = t;
        }

        cout << ans1 << ' ' << ans2;
    }

    return 0;
}