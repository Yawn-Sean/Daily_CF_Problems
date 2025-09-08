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

    int mod = 1e9 + 7, N = 1e5 + 5;
    
    vector<int> f(N, 1), g(N);

    for (int i = 1; i < N; i ++)
        f[i] = 1ll * i * f[i - 1] % mod;
    
    g[N - 1] = quickPow(f[N - 1], mod - 2, mod);
    for (int i = N - 1; i > 0; i --)
        g[i - 1] = 1ll * i * g[i] % mod;
    
    int t;
    cin >> t;

    auto comb = [&] (int x, int y) -> int {
        return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
    };

    while (t --) {
        int n, m;
        cin >> n >> m;

        if (n == 1 && m == 1) cout << 1 << '\n';
        else if (2 * n > m) cout << 0 << '\n';
        else cout << 1ll * m * comb(m - n - 1, n - 1) % mod * f[n - 1] % mod << '\n';
    }

    return 0;
}