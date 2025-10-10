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

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int mod = 1e9 + 7;

    vector<int> f(n + 1, 1), g(n + 1);

    for (int i = 1; i <= n; i ++)
        f[i] = 1ll * i * f[i - 1] % mod;
    
    g[n] = quickPow(f[n], mod - 2, mod);

    for (int i = n; i >= 1; i --)
        g[i - 1] = 1ll * i * g[i] % mod;
    
    auto comb = [&] (int x, int y) -> int {
        if (x < y || x < 0 || y < 0) return 0;
        return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
    };

    int ans = 0;
    int pw2 = 1, rev2 = (mod + 1) / 2;
    int weight_left = 0, weight_right;

    for (int i = l - 1; i <= r - 1; i ++)
        weight_left += comb(n - 1, i), weight_left %= mod;
    
    weight_right = weight_left;
    ans += 1ll * (weight_left + weight_right) * nums[0] % mod;

    for (int i = 1; i < n; i ++) {
        pw2 = pw2 * 2 % mod;

        weight_left = (0ll + weight_left + comb(n - i - 1, l - i - 1) - comb(n - i - 1, r - i)) * rev2 % mod;
        weight_right = (0ll + weight_right - comb(n - i - 1, l - 2) + comb(n - i - 1, r - 1)) * rev2 % mod;

        ans += 1ll * (weight_left + weight_right) * nums[i] % mod * pw2 % mod;
        ans %= mod;
    }

    cout << (ans + mod) % mod;

    return 0;
}