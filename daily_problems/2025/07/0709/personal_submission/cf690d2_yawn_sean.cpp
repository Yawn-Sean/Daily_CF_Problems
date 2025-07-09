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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c, mod = 1e6 + 3;
    cin >> n >> c;

    int v1 = 1, v2 = 1;
    for (int i = 1; i <= c; i ++) {
        v1 = 1ll * v1 * (n + c + 1 - i) % mod;
        v2 = 1ll * v2 * i % mod;
    }

    int ans = 1ll * v1 * quickPow(v2, mod - 2, mod) % mod;
    cout << (ans + mod - 1) % mod;

    return 0;
}