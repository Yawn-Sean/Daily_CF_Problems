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

    int n, m;
    cin >> n >> m;

    int g = 0;
    while (n --) {
        int x;
        cin >> x;
        g = gcd(g, x - 1);
    }

    g /= g & -g;

    long long ans = 0;

    auto solve = [&] (int x) -> long long {
        long long res = 0;
        while (x <= m) {
            res += m - x;
            x <<= 1;
        }
        return res;
    };

    for (int i = 1; i <= g / i; i ++) {
        if (g % i == 0) {
            ans += solve(i);
            if (i != g / i) ans += solve(g / i);
        }
    }

    cout << ans;

    return 0;
}