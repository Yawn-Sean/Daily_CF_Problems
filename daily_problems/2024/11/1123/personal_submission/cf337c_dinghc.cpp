#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int mod = 1'000'000'009;

int fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int x = max(0, m - n / k * (k - 1) - n % k);
    // (2^ (x + 1) - 2) * k + m - k * x
    int ans = (1LL* (fast_pow(2, x + 1) + mod - 2) % mod * k % mod + m + mod - 1LL * k * x % mod) % mod;
    cout << ans << "\n";
    return 0;
}

