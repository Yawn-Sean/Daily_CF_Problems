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

    int n, k;
    cin >> n >> k;

    vector<int> v1(n), v2(n);
    for (auto &x: v1) cin >> x;
    for (auto &x: v2) cin >> x;

    int mod = 998244353;

    int tot1 = 0, tot2 = 0, dot = 0;

    for (auto &x: v1) tot1 += x, tot1 %= mod;
    for (auto &x: v2) tot2 += x, tot2 %= mod;

    for (int i = 0; i < n; i ++) {
        dot += 1ll * v1[i] * v2[i] % mod;
        dot %= mod;
    }

    int ans = 1ll * tot1 * tot2 % mod * quickPow(dot, k - 1, mod) % mod;

    cout << (ans + mod) % mod;

    return 0;
}