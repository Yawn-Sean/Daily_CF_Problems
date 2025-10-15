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

    int n, mod = 1e9 + 7;
    cin >> n;

    int dp0 = 0, dp1 = 0;
    for (int i = 0; i < n; i ++) {
        if (i & 1) dp1 = (dp0 + dp1 + 1) % mod;
        else dp0 = (dp0 + dp1 + 1) % mod;
    }

    cout << (dp0 + dp1) % mod;

    return 0;
}